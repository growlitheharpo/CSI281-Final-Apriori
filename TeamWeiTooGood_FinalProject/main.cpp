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
		largeItemsets.clear();

		filename = getFileName();

		if (!loadData(transactions, transactionSizeInfo, filename))
			continue;

		minimumSupport = getMinimumSupport(transactionSizeInfo.sizeI);

		//Do apriori
		timer.startClock();
		runApriori(const_cast<const bool**>(transactions), transactionSizeInfo, minimumSupport, largeItemsets);
		time = timer.getTime();

		//show results
		outputResults(time, largeItemsets);

		//deallocate transactions and ask to continue
		cleanupTransactions(transactions, transactionSizeInfo);
		keepRunning = getContinue();
	}

	return 0;
}