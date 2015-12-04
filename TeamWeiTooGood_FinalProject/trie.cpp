#include "trie.h"

Trie::Trie()
{
  mRootNode = new Node();
  mRootNode->mItemId = -1;    //No itemId
}

Trie::~Trie()
{
  emptyTrie();
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

void Trie::emptyTrie()
{
  //for (int i = 0; i < mRootNode->mChildren->
}


bool Trie::isEmpty()
{
  return mRootNode->mChildren->size() == 0;
}

bool Trie::isLeaf(Node node)
{
  return 
}

bool Trie::removeNode(int path[])
{

}

void Trie::traverseTrie(int path[], Node *&someNode)
{

}