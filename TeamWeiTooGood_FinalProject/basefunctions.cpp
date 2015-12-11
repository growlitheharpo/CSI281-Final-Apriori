#include "basefunctions.h"


void cleanupTransactions(bool** transactions, ArrayInfo2D arrayInfo)
{
	for (int i = arrayInfo.sizeI - 1; i >= 0; i--)
	{
		delete[] transactions[i];
	}

	delete[] transactions;
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