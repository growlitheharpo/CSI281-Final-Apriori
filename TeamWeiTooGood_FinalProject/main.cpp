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
#include "inputoutput.h"
#include "apriori.h"
#include <string>

int interactiveMain()
{
	DynamicArray<AprioriResult> results;
	ItemsetHolder largeItemsets;
	ArrayInfo2D transactionSizeInfo;
	bool **transactions = NULL;

	string filename = "";
	bool keepRunning = true;
	int minimumSupport = 0;
	double time;

	while (keepRunning)
	{
		largeItemsets.clearTrie();
		time = 0.0;

		filename = getFileName();

		if (!loadData(transactions, transactionSizeInfo, filename))
			continue;

		minimumSupport = getMinimumSupport(transactionSizeInfo.sizeI);

		//Do apriori
		runApriori(const_cast<const bool**>(transactions), transactionSizeInfo, minimumSupport, largeItemsets, results);

		for (int i = 0; i < results.count(); i++)
			time += results[i].mTimeForThisDepth;

		//show results
		outputResults(time, largeItemsets);

		//deallocate transactions and ask to continue
		cleanupTransactions(transactions, transactionSizeInfo);
		keepRunning = getContinue();
	}

	system("pause");
	return 0;
}

int testingMain()
{
	DynamicArray<AprioriResult> allResults[NUM_OF_DATASETS][NUM_OF_MINSUPPORTS][NUM_OF_TRIALS];

	ItemsetHolder largeItemsets;
	ArrayInfo2D transactionSizeInfo;
	bool **transactions = NULL;

	string currentFile;
	int currentMinSupport;

	for (int i = 0; i < NUM_OF_DATASETS; i++)
	{
		currentFile = "datasets\\" + DATASET_LIST[i];
		cout << "Testing " << currentFile << endl;
		if (!loadData(transactions, transactionSizeInfo, currentFile))
		{
			cout << "Could not load " << currentFile << endl;
			continue;
		}

		for (int j = 0; j < NUM_OF_MINSUPPORTS; j++)
		{
			currentMinSupport = (transactionSizeInfo.sizeI * MINIMUM_SUPPORT_LIST[j]) / 100;

			for (int k = 0; k < NUM_OF_TRIALS; k++)
			{
				largeItemsets.clearTrie();
				runApriori(const_cast<const bool**>(transactions), transactionSizeInfo, currentMinSupport, largeItemsets, allResults[i][j][k]);
			}

		}

		cleanupTransactions(transactions, transactionSizeInfo);
	}

	outputAllTestResults(allResults);

	system("pause");
	return 0;
}

int main()
{
	//entry point

	return testingMain();
	//return interactiveMain();
}