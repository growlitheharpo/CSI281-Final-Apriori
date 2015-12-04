#ifndef TRIE_H
#define TRIE_H

#include "basefunctions.h"
#include "dynamicarray.h"

class Trie
{
private:
  struct Node
  {
    int                 mItemId;
    DynamicArray<Node*> *mChildren;

    /*     Pre:  None
    *     Post:  This object is initialized using default values
    *  Purpose:  To initialize date object
    *************************************************************************/
    Node()
    {
      mItemId = int();
      mChildren = new DynamicArray<Node*>();
    }

    /*     Pre:  None
    *     Post:  This object is initialized using specified data
    *  Purpose:  To initialize date object
    *************************************************************************/
    Node(int itemId)
    {
      mItemId = itemId;
      mChildren = new DynamicArray<Node*>();
    }
  };

  Node *mRootNode;
  bool isLeaf(Node node);
  void traverseTrie(int path[], Node *&someNode);

public:
  Trie();
  ~Trie();

  bool addNode(int path[]);
  void emptyTrie();
  bool isEmpty();
  bool removeNode(int path[]);

};

#endif