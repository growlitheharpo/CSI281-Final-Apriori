#include "inputoutput.h"
#include "apriori.h"
#include "timerSystem.h"

int main()
{
	TimerSystem timer;
	Trie largeItemsets;
	ArrayInfo2D transactionSizeInfo;
	bool **transactions = NULL;

	string filename = "";
	bool keepRunning = true;
	int minimumSupport = 0;
	double time;

	while (keepRunning)
	{
		largeItemsets.clearTrie();

		filename = getFileName();
		//filename = "datasets\\T25.N0.1K.D10K.txt";

		if (!loadData(transactions, transactionSizeInfo, filename))
			continue;

		minimumSupport = getMinimumSupport(transactionSizeInfo.sizeI);

		timer.startClock();
		runApriori(const_cast<const bool**>(transactions), transactionSizeInfo, minimumSupport, largeItemsets);
		time = timer.getTime();

		outputResults(time, largeItemsets);

		cleanupTransactions(transactions, transactionSizeInfo);
		keepRunning = getContinue();
	}

	return 0;
}