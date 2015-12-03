#ifndef BASE_H
#define BASE_H

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

void clearScreen(bool alsoPause = false);
void pause();

#endif