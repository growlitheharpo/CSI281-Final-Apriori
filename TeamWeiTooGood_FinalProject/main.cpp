#include "inputoutput.h"
#include "apriori.h"
#include "timerSystem.h"

//Name this main once we're ready to start
int actualMain()
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
		filename = getFileName();

		if (!loadData(transactions, transactionSizeInfo, filename))
			continue;

		minimumSupport = getMinimumSupport(transactionSizeInfo.sizeJ);

		timer.startClock();
		runApriori(const_cast<const bool**>(transactions), transactionSizeInfo, minimumSupport, largeItemsets);
		time = timer.getTime();

		outputResults(time, largeItemsets);

		delete[] transactions;
		keepRunning = getContinue();
	}

	return 0;
}

#include <iostream>

int main()
{
	Trie largeItemsets;
	ArrayInfo2D transactionSizeInfo(4, 6);

	const bool transactions[4][6] = { { false, true, true, true, true, false },
								{ false, true, false, false, false, false },
								{ false, true, false, true, true, true },
								{ true, true, false, false, false, false } };

	int minimumSupport = 2;

	runApriori(transactions, transactionSizeInfo, minimumSupport, largeItemsets);

	outputResults(0.0, largeItemsets);

	system("pause");
	return 0;
}