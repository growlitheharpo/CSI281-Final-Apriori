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