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

bool Trie::addNode(int path[])
{

}

void Trie::emptyTrie()
{
  //for (int i = 0; i < mRootNode->mChildren->
}


bool Trie::isEmpty()
{
  //if(mRootNode->mChildren)
}

bool Trie::isLeaf(Node node)
{

}

bool Trie::removeNode(int path[])
{

}

void Trie::traverseTrie(int path[], Node *&someNode)
{

}