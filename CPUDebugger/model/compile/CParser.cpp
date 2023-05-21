#include "CParser.h"

QList<CPUSignal> CParser::export_signals()
{
    QList<CPUSignal> signalList;
    for (verilog::Instance inst: this->insts) {
        for (std::vector<verilog::NetConcat> nets: inst.net_names) {
            for (auto &v: nets) {
                signalList.append(CPUSignal::createInstance(v));
            }
        }
    }
    for (CPUSignal& sig: signalList) {
        qDebug() << sig.name << " [" << sig.lBound << ", " << sig.rBound << "]";
    }
    return signalList;
}

