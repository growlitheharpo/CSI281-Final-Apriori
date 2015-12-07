#ifndef BASE_FUNCTIONS_H
#define BASE_FUNCTIONS_H

#include <iostream>

using namespace std;

struct ArrayInfo2D
{
	int sizeI, sizeJ;

	ArrayInfo2D(int i, int j)
	{
		this->sizeI = i;
		this->sizeJ = j;
	}
};

void clearScreen(bool pauseFirst = false);
void pause();

#endif