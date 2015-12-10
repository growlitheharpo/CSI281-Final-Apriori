#ifndef ITEMSET_H
#define ITEMSET_H

#include "dynamicarray.h"

struct Itemset
{
	DynamicArray<int> thisSet;
	bool hasMinSupport;

	Itemset()
	{
		this->thisSet.clear();
		this->hasMinSupport = false;
	}

	Itemset(const DynamicArray<int> &set)
	{
		this->thisSet = set;
		this->hasMinSupport = false;
	}

	Itemset(const DynamicArray<int> &set, bool support)
	{
		this->thisSet = set;
		this->hasMinSupport = support;
	}
};

#endif
