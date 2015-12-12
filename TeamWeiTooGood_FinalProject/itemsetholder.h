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
#ifndef TRIE_H
#define TRIE_H

#include "basefunctions.h"
#include "itemset.h"

class ItemsetHolder
{
private:
	DynamicArray<DynamicArray<Itemset*>> myContents;

public:
	ItemsetHolder();
	~ItemsetHolder();

	void setMinSupport(const DynamicArray<int> &path, bool hasMinSupport);
	bool getHasMinSupport(const DynamicArray<int> &path) const;

	bool getPathExists(const DynamicArray<int> &path) const;

	void getAllItemsets(DynamicArray<DynamicArray<int>> &allSets) const;
	void getAllTwoOrLargerSets(DynamicArray<DynamicArray<int>> &sets) const;
	void getAllSetsAtDepth(DynamicArray<DynamicArray<int>> &setsAtDepth, int depth) const;

	bool addNode(const DynamicArray<int> &path, int itemId);
	bool addNode(const DynamicArray<int> &path);
	bool isEmpty() const;
	bool removeNode(const DynamicArray<int> &path);

	void clearTrie();
};

#endif