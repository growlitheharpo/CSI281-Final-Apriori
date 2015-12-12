#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "basefunctions.h"
#include "itemsetholder.h"

const int NUM_OF_DATASETS = 5,
		  NUM_OF_MINSUPPORTS = 3,
		  NUM_OF_TRIALS = 3;

const string DATASET_LIST[] =
{
	"T25.N0.1K.D10K.txt", //DELETE ME
	"T5.N0.1K.D1K.txt",
	"T5.N0.1K.D10K.txt",
	"T5.N0.1K.D100K.txt",
	"T5.N0.5K.D1K.txt",
	"T5.N0.5K.D10K.txt",
	"T5.N0.5K.D100K.txt",
	"T5.N1K.D1K.txt",
	"T5.N1K.D10K.txt",
	"T5.N1K.D100K.txt",
	"T20.N0.1K.D1K.txt",
	"T20.N0.1K.D10K.txt",
	"T20.N0.1K.D100K.txt",
	"T20.N0.5K.D1K.txt",
	"T20.N0.5K.D10K.txt",
	"T20.N0.5K.D100K.txt",
	"T20.N1K.D1K.txt",
	"T20.N1K.D10K.txt",
	"T20.N1K.D100K.txt",
	"T25.N0.1K.D1K.txt",
	"T25.N0.1K.D10K.txt",
	"T25.N0.1K.D100K.txt",
	"T25.N0.5K.D1K.txt",
	"T25.N0.5K.D10K.txt",
	"T25.N0.5K.D100K.txt",
	"T25.N1K.D1K.txt",
	"T25.N1K.D10K.txt",
	"T25.N1K.D100K.txt"
};

const int MINIMUM_SUPPORT_LIST[] = { 35, 50, 70 };

bool	getContinue();
string	getFileName();
int		getMinimumSupport(const int totalTransactionCount);
void	initializeTransactionArray(bool** &transactions, ArrayInfo2D &arrayInfo, int sizeI, int sizeJ);
bool	loadData(bool** &transactions, ArrayInfo2D &arrayInfo, const string &filename);
void	outputResults(double time, const ItemsetHolder& largeItemsets);
void	outputAllTestResults(DynamicArray<AprioriResult> allResults[NUM_OF_DATASETS][NUM_OF_MINSUPPORTS][NUM_OF_TRIALS]);
void	parseFileName(int &transactions, int &items, const string &filename);
void	readFile(bool **transactions, const ArrayInfo2D &arrayInfo, ifstream& fin);

#endif