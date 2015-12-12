#include "inputoutput.h"
#include "apriori.h"


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
		for (int j = 0; j < NUM_OF_MINSUPPORTS; j++)
		{
			currentFile = "datasets\\" + DATASET_LIST[i];
			loadData(transactions, transactionSizeInfo, currentFile);
			currentMinSupport = (transactionSizeInfo.sizeI * MINIMUM_SUPPORT_LIST[j]) / 100;

			for (int k = 0; k < NUM_OF_TRIALS; k++)
			{
				largeItemsets.clearTrie();
				runApriori(const_cast<const bool**>(transactions), transactionSizeInfo, currentMinSupport, largeItemsets, allResults[i][j][k]);
			}

			cleanupTransactions(transactions, transactionSizeInfo);
		}
	}

	outputAllTestResults(allResults);

	return 0;
}

int main()
{
	//entry point

	return testingMain();
	//return interactiveMain();
}