#ifndef MAIN_H
#define MAIN_H

#include "base.h"

bool loadData(bool **transactions, ArrayInfo2D &arrayInfo, const string &filename);
void parseFileName(int &transactions, int &items, const string &filename);
void initializeTransactionArray(bool **transactions, ArrayInfo2D &arrayInfo, int sizeI, int sizeJ);

#endif