#ifndef TRIE_H
#define TRIE_H

#include "basefunctions.h"
#include "dynamicarray.h"

class Trie
{
	private:
		struct Node
		{
			DynamicArray<Node*> mChildren;
      DynamicArray<int>   mPath;
      bool                mHasMinSupport;
      int                 mItemId;


			/*     Pre:  None
			*     Post:  This object is initialized using default values
			*  Purpose:  To initialize date object
			*************************************************************************/
			Node()
			{
				mItemId = int();
        mHasMinSupport = false;
			}

			/*     Pre:  None
			*     Post:  This object is initialized using specified data
			*  Purpose:  To initialize date object
			*************************************************************************/
			Node(int itemId)
			{
				mItemId = itemId;
        mHasMinSupport = false;
			}
		};

		Node *mRootNode;

		void destroySubtrie(Node *node);
		bool isLeaf(Node *node);
		Node* traverseTrie(DynamicArray<int> path, Node *someNode);

	public:
		Trie();
		~Trie();

    void setMinSupport(DynamicArray<int> path, bool hasMinSupport);
    bool getHasMinSupport(DynamicArray<int> path);

    void getAllPaths(DynamicArray<DynamicArray<int>> &allPaths); 

    bool addNode(DynamicArray<int> path, int itemId);
		bool isEmpty();
    bool removeNode(DynamicArray<int> path);

};

#endif