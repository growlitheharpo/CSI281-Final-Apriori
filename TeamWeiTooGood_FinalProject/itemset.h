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
