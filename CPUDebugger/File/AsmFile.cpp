#include <QDir>
#include "AsmFile.h"

AsmFile::AsmFile(QFile &file) : asmFile(&file) {
    loadAsmFile(file);
}

AsmFile::AsmFile() = default;

AsmFile::~AsmFile() = default;

QString AsmFile::loadAsmFile(QFile &file) {
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug("Asm file not found\n");
    }
    asmFile                  = &file;
    // generate the input streams
    QTextStream in(&file);
    QString     fileContents = in.readAll();
    // close the file
    file.close();
    // get binary and asm -> bin map
    parseAsm(fileContents);
    return fileContents;
}

QByteArray AsmFile::updateAsmFile(QString &asmString) {
    if (!asmFile->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug("Not able to find original Asm file\n");
    }
    // generate output streams
    QTextStream out(asmFile);
    out << asmString;
    // close the file
    asmFile->close();
    // get binary and asm -> bin map
    parseAsm(asmString);
    return bin;
}

QByteArray AsmFile::getBin() {
    return bin;
}

unsigned int AsmFile::getPC(int asmLine) {
    return asmToPCMap.value(asmLine);
}

int AsmFile::getAsmLine(unsigned int PC) {
    return PCToAsmMap.value(PC);
}

void AsmFile::parseAsm(QString asmString) {
    programCounter = 0;
    bin.clear();
    labelMap.clear();

    preprocess(asmString);

    // cache the .data section
    QByteArray data = bin;
    bin.clear();

    QStringList instructions = asmString.split(QRegularExpression("(?=\n)|(?<=\n)|[ \t,:;]"),
                                               Qt::SkipEmptyParts);
    QStringList::const_iterator instruction  = instructions.constBegin();

    qDebug() << instructions.toList();

    asmLine = 0;
    int opType;

    do {
        opType = getOpType(*instruction);

        if (opType == N_Type) {
            asmLine += (*instruction == "\n");
            continue;
        } else {
            PCToAsmMap.insert(programCounter, asmLine);
            asmToPCMap.insert(asmLine, programCounter);

            switch (opType) {
                case O_Type:
                    O_TypeProcess(instruction);
                    break;
                case R_Type:
                    R_TypeProcess(instruction);
                    break;
                case I_Type:
                    I_TypeProcess(instruction);
                    break;
                case J_Type:
                    J_TypeProcess(instruction);
                    break;
                case P_Type:
                    P_TypeProcess(instruction);
                default:
                    break;
            }

            programCounter += 4;
        }
    } while ((++instruction) != instructions.constEnd());

    // pad the .text section with 0s for a total of 64KB (14-bit address width)
    bin = bin.append(TEXT_MEM_SIZE - bin.length(), '\x00').append(data);

    qDebug() << bin.toHex();
}

void printByte(char byte) {
    QString  result;
    for (int i = 7; i >= 0; --i) {
        result.append(QString::number((byte >> i) & 1));
    }
    qDebug("0b%s", qPrintable(result));
}

void AsmFile::preprocess(QString &asmString) {
    // remove comments
    asmString.replace(QRegularExpression("#[^\n]*"), "");

    asmLine = 0;
    bool dataSection = true;

    QStringList                 words    = asmString.split(QRegularExpression("[ ,;\n\t]"),
                                                           Qt::SkipEmptyParts);
    QStringList::const_iterator wordIter = words.constBegin();

    do {
        if (*wordIter == ".data") {
            // data section start
            dataSection = true;
            asmLine     = 0;
        } else if (*wordIter == ".text") {
            // text section start
            dataSection = false;
            asmLine     = 0;
            // pad the data section with 0s
            bin.append(DATA_MEM_SIZE - bin.length(), '\x00');
        } else if (dataSection) {
            // insert into data section
            if (wordIter->endsWith(":")) {
                labelMap.insert(wordIter->chopped(1), asmLine * 4);
                wordIter++;
                if (*wordIter == ".asciiz") {
                    ++wordIter;
                    // append all ascii bytes with byte array
                    bin.append(asciiData(*wordIter, &asmLine));
                } else if (*wordIter == ".word") {
                    while ((++wordIter) != words.constEnd()) {
                        if (wordIter->left(1) <= "9" && wordIter->left(1) >= "0") {
                            // append value of the current word
                            binAppend(zeroExtend(*wordIter, WORD_LEN));
                            ++asmLine;
                        } else {
                            // rollback as the iterator will be incremented later
                            --wordIter;
                            break;
                        }
                    }
                }
            }
        } else {
            // get labels in text section
            if (isSingleLine(wordIter))
                asmLine++;
            else if (isDoubleLine(wordIter))
                asmLine += 2;
            else if (wordIter->right(1) == ":")
                labelMap.insert(wordIter->chopped(1), asmLine * 4);
        }
//        qDebug() << *wordIter << dataSection << asmLine;
    } while (++wordIter != words.constEnd());
}

QByteArray AsmFile::asciiData(QString data, int *wordCnt) {
    data                              = data.mid(1, data.length() - 2); // remove surrounding ""

    QByteArray              ascii;
    QString::const_iterator character = data.constBegin();

    while (character != data.constEnd()) {
        if (*character == '\\') { // take care of "\n" and "\t"
            ++character;
            switch (character->toLatin1()) {
                case 'n':
                    ascii.append('\n');
                    break;
                case 't':
                    ascii.append('\t');
                    break;
                default :
                    break;
            }
        } else { // byte align characters
            ascii.append(character->toLatin1());
        }
        ++character;
    }

    // word align with padding '\0'
    if (ascii.length() % 4 == 0)
        ascii.append(4, '\x00');
    else
        ascii.append(4 - (ascii.length() % 4), '\x00');

    (*wordCnt) += ascii.length() / 4;

    return ascii;
}

void AsmFile::binAppend(uint32_t word) {
    bin.append(reinterpret_cast<const char *>(&word), 4);
}

uint32_t AsmFile::zeroExtend(const QString &word, int length) {
    static bool     valid;
    static uint64_t mask = ((uint64_t) 1 << length) - 1;

    return word.toUInt(&valid, 2 < word.length()
                               && (word.left(2) == "0x" || word.left(2) == "0X")
                               ? 16 : 10) & mask;
}

uint32_t AsmFile::signExtend(const QString &word, int length) {
    static bool     valid;
    static uint64_t mask = (1 << length) - 1;

    return word.toInt(&valid, 2 < word.length()
                              && (word.left(2) == "0x" || word.left(2) == "0X")
                              ? 16 : 10) & mask;
}

int AsmFile::getOpType(const QString &op) {
    if (op == "eret" || op == "syscall" || op == "break" || op == "nop")
        return O_Type;
    else if (op == "add" || op == "addu" || op == "sub" || op == "subu" ||
             op == "and" || op == "or" || op == "xor" || op == "nor" ||
             op == "slt" || op == "sltu" || op == "sll" || op == "srl" ||
             op == "sra" || op == "sllv" || op == "srlv" || op == "srav" ||
             op == "jr" || op == "div" || op == "divu" || op == "mult" ||
             op == "multu" || op == "jalr" || op == "mtlo" || op == "mthi" ||
             op == "mfhi" || op == "mflo")
        return R_Type;
    else if (op == "addi" || op == "addiu" || op == "andi" || op == "ori" ||
             op == "xori" || op == "lui" || op == "lw" || op == "sw" ||
             op == "beq" || op == "bne" || op == "slti" || op == "sltiu" ||
             op == "lb" || op == "lbu" || op == "lh" || op == "lhu" ||
             op == "sb" || op == "sh" || op == "blez" || op == "bltz" ||
             op == "bgez" || op == "bgtz")
        return I_Type;
    else if (op == "j" || op == "jal")
        return J_Type;
    else if (op == "blt" || op == "ble" || op == "bgt" || op == "bge" ||
             op == "la" || op == "move" || op == "li")
        return P_Type;
    else
        return N_Type;
}

void AsmFile::O_TypeProcess(QStringList::const_iterator &instruction) {
    static uint32_t syscall = 0b00000000000000000000000000001100,
            eret    = 0b01000010000000000000000000011000;

    if (*instruction == "nop")
        bin.append(4, '\x00');
    else if (*instruction == "eret")
        bin.append(reinterpret_cast<char *>(&eret), 4);
    else if (*instruction == "syscall")
        bin.append(reinterpret_cast<char *>(&syscall), 4);
    else if (*instruction == "break") {
        uint32_t addr = zeroExtend(getNext(instruction), ADDR_LEN);
        addr = (addr << FUNC_LEN) | 0b001101;
        bin.append(reinterpret_cast<char *>(&addr), 4);
    }

    qDebug() << "O_Type: " << bin.right(4).toHex();
}

void AsmFile::R_TypeProcess(QStringList::const_iterator &instruction) {
    uint32_t opCode = 0b000000, dReg, sReg, tReg, shAmt, func = 0b000000, word;
    QString  op     = *instruction;

    // format: op rd rs rt
    if (op == "add" || op == "addu" || op == "sub" || op == "subu" ||
        op == "and" || op == "or" || op == "xor" || op == "nor" ||
        op == "slt" || op == "sltu") {

        dReg = getRegCode(getNext(instruction));
        sReg = getRegCode(getNext(instruction));
        tReg = getRegCode(getNext(instruction));

        shAmt = 0b00000;

        if (op == "add") func = 0b100000;
        else if (op == "addu") func = 0b100001;
        else if (op == "sub") func = 0b100010;
        else if (op == "subu") func = 0b100011;
        else if (op == "and") func = 0b100100;
        else if (op == "or") func = 0b100101;
        else if (op == "xor") func = 0b100110;
        else if (op == "nor") func = 0b100111;
        else if (op == "slt") func = 0b101010;
        else if (op == "sltu") func = 0b101011;
    }
        // format: op rd rt rs
    else if (op == "sllv" || op == "srlv" || op == "srav") {
        dReg = getRegCode(getNext(instruction));
        tReg = getRegCode(getNext(instruction));
        sReg = getRegCode(getNext(instruction));

        shAmt = 0b00000;

        if (op == "sllv") func = 0b000100;
        else if (op == "srlv") func = 0b000110;
        else if (op == "srav") func = 0b000111;
    }
        // format: op rs rt
    else if (op == "mult" || op == "multu" || op == "div" || op == "divu") {
        sReg = getRegCode(getNext(instruction));
        tReg = getRegCode(getNext(instruction));
        dReg = 0b00000;

        shAmt = 0b00000;

        if (op == "mult") func = 0b011000;
        else if (op == "multu") func = 0b011001;
        else if (op == "div") func = 0b011010;
        else if (op == "divu") func = 0b011011;
    }
        // format: op rs rd
    else if (op == "jalr") {
        sReg = getRegCode(getNext(instruction));
        dReg = getRegCode(getNext(instruction));
        tReg = 0b00000;

        shAmt = 0b00000;

        func = 0b001001;
    }
        // format: op rd rt shamt
    else if (op == "sll" || op == "srl" || op == "sra") {
        sReg = 0b00000;
        dReg = getRegCode(getNext(instruction));
        tReg = getRegCode(getNext(instruction));

        shAmt = zeroExtend(getNext(instruction), SHAMT_LEN);

        if (op == "sll") func = 0b000000;
        else if (op == "sra") func = 0b000011;
        else if (op == "srl") func = 0b000010;
    }
        // format: op rs
    else if (op == "jr" || op == "mthi" || op == "mtlo") {
        sReg = getRegCode(getNext(instruction));
        tReg = 0b00000;
        dReg = 0b00000;

        shAmt = 0b00000;

        if (op == "mthi") func = 0b010001;
        else if (op == "mtlo") func = 0b010011;
        else if (op == "jr") func = 0b001000;
    }
        // format: op rd
    else if (op == "mfhi" || op == "mflo") {
        dReg = getRegCode(getNext(instruction));
        sReg = 0b00000;
        tReg = 0b00000;

        shAmt = 0b00000;

        if (op == "mfhi") func = 0b010000;
        else if (op == "mflo") func = 0b010010;
    } else return;

    word = opCode;
    word = (word << REG_LEN) | sReg;
    word = (word << REG_LEN) | tReg;
    word = (word << REG_LEN) | dReg;
    word = (word << SHAMT_LEN) | shAmt;
    word = (word << FUNC_LEN) | func;

    binAppend(word);

    qDebug() << "R_Type: " << bin.right(4).toHex();
}

void AsmFile::I_TypeProcess(QStringList::const_iterator &instruction) {
    uint32_t opCode = 0b000000, sReg, tReg = 0b00000, imme, addr, word;
    QString  op     = *instruction;

    // format: op rs rt imme
    if (op == "beq" || op == "bne") {
        sReg = getRegCode(getNext(instruction));
        tReg = getRegCode(getNext(instruction));

        addr = labelMap.value(getNext(instruction));
        addr = (addr - (programCounter + 4)) / 4;

        imme = signExtend(QString::number(addr), 16);

        if (op == "beq") opCode = 0b000100;
        else if (op == "bne") opCode = 0b000101;
    }
        // format: op rt ts imme
    else if (op == "addi" || op == "addiu" || op == "andi" || op == "ori" ||
             op == "xori" || op == "slti" || op == "slti" || op == "sltiu") {
        tReg = getRegCode(getNext(instruction));
        sReg = getRegCode(getNext(instruction));

        if (op == "addi" || op == "slti" || op == "sltiu" || op == "addiu")
            imme = signExtend(getNext(instruction), IMME_LEN);
        else
            imme = zeroExtend(getNext(instruction), IMME_LEN);

        if (op == "addi") opCode = 0b001000;
        else if (op == "addiu") opCode = 0b001001;
        else if (op == "andi") opCode = 0b001100;
        else if (op == "ori") opCode = 0b001101;
        else if (op == "xori") opCode = 0b001110;
        else if (op == "slti") opCode = 0b001010;
        else if (op == "sltiu") opCode = 0b001011;
    }
        // format: op rt imme(rs)
    else if (op == "lw" || op == "sw" || op == "lb" || op == "lbu" || op == "lh" ||
             op == "lhu" || op == "sb" || op == "sb" || op == "sh") {
        tReg = getRegCode(getNext(instruction));

        QStringList immeNrs = (getNext(instruction)).split(QRegularExpression("[()]"),
                                                           Qt::SkipEmptyParts);

        if (immeNrs.length() == 1) {
            // imme left out
            sReg = getRegCode(immeNrs.at(0));
            imme = 0;
        } else {
            sReg = getRegCode(immeNrs.at(1));
            imme = signExtend(immeNrs.at(0), 16);
        }

        if (op == "lw") opCode = 0b100011;
        else if (op == "sw") opCode = 0b101011;
        else if (op == "lb") opCode = 0b100000;
        else if (op == "lbu") opCode = 0b100100;
        else if (op == "lh") opCode = 0b100001;
        else if (op == "lhu") opCode = 0b100101;
        else if (op == "sb") opCode = 0b101000;
        else if (op == "sh") opCode = 0b101001;
    }
        // format: op rt imme
    else if (op == "lui") {
        tReg = getRegCode(getNext(instruction));
        sReg = 0b00000;

        imme = signExtend(getNext(instruction), 16);

        opCode = 0b001111;
    }
        // format: op rs imme
    else if (op == "blez" || op == "bltz" || op == "bgtz" || op == "bgez") {
        sReg = getRegCode(getNext(instruction));

        addr = labelMap.value(getNext(instruction));
        addr = (addr - (programCounter + 4)) / 4;

        imme = signExtend(QString::number(addr), 16);

        if (op == "bgez") {
            opCode = 0b000001;
            tReg   = 0b00001;
        } else if (op == "bgtz") {
            opCode = 0b000111;
            tReg   = 0b00000;
        } else if (op == "blez") {
            opCode = 0b000110;
            tReg   = 0b00000;
        } else if (op == "bltz") {
            opCode = 0b000001;
            tReg   = 0b00000;
        }
    } else return;

    word = opCode;
    word = (word << REG_LEN) | sReg;
    word = (word << REG_LEN) | tReg;
    word = (word << IMME_LEN) | imme;

    binAppend(word);

    qDebug() << "I_Type: " << bin.right(4).toHex();
}

void AsmFile::J_TypeProcess(QStringList::const_iterator &instruction) {
    uint32_t opCode = 0b000000, offset, addr, word;

    if (*instruction == "j") opCode = 0b000010;
    else if (*instruction == "jal") opCode = 0b000011;

    addr   = labelMap.value(getNext(instruction)) / 4;
    offset = signExtend(QString::number(addr), 26);

    word = opCode;
    word = (word << OFFS_LEN) | offset;

    binAppend(word);

    qDebug() << "J_Type: " << bin.right(4).toHex();
}

void AsmFile::P_TypeProcess(QStringList::const_iterator &instruction) {
    uint32_t opCode, dReg, tReg, sReg, imme, addr, shAmt, func, word;
    QString  op = *instruction;

    if (op == "blt" || op == "ble" || op == "bgt" || op == "bge") {
        pseudoCompare(instruction);
    } else if (op == "la") {
        // format: la $at addr
        // expand: (1) lui $rt, addr[high]
        //         (2) ori $rt, $at, addr[low]

        opCode = 0b001111; // instruction 1

        tReg = 0b00001; // instruction 1
        sReg = 0b00000; // instruction 1

        word = opCode; // instruction 1
        word = (word << REG_LEN) | sReg; // instruction 1
        word = (word << REG_LEN) | tReg; // instruction 1

        tReg = getRegCode(getNext(instruction)); // instruction 2

        addr = labelMap.value(getNext(instruction)); // instruction 1 and 2

        imme = zeroExtend(QString::number(addr >> 16), IMME_LEN); // instruction 1

        word = (word << IMME_LEN) | imme; // instruction 1

        binAppend(word); // instruction 1
        programCounter += 4;
        PCToAsmMap.insert(programCounter, asmLine);

        opCode = 0b001101; // instruction 2
        sReg   = 0b00001; // instruction 2

        addr = addr & ((1 << IMME_LEN) - 1); // instruction 2

        imme = zeroExtend(QString::number(addr), IMME_LEN); // instruction 2

        word = opCode; // instruction 2
        word = (word << REG_LEN) | sReg; // instruction 2
        word = (word << REG_LEN) | tReg; // instruction 2
        word = (word << IMME_LEN) | imme; // instruction 2

        binAppend(word); // instruction 2

        qDebug() << "P_Type: " << bin.right(8).toHex();
    } else if (op == "move") {
        opCode = 0b000000;

        dReg = getRegCode(getNext(instruction));
        sReg = getRegCode(getNext(instruction));
        tReg = 0b00000;

        shAmt = 0b00000;

        func = 0b100101;

        word = opCode;
        word = (word << REG_LEN) | sReg;
        word = (word << REG_LEN) | tReg;
        word = (word << REG_LEN) | dReg;
        word = (word << SHAMT_LEN) | shAmt;
        word = (word << FUNC_LEN) | func;

        binAppend(word);

        qDebug() << "P_Type: " << bin.right(4).toHex();
    } else if (op == "li") {
        // format: li $rt imme
        // expand: (1) lui $at imme[high]
        //         (2) ori $rt $at imme[low]

        opCode = 0b001111; // (1)
        sReg   = 0b00000;  // (1)
        tReg   = 0b00001;  // (1)

        word = opCode;             // (1)
        word = (word << REG_LEN) | sReg; // (1)
        word = (word << REG_LEN) | tReg; // (1)

        tReg = getRegCode(getNext(instruction)); // (2)

        addr = zeroExtend(getNext(instruction), IMME_LEN); // (1) and (2)
        imme = addr >> IMME_LEN; // (1)

        word = (word << IMME_LEN) | imme; // (1)

        binAppend(word); // (1)
        programCounter += 4;
        PCToAsmMap.insert(programCounter, asmLine);

        opCode = 0b001101;                // (2)
        sReg   = 0b00001;                 // (2)
        imme   = addr & ((1 << IMME_LEN) - 1);  // (2)

        word = opCode;              // (2)
        word = (word << REG_LEN) | sReg;  // (2)
        word = (word << REG_LEN) | tReg;  // (2)
        word = (word << IMME_LEN) | imme; // (2)

        binAppend(word);

//        qDebug() << "P_Type: " << bin.right(8).toHex();
    } else {
//        qDebug() << "Skip  : " << op;
    }
}

int AsmFile::getRegCode(const QString &r) {
    if (r == "$0" || r == "$zero") return 0b00000;
    if (r == "$1" || r == "$at") return 0b00001;
    if (r == "$2" || r == "$v0") return 0b00010;
    if (r == "$3" || r == "$v1") return 0b00011;
    if (r == "$4" || r == "$a0") return 0b00100;
    if (r == "$5" || r == "$a1") return 0b00101;
    if (r == "$6" || r == "$a2") return 0b00110;
    if (r == "$7" || r == "$a3") return 0b00111;
    if (r == "$8" || r == "$t0") return 0b01000;
    if (r == "$9" || r == "$t1") return 0b01001;
    if (r == "$10" || r == "$t2") return 0b01010;
    if (r == "$11" || r == "$t3") return 0b01011;
    if (r == "$12" || r == "$t4") return 0b01100;
    if (r == "$13" || r == "$t5") return 0b01101;
    if (r == "$14" || r == "$t6") return 0b01110;
    if (r == "$15" || r == "$t7") return 0b01111;
    if (r == "$16" || r == "$s0") return 0b10000;
    if (r == "$17" || r == "$s1") return 0b10001;
    if (r == "$18" || r == "$s2") return 0b10010;
    if (r == "$19" || r == "$s3") return 0b10011;
    if (r == "$20" || r == "$s4") return 0b10100;
    if (r == "$21" || r == "$s5") return 0b10101;
    if (r == "$22" || r == "$s6") return 0b10110;
    if (r == "$23" || r == "$s7") return 0b10111;
    if (r == "$24" || r == "$t8") return 0b11000;
    if (r == "$25" || r == "$t9") return 0b11001;
    if (r == "$26" || r == "$k0") return 0b11010;
    if (r == "$27" || r == "$k1") return 0b11011;
    if (r == "$28" || r == "$gp") return 0b11100;
    if (r == "$29" || r == "$sp") return 0b11101;
    if (r == "$30" || r == "$fp") return 0b11110;
    return 0b11111;
}

//QString AsmFile::zeroExtent(QString string, int length) {
//    bool ok;
//
//    string = QString::number(string.toLongLong(&ok, string.left(2) == "0x" || string.left(2) == "0X"
//                                                    ? 16 : 10));
//
//    return string.rightJustified(length, '0');
//}

void AsmFile::pseudoCompare(QStringList::const_iterator &instruction) {
    // instruction 1: R type
    uint32_t opCode, sReg, tReg, dReg, shAmt, func, word;
    opCode = 0b000000;
    dReg   = 0b00001;

    if (*instruction == "bge" || *instruction == "blt") {
        sReg = getRegCode(getNext(instruction));
        tReg = getRegCode(getNext(instruction));
    } else {
        tReg = getRegCode(getNext(instruction));
        sReg = getRegCode(getNext(instruction));
    }

    shAmt = 0b00000;
    func  = 0b101010;

    word = opCode;
    word = (word << REG_LEN) | sReg;
    word = (word << REG_LEN) | tReg;
    word = (word << REG_LEN) | dReg;
    word = (word << SHAMT_LEN) | shAmt;
    word = (word << FUNC_LEN) | func;

    binAppend(word);
    programCounter += 4;
    PCToAsmMap.insert(programCounter, asmLine);

    // instruction 2: I type
    int          imme;
    unsigned int addr;

    sReg = 0b00001;
    tReg = 0b00000;

    if (*instruction == "bge" || *instruction == "ble")
        opCode = 0b000100;
    else
        opCode = 0b000101;

    addr = labelMap.value(getNext(instruction));
    addr = (addr - (programCounter + 4)) / 4;
    imme = signExtend(QString::number(addr), 16);

    word = opCode;
    word = (word << REG_LEN) | sReg;
    word = (word << REG_LEN) | tReg;
    word = (word << IMME_LEN) | imme;

    binAppend(word);
}

bool AsmFile::isSingleLine(QStringList::const_iterator &wordIter) {
    return *wordIter == "eret" ||
           *wordIter == "syscall" ||
           *wordIter == "break" ||
           *wordIter == "nop" ||
           *wordIter == "add" ||
           *wordIter == "addu" ||
           *wordIter == "sub" ||
           *wordIter == "subu" ||
           *wordIter == "and" ||
           *wordIter == "or" ||
           *wordIter == "xor" ||
           *wordIter == "nor" ||
           *wordIter == "slt" ||
           *wordIter == "sltu" ||
           *wordIter == "sll" ||
           *wordIter == "srl" ||
           *wordIter == "sra" ||
           *wordIter == "sllv" ||
           *wordIter == "srlv" ||
           *wordIter == "srav" ||
           *wordIter == "jr" ||
           *wordIter == "div" ||
           *wordIter == "divu" ||
           *wordIter == "mult" ||
           *wordIter == "multu" ||
           *wordIter == "jalr" ||
           *wordIter == "mtlo" ||
           *wordIter == "mthi" ||
           *wordIter == "mfhi" ||
           *wordIter == "mflo" ||
           *wordIter == "mfc0" ||
           *wordIter == "mtc0" ||
           *wordIter == "addi" ||
           *wordIter == "addiu" ||
           *wordIter == "andi" ||
           *wordIter == "ori" ||
           *wordIter == "xori" ||
           *wordIter == "lui" ||
           *wordIter == "lw" ||
           *wordIter == "sw" ||
           *wordIter == "beq" ||
           *wordIter == "bne" ||
           *wordIter == "slti" ||
           *wordIter == "sltiu" ||
           *wordIter == "lb" ||
           *wordIter == "lbu" ||
           *wordIter == "lh" ||
           *wordIter == "lhu" ||
           *wordIter == "sb" ||
           *wordIter == "sh" ||
           *wordIter == "blez" ||
           *wordIter == "bltz" ||
           *wordIter == "bgez" ||
           *wordIter == "bgtz" ||
           *wordIter == "j" ||
           *wordIter == "jal" ||
           *wordIter == "move" ||
           *wordIter == "nop";
}

bool AsmFile::isDoubleLine(QStringList::const_iterator &wordIter) {
    return *wordIter == "blt" ||
           *wordIter == "ble" ||
           *wordIter == "bgt" ||
           *wordIter == "bge" ||
           *wordIter == "la" ||
           *wordIter == "li";
}

QString AsmFile::getNext(QStringList::const_iterator &instruction) {
    while (*(++instruction) == "\n") {
        asmLine++;
        asmToPCMap.insert(asmLine, programCounter);
    }
    return *instruction;
}
