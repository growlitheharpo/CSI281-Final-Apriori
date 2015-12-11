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