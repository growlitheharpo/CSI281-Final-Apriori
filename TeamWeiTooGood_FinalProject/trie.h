#ifndef TRIE_H
#define TRIE_H

#include "basefunctions.h"
#include "itemset.h"

class Trie
{
	private:
		struct Node
		{
			vector<Node*> mChildren;
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

      ~Node(){}
		};

		Node *mRootNode;

		void destroySubtrie(Node *node);
		bool isLeaf(Node *node) const;
		Node* traverseTrie(const vector<int> &path) const;

	public:
		Trie();
    ~Trie() { delete mRootNode; }

    void getAllPaths(vector<vector<int>> &allPaths) const;
    void getAllPathsAtDepth(vector<vector<int>> &pathsAtDepth, int depth) const;
    bool getHasMinSupport(const vector<int> &path) const;

    void setMinSupport(const vector<int> &path, bool hasMinSupport);

    bool addNode(const vector<int> &path);
    void displayAllPaths();
    void displayAllPathsAtDepth(int depth);
    bool isEmpty() const;
    bool removeNode(const vector<int> &path);

};

#endif