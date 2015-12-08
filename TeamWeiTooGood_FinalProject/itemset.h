#ifndef ITEMSET_H
#define ITEMSET_H

#include "dynamicarray.h"

struct Itemset
{
	DynamicArray<int> thisSet;
	int support;

	Itemset()
	{
		this->thisSet.clear();
		this->support = 0;
	}

	Itemset(DynamicArray<int> &set)
	{
		this->thisSet = set;
		this->support = 0;
	}

	Itemset(DynamicArray<int> &set, int support)
	{
		this->thisSet = set;
		this->support = support;
	}
};

#endif
