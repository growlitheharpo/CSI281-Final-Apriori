#ifndef TRIE_H
#define TRIE_H

#include "basefunctions.h"
#include "itemset.h"
#include <vector>

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

      ~Node()
      {
        cout << "Deleting node with item: " << mItemId << endl;     //For debug
      }
		};


		void destroySubtrie(Node *node);
		bool isLeaf(Node *node) const;
		Node* traverseTrie(const vector<int> &path) const;
    void getAllPathsAtDepthStart(vector<vector<int>> &pathsAtDepth, int depth, const Node *currentNode, int currentDepth) const;

		Node *mRootNode;
	public:
		Trie();
    ~Trie() { delete mRootNode; }

    void setMinSupport(const vector<int> &path, bool hasMinSupport);
    bool getHasMinSupport(const vector<int> &path) const;

    void getAllPaths(vector<vector<int>> &allPaths) const;
    void getAllPathsAtDepth(vector<vector<int>> &pathsAtDepth, int depth) const;

    bool addNode(const vector<int> &path);
		bool isEmpty() const;
    bool removeNode(const vector<int> &path);

};

#endif