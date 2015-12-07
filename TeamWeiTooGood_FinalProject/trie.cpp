#include "trie.h"
#include "simpleQueue.h"

Trie::Trie()
{
  mRootNode = new Node();
  mRootNode->mItemId = -1;    //No itemId
}

Trie::~Trie()
{
  destroySubtrie(mRootNode);
}

void Trie::setMinSupport(int path[], bool hasMinSupport)
{

}

bool Trie::getHasMinSupport(int path[])
{
  return false;
}

bool Trie::addNode(int path[])
{
  return false;
}

void Trie::destroySubtrie(Node *node)
{
  if (isLeaf(node))
  {
    return;
  }
  else
  {
    while (node->mChildren.count() > 0)
    {
      destroySubtrie(node->mChildren[0]);
      //delete node->mChildren[0];
      //node->mChildren[0]->mItemId = 5;
    }
  }
}

void Trie::getAllPaths(DynamicArray<DynamicArray<int>> &allPaths)
{
	SimpleQueue<Node *> nodeQueue;
	Node *currentNode;
	nodeQueue.enqueue(mRootNode);

	while (nodeQueue.getCount() > 0)
	{
		currentNode = nodeQueue.dequeue();

		for (int i = 0; i < currentNode->mChildren->count(); i++)
			nodeQueue.enqueue((currentNode->mChildren[i]));
	}
}



bool Trie::isEmpty()
{
  return mRootNode->mChildren.count() == 0;
}

bool Trie::isLeaf(Node *node)
{
  return node->mChildren.count() == 0;
}

bool Trie::removeNode(int path[])
{
  return false;
}

void Trie::traverseTrie(int path[], Node *&someNode)
{

}