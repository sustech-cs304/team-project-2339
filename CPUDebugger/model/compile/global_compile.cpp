#include "global_compile.h"

qsizetype TYPE_SIZE = 5;

std::pair<qsizetype, qsizetype> global_type[] ={
    std::pair(0, 12),
    std::pair(13, 5),
    std::pair(18, 7),
};

QString global_data[] = {
    "0 #",
    "1 <",
    "2 >",
    "3 (",
    "4 )",
    "5 [",
    "6 [",
    "7 {",
    "8 }",
    "9 ,",
    "10 ;",
    "11 _",
    "12 `",
    "13 +",
    "14 -",
    "15 *",
    "16 /",
    "17 %",
    "31 module",
    "32 endmodule",
    "33 input",
    "34 output",
    "35 reg",
    "36 wire",
    "37 assign",
};
