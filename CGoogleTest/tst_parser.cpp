
#include "compile/CParser.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

TEST(ParserTest, Interface) {
    CParser *p = new CParser();
    p->read("./not_exist_file");
    delete p;
}
