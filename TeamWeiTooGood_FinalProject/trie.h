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
			}

			/*     Pre:  None
			*     Post:  This object is initialized using specified data
			*  Purpose:  To initialize date object
			*************************************************************************/
			Node(int itemId)
			{
				mItemId = itemId;
			}

      ~Node()
      {
        cout << "Deleting node with item: " << mItemId << endl;     //For debug
      }
		};


		void destroySubtrie(Node *node);
		bool isLeaf(Node *node) const;
		Node* traverseTrie(const DynamicArray<int> &path) const;
    void getAllPathsAtDepthStart(DynamicArray<DynamicArray<int>> &pathsAtDepth, int depth, const Node *currentNode, int currentDepth) const;

	public:
		Node *mRootNode;    //ONLY FOR DEBUG!!
		Trie();
		~Trie();

    void setMinSupport(const DynamicArray<int> &path, bool hasMinSupport);
		bool getHasMinSupport(const DynamicArray<int> &path) const;

		void getAllPaths(DynamicArray<DynamicArray<int>> &allPaths) const;
    void getAllPathsAtDepth(DynamicArray<DynamicArray<int>> &pathsAtDepth, int depth) const;

		bool addNode(const DynamicArray<int> &path, int itemId);
		bool addNode(const DynamicArray<int> &path);
		bool isEmpty() const;
		bool removeNode(const DynamicArray<int> &path);

};

#endif