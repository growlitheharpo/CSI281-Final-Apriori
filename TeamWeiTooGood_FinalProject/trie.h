#ifndef TRIE_H
#define TRIE_H

#include "basefunctions.h"
#include "dynamicarray.h"

class Trie
{
	private:
		struct Node
		{
			DynamicArray<Node*> *mChildren;
      bool                mHasMinSupport;
      int                 mItemId;


			/*     Pre:  None
			*     Post:  This object is initialized using default values
			*  Purpose:  To initialize date object
			*************************************************************************/
			Node()
			{
				mChildren = new DynamicArray<Node*>();
				mItemId = int();
        mHasMinSupport = false;
			}

			/*     Pre:  None
			*     Post:  This object is initialized using specified data
			*  Purpose:  To initialize date object
			*************************************************************************/
			Node(int itemId)
			{
				mChildren = new DynamicArray<Node*>();
				mItemId = itemId;
        mHasMinSupport = false;
			}
		};

		Node *mRootNode;

		bool isLeaf(Node node);
		void traverseTrie(int path[], Node *&someNode);

	public:
		Trie();
		~Trie();

    void setMinSupport(int path[], bool hasMinSupport);
    bool getHasMinSupport(int path[]);

		bool addNode(int path[]);
		void emptyTrie();
		bool isEmpty();
		bool removeNode(int path[]);

};

#endif