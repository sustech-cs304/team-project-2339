#include "CParser.h"

QList<CPUSignal> CParser::export_signals()
{
    QList<CPUSignal> signalList;
    for (verilog::Instance inst: this->insts) {
        for (std::vector<verilog::NetConcat> nets: inst.net_names) {
            for (auto &v: nets) {
                if (v.index() == 0) {
                    std::pair<int, int> p = searchWidth(std::get<0>(v));
                    signalList.append(CPUSignal(QString::fromStdString(std::get<0>(v)), p.first, p.second));
                } else {
                    signalList.append(CPUSignal::createInstance(v));
                }
            }
        }
    }
    return signalList;
}

std::pair<int, int> CParser::searchWidth(std::string name)
{
    for (auto port: ports) {
        for (auto s : port.names) {
            if (s == name) {
                return std::pair<int, int>(port.end, port.beg);
            }
        }
    }
    for (auto net: nets) {
        for (auto s : net.names) {
            if (s == name) {
                return std::pair<int, int>(net.end, net.beg);
            }
        }
    }
    return std::pair<int, int>(-1, -1);
}

