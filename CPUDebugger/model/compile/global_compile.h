#ifndef GLOBAL_COMPILE_H
#define GLOBAL_COMPILE_H
#include <QtCore>
#include <string>
#define RANGE 0
#define OPN 1
#define KEY 2
#define ID 3
#define CONS 4
typedef int Type;
typedef int Code;
typedef QString Line;

extern qsizetype TYPE_SIZE;

extern std::pair<qsizetype, qsizetype> global_type[];

extern QString global_data[];

#endif // GLOBAL_COMPILE_H
