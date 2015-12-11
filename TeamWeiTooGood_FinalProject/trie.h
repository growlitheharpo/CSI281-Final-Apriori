#ifndef TRIE_H
#define TRIE_H

#include "basefunctions.h"
#include "itemset.h"

class Trie
{
private:
	DynamicArray<DynamicArray<Itemset*>> myContents;

public:
	Trie();
	~Trie();

	void setMinSupport(const DynamicArray<int> &path, bool hasMinSupport);
	bool getHasMinSupport(const DynamicArray<int> &path) const;

	bool getPathExists(const DynamicArray<int> &path) const;

	void getAllPaths(DynamicArray<DynamicArray<int>> &allPaths) const;
	void getAllPathsAtDepth(DynamicArray<DynamicArray<int>> &pathsAtDepth, int depth) const;

	bool addNode(const DynamicArray<int> &path, int itemId);
	bool addNode(const DynamicArray<int> &path);
	bool isEmpty() const;
	bool removeNode(const DynamicArray<int> &path);
};

#endif