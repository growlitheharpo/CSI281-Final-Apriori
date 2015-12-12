#include "basefunctions.h"

/*********************************************************************************************
* Purpose:  Clear transactions array
*     Pre:  Transactions and arrayInfo must be initialized
*	 Post:    Transactions are cleared
*********************************************************************************************/
void cleanupTransactions(bool** &transactions, ArrayInfo2D arrayInfo)
{
	bool *currentPointer;
	for (int i = 0; i < arrayInfo.sizeI; i++)
	{
		currentPointer = transactions[i];

		delete[] currentPointer;
	}

	delete[] transactions;
	transactions = NULL;
}


/*********************************************************************************************
* Purpose: Clear console
*     Pre: None
*	 Post: Console is cleared
*********************************************************************************************/
void clearScreen(bool pauseFirst)
{
	if (pauseFirst)
		pause();

	system("cls");
}


/*********************************************************************************************
* Purpose: Pause execution
*     Pre: None
*	 Post: Execution is paused
*********************************************************************************************/
void pause()
{
	system("pause");
}