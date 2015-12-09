#include "trie.h"
#include "simpleQueue.h"


/*********************************************************************************************
*  Purpose:	Default constructor
*      Pre:	None
*	  Post:	Trie is initialized
*********************************************************************************************/
Trie::Trie()
{
	mRootNode = new Node();
	mRootNode->mItemId = -1;    //No itemId
}


/*********************************************************************************************
*  Purpose:	Destructor
*      Pre:	None
*	  Post:	Trie is destroyed and memory is released.
*********************************************************************************************/
Trie::~Trie()
{
	destroySubtrie(mRootNode);
}


/*********************************************************************************************
*  Purpose:	Set minimum support for the node at a given path
*      Pre:	Handed the path to the node, and whether or not it has support
*	  Post:	Node is updated
*********************************************************************************************/
void Trie::setMinSupport(const DynamicArray<int> &path, bool hasMinSupport)
{

}


/*********************************************************************************************
*  Purpose:	Determine if the node at a given node meets minimum support.
*      Pre:	Handed the path
*	  Post:	Returns true if the node at the given path has min support, false otherwise.
*********************************************************************************************/
bool Trie::getHasMinSupport(const DynamicArray<int> & path) const
{

}


/*********************************************************************************************
*  Purpose:	Add a node to the tree with the given itemId and path
*      Pre:	Handed the path and the id of the new item
*	  Post:	Item is added to the tree
*********************************************************************************************/
bool Trie::addNode(const DynamicArray<int> &path, int itemId)
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


/*********************************************************************************************
*  Purpose:	Add a node to the tree with the given path
*      Pre:	Handed the path of the new item
*	  Post:	Item is added to the tree
*********************************************************************************************/
bool Trie::addNode(const DynamicArray<int>& path)
{

}


/*********************************************************************************************
*  Purpose:	Destroy a subtrie in the trie.
*      Pre:	Handed the node at which to begin deleting
*	  Post:	Subtrie is deleted
*********************************************************************************************/
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


/*********************************************************************************************
*  Purpose:	Get ALL potential paths (itemsets) stored in the tree
*      Pre:	Handed the declared DA<DA<int>> where the paths will be stored.
*	  Post:	All paths stored in the trie are inserted into the array.
*********************************************************************************************/
void Trie::getAllPaths(DynamicArray<DynamicArray<int>> &allPaths) const
{
	SimpleQueue<Node *> nodeQueue;
	Node *currentNode;
	nodeQueue.enqueue(mRootNode);

	allPaths.clear();

	while (nodeQueue.getCount() > 0)
	{
		currentNode = nodeQueue.dequeue();

		DynamicArray<int> thisNodesChildren = currentNode->thisSet.thisSet;
		allPaths.insert(thisNodesChildren);

		for (int i = 0; i < currentNode->mChildren.count(); i++)
			nodeQueue.enqueue((currentNode->mChildren[i]));
	}
}


/*********************************************************************************************
*  Purpose:	Get all paths from the nodes at a certain depth/level of the tree.
*      Pre:	Handed the DA<DA<int>> to store the paths, and what depth/level to get them from.
*	  Post:	pathsAtDepth is filled with the paths at the given depth/level.
*********************************************************************************************/
void Trie::getAllPathsAtDepth(DynamicArray<DynamicArray<int>> &pathsAtDepth, int depth) const
{

}


/*********************************************************************************************
*  Purpose:	Is the trie empty?
*      Pre:	None
*	  Post:	True if root has no children, false otherwise
*********************************************************************************************/
bool Trie::isEmpty() const
{
	return mRootNode->mChildren.count() == 0;
}


/*********************************************************************************************
*  Purpose:	Determine if a given node is a leaf.
*      Pre:	Handed a node.
*	  Post:	True if node is a leaf, false otherwise.
*********************************************************************************************/
bool Trie::isLeaf(Node *node) const
{
	return node->mChildren.count() == 0;
}


/*********************************************************************************************
*  Purpose:	Remove a node at a given path.
*      Pre:	Handed the path to remove the node from.
*	  Post:	Returns false if the item could not be found, otherwise true and item is removed.
*********************************************************************************************/
bool Trie::removeNode(const DynamicArray<int> &path)
{
	//   int lastNode = path[path.count() - 1];
	//   path.removeAt(path.count() - 1);
	// 	Node *node


	return false;
}


/*********************************************************************************************
*  Purpose:	david what the fuck is this
*      Pre:	
*	  Post:	
*********************************************************************************************/
Trie::Node* Trie::traverseTrie(const DynamicArray<int> &path, Node *node) const
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
