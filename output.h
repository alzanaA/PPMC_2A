#ifndef OUTPUT_H
#define OUTPUT_H
#include "tipedata.h"


void output(int n, int m, struct Queue * database);
int search(struct table * LUT, char * p, int m);
char* getValue(struct table * LUT, int index, int m);
char* getKey(struct table * LUT, int index);
node * getValueRand(node * value, node * current, int word_index);

#endif