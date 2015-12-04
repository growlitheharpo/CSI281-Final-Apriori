#include "trie.h"

Trie::Trie()
{
  mRootNode = new Node();
  mRootNode->mItemId = -1;    //No itemId
}

Trie::~Trie()
{
  emptyTrie(mRootNode);
}

void Trie::setMinSupport(int path[], bool hasMinSupport)
{

}

bool Trie::getHasMinSupport(int path[])
{

}

bool Trie::addNode(int path[])
{

}

void Trie::destroySubtrie(Node *node)
{
  if (isLeaf(node))
  {
    return;
  }
  else
  {
    while (node->mChildren->count() > 0)
    {
      destroySubtrie(node->mChildren[0]);
      //delete node->mChildren[0];
      //node->mChildren[0]->mItemId = 5;
    }
  }
}


bool Trie::isEmpty()
{
  return mRootNode->mChildren->count() == 0;
}

bool Trie::isLeaf(Node *node)
{
  return node->mChildren->count() == 0;
}

bool Trie::removeNode(int path[])
{

}

void Trie::traverseTrie(int path[], Node *&someNode)
{

}