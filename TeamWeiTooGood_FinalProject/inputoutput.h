/*
Author:           James Keats, David Horntvedt
Class:            CSI-281-02
Assignment:       Apriori
Due Date:         12/12/2015 @ 11:59 PM

Description:
Apriori. What else is there to say.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references
to the work of others. I understand the definition and consequences of plagiarism and acknowledge
that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then
retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/
#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "basefunctions.h"
#include "itemsetholder.h"

const int NUM_OF_DATASETS = 27,
		  NUM_OF_MINSUPPORTS = 3,
		  NUM_OF_TRIALS = 3;

const string DATASET_LIST[] =
{
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

const int MINIMUM_SUPPORT_LIST[] = { 15, 25, 40 };

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