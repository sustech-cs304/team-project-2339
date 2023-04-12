#include "CompileFactory.h"

CompileFactory::CompileFactory(MAlex *alex)
{
    this->alex = alex;
}

void CompileFactory::addTopModule(QList<Token> &tokenList, qsizetype index)
{
//    FileStore *fs = FileStore::getInstance();
//    ModuleData *md = fs->getModuleData("top");
    int p = 0;
    Module *m;
    while (p < tokenList.length()) {
        Token &t = tokenList[p];
        if (!t.s.compare("module") && t.t == KEY) {
            m = new Module(tokenList[++p].s);
        } else if (!t.s.compare("input") && t.t == KEY) {
            while (tokenList[p+1].t == ID) {
                m->addSignal(tokenList[p+1].s, SIG_IN);
                p += 2;
            }
        } else if (!t.s.compare("output") && t.t == KEY) {
            while (tokenList[p+1].t == ID) {
                m->addSignal(tokenList[p+1].s, SIG_OUT);
                p += 2;
            }
        }
        p++;
    }
}
