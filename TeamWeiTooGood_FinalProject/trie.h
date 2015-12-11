#ifndef TRIE_H
#define TRIE_H

#include "basefunctions.h"
#include "itemset.h"

class Trie
{
	private:
		struct Node
		{
			DynamicArray<Node*> mChildren;
			Itemset				      thisSet;
			int                 mItemId;


			/*     Pre:  None
			*     Post:  This object is initialized using default values
			*  Purpose:  To initialize date object
			*************************************************************************/
			Node()
			{
				mItemId = int();
        thisSet.hasMinSupport = false;
			}

			/*     Pre:  None
			*     Post:  This object is initialized using specified data
			*  Purpose:  To initialize date object
			*************************************************************************/
			Node(int itemId)
			{
				mItemId = itemId;
        thisSet.hasMinSupport = false;
			}

      ~Node(){}
		};

		Node *mRootNode;

		bool isLeaf(Node *node) const;
    void removeAll(Node *node);
		Node* traverseTrie(const DynamicArray<int> &path) const;

	public:
		Trie();
    ~Trie() { delete mRootNode; }



    bool addNode(const DynamicArray<int> &path);
    void clear();
    void displayAllPaths();
    void displayAllPathsAtDepth(int depth);
    void getAllPaths(DynamicArray<DynamicArray<int>> &allPaths) const;
    void getAllPathsAtDepth(DynamicArray<DynamicArray<int>> &pathsAtDepth, int depth) const;
    bool getHasMinSupport(const DynamicArray<int> &path) const;
    bool isEmpty() const;
    bool removeNode(const DynamicArray<int> &path);
    void setMinSupport(const DynamicArray<int> &path, bool hasMinSupport);
};

#endif