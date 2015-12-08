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

void Trie::setMinSupport(DynamicArray<int> path, bool hasMinSupport)
{

}

bool Trie::getHasMinSupport(DynamicArray<int> path)
{
	return false;
}

bool Trie::addNode(DynamicArray<int> path, int itemId)
{
	if (path.count() == 0)
	{
		mRootNode->mChildren.insert(new Node(itemId));
		return true;
	}
	else
	{
		Node *node = traverseTrie(path, mRootNode);

		if (node->mItemId == path[path.count() - 1])
		{
			node->mChildren.insert(new Node(itemId));
			return true;
		}
		else
			return false;
	}
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

		DynamicArray<int> thisNodesChildren = currentNode->thisSet.thisSet;
		allPaths.insert(thisNodesChildren);

		for (int i = 0; i < currentNode->mChildren.count(); i++)
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

bool Trie::removeNode(DynamicArray<int> path)
{
	//   int lastNode = path[path.count() - 1];
	//   path.removeAt(path.count() - 1);
	// 	Node *node


	return false;
}

Trie::Node* Trie::traverseTrie(DynamicArray<int> path, Node *node)
{
	for (int i = 0; i < path.count(); i++)
	{
		for (int j = 0; j < node->mChildren.count(); j++)
		{
			if (node->mChildren[j]->mItemId == path[i])
			{
				node = node->mChildren[j];
				break;
			}
		}
	}

	return node;
}