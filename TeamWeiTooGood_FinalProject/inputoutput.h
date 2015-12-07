#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "basefunctions.h"
#include "trie.h"

bool	getContinue();
string	getFileName();
int		getMinimumSupport(int totalTransactionCount);
void	initializeTransactionArray(bool **transactions, ArrayInfo2D &arrayInfo, int sizeI, int sizeJ);
bool	loadData(bool **transactions, ArrayInfo2D &arrayInfo, const string &filename);
void	outputResults(double time, const Trie& largeItemsets);
void	parseFileName(int &transactions, int &items, const string &filename);

#endif