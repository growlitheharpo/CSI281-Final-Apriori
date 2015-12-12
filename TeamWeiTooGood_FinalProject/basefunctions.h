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
#ifndef BASE_FUNCTIONS_H
#define BASE_FUNCTIONS_H

#include <iostream>
#include "aprioriresult.h"

using namespace std;

struct ArrayInfo2D
{
	int sizeI, sizeJ;

	ArrayInfo2D()
	{
		this->sizeI = 0;
		this->sizeJ = 0;
	}

	ArrayInfo2D(int i, int j)
	{
		this->sizeI = i;
		this->sizeJ = j;
	}
};

void cleanupTransactions(bool** &transactions, ArrayInfo2D array_info2_d);
void clearScreen(bool pauseFirst = false);
void pause();

#endif