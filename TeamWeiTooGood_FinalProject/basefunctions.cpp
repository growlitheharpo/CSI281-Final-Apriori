#include "basefunctions.h"


void cleanupTransactions(bool** &transactions, ArrayInfo2D arrayInfo)
{
	/*
	bool *currentPointer;
	for (int i = 0; i < arrayInfo.sizeI; i++)
	{
		currentPointer = transactions[i];

		delete[] currentPointer;
	}

	delete[] transactions;
	*/
	cout << "Transactions is currently leaking." << endl;
}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
void clearScreen(bool pauseFirst)
{
	if (pauseFirst)
		pause();

	system("cls");
}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
void pause()
{
	system("pause");
}