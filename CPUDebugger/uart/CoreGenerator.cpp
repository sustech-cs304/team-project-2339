//
// Created by David Li on 4/12/23.
//

#include "CoreGenerator.h"

const char *inputFormat    = "input      [%d:0] signal_%d,\n";
const char *inputIndent    = "\tinput      [%d:0] signal_%d,\n";
const char *signalFormat   = "signal_%d,\n\t                                                  ";
const char *moduleFormat   = "\t\t.signal_%-16d(%s),\n";
const char *moduleSection  = "debug_unit(\n"
                             "        .clk                    (clk_cpu),\n"
                             "        .rst_n                  (rst_n),\n"
                             "\n"
                             "        .uart_rx                (uart_rx),\n"
                             "        .uart_tx                (uart_tx),\n"
                             "\n"
                             "        .pc                     (instruction_mem_pc),\n"
                             "%s\n"
                             "        .uart_addr              (debug_unit_write_address),\n"
                             "        .uart_data              (debug_unit_write_data),\n"
                             "        .uart_write_enable      (debug_unit_write_enable),\n"
                             "\n"
                             "        .rx_light               (rx_light),\n"
                             "\n"
                             "        .debug_pause            (debug_unit_debug_pause),\n"
                             "        .uart_complete          (debug_unit_uart_complete)\n"
                             "    );";
const char *moduleComplete = "\n"
                             "    //-------------------------------------debug----------------------------------------//\n"
                             "    debug_unit debug_unit(\n"
                             "        .clk                    (clk_cpu),\n"
                             "        .rst_n                  (rst_n),\n"
                             "\n"
                             "        .uart_rx                (uart_rx),\n"
                             "        .uart_tx                (uart_tx),\n"
                             "\n"
                             "        .pc                     (instruction_mem_pc),\n"
                             "%s\n"
                             "        .uart_addr              (debug_unit_write_address),\n"
                             "        .uart_data              (debug_unit_write_data),\n"
                             "        .uart_write_enable      (debug_unit_write_enable),\n"
                             "\n"
                             "        .rx_light               (rx_light),\n"
                             "\n"
                             "        .debug_pause            (debug_unit_debug_pause),\n"
                             "        .uart_complete          (debug_unit_uart_complete)\n"
                             "    );\n"
                             "endmodule";

const char *coreName = "debug_unit.v";

static int coreWidth = 32; // default to 32

int setISAWidth(int ISAWidth) {
    return (coreWidth = ISAWidth);
}

int sumWidth(const QList<CPUSignal> &selectedSignals) {
    return std::accumulate(selectedSignals.cbegin(), selectedSignals.cend(),
                           coreWidth /* PC_WIDTH */ + OPCODE_WIDTH,
                           [](int acc, const CPUSignal &signal) {
                               return acc + signal.rawWidth;
                           });
}

QString insertInput(const QList<CPUSignal> &selectedSignals) {
    QString inputLines;

    for (int i = 0; i < selectedSignals.size(); ++i)
        inputLines.append(
                QString::asprintf(i == 0
                                  ? inputFormat
                                  : inputIndent,
                                  selectedSignals[i].rawWidth - 1,
                                  i)
        );

    return inputLines;
}

typedef QString (*insertFunc)(const QList<CPUSignal> &selectedSignals);

QString insertWidth(const QList<CPUSignal> &selectedSignals) {
    return QString::number(sumWidth(selectedSignals));
}

QString insertBytes(const QList<CPUSignal> &selectedSignals) {
    return QString::number(static_cast<int>(ceil(sqrt(
            (sumWidth(selectedSignals)) / 8
    ))));
}

QString insertSignals(const QList<CPUSignal> &selectedSignals) {
    QString signalLines;

    for (int i = 0; i < selectedSignals.size(); ++i)
        signalLines.append(QString::asprintf(signalFormat, i));

    return signalLines;
}

typedef struct {
    QString    key;
    insertFunc func;
}               entry;

static QVector<entry> insert{
        {"[INPUT]",   insertInput},
        {"[WIDTH]",   insertWidth},
        {"[BYTES]",   insertBytes},
        {"[SIGNALS]", insertSignals}
};

QString insertModule(const QList<CPUSignal> &selectedSignals) {
    QString moduleLines;

    for (int i = 0; i < selectedSignals.size(); ++i)
        moduleLines.append(
                QString::asprintf(moduleFormat,
                                  i,
                                  qPrintable(selectedSignals[i].name))
        );

    return moduleLines;
}

/**
 * Generates
 */
bool generateCore(QString topPath,
                  QString outputDirPath,
                  const QList<CPUSignal> &selectedSignals) {
    QFile topFile(topPath);
    QDir outputDir(outputDirPath);
    if (!topFile.open(QIODevice::ReadWrite)) {
        qDebug("Top file cannot open");
        return false;
    }
    // the template to start with
    QFile coreTemplate(QDir::currentPath().append("/template.v"));
    if (!coreTemplate.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug("Template not found\n");
        return false;
    }
    // create debug unit file
    QFile outputFile(outputDir.filePath(coreName));
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug("Not able to create uart core file\n");
        return false;
    }
    // generate the input streams
    QTextStream              in(&coreTemplate);
    QTextStream              out(&outputFile);
    // replace the tokens in the template
    QVector<entry>::iterator iterator = insert.begin();
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.contains(iterator->key, Qt::CaseInsensitive) &&
            iterator != insert.end()) {
            line.replace(iterator->key, iterator->func(selectedSignals));
            ++iterator;
        }
        out << line << "\n";

//        qDebug() << line;
    }
    coreTemplate.close();
    outputFile.close();
    // read all text from top module
    QString            topText   = topFile.readAll();
    // replace any previous instantiations of debug unit or insert before last line
    QRegularExpression coreRegex = QRegularExpression("(debug_unit(?=\\()(.|\\n)*(?=;);)");
    if (topText.contains(coreRegex))
        topText.replace(coreRegex,
                        QString::asprintf(moduleSection, qPrintable(insertModule(selectedSignals))));
    else
        topText.replace("endmodule",
                        QString::asprintf(moduleComplete, qPrintable(insertModule(selectedSignals))));
    // write back to top module
    topFile.seek(0);
    topFile.write(topText.toUtf8());
    return true;
}

//int main() {
//    QList<CPUSignal> list{
//            CPUSignal{"instruction_1", 32, 32, QBitArray(), false},
//            CPUSignal{"another_instruction", 32, 32, QBitArray(), false}
//    };
////    qDebug("%s", insertInput(list).toLocal8Bit().constData());
////    qDebug("%s", insertBytes(list).toLocal8Bit().constData());
////    qDebug("%s", insertWidth(list).toLocal8Bit().constData());
////    qDebug("%s", insertSignals(list).toLocal8Bit().constData());
//
//    QFile top(QDir::currentPath().append("/top.v"));
//    QDir  output(QDir::currentPath());
//
//    top.open(QIODevice::ReadWrite | QIODevice::Text);
//
//    generateCore(top, output, list);
//
//    top.close();
//    return 0;
//}
