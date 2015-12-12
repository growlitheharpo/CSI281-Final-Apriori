#ifndef ITEMSET_H
#define ITEMSET_H

#include "dynamicarray.h"

struct Itemset
{
	DynamicArray<int> thisSet;
	bool hasMinSupport;

  /*********************************************************************************************
  * Purpose:  Initialize
  *     Pre:  None
  *	 Post: Itemset is initialized
  *********************************************************************************************/
	Itemset()
	{
		this->thisSet.clear();
		this->hasMinSupport = false;
	}

  /*********************************************************************************************
  * Purpose:  Initialize with an itemset
  *     Pre:  Initialized itemset
  *	 Post: Itemset is initialized
  *********************************************************************************************/
	Itemset(const DynamicArray<int> &set)
	{
		this->thisSet = set;
		this->hasMinSupport = false;
	}

	Itemset(const Itemset& other)
	{
		this->thisSet = other.thisSet;
		this->hasMinSupport = other.hasMinSupport;
	}

	Itemset(const DynamicArray<int> &set, bool support)
	{
		this->thisSet = set;
		this->hasMinSupport = support;
	}

	Itemset& operator = (const Itemset& other)
	{
		this->thisSet = other.thisSet;
		this->hasMinSupport = other.hasMinSupport;

		return *this;
	}
};

#endif
