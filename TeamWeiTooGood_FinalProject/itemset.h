#ifndef ITEMSET_H
#define ITEMSET_H

#include "dynamicarray.h"
#include <vector>
struct Itemset
{
	vector<int> thisSet;
	bool hasMinSupport;

	Itemset()
	{
		this->thisSet.clear();
		this->hasMinSupport = false;
	}

  Itemset(vector<int> &set)
	{
		this->thisSet = set;
		this->hasMinSupport = false;
	}

  Itemset(vector<int> &set, bool support)
	{
		this->thisSet = set;
		this->hasMinSupport = support;
	}
};

#endif
