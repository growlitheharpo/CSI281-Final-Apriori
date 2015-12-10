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
*  Purpose:	Set minimum support for the node at a given path
*      Pre:	Handed the path to the node, and whether or not it has support
*	  Post:	Node is updated
*********************************************************************************************/
void Trie::setMinSupport(const vector<int> &path, bool hasMinSupport)
{
  Node *node = traverseTrie(path);
  node->thisSet.hasMinSupport = hasMinSupport;
}


/*********************************************************************************************
*  Purpose:	Determine if the node at a given node meets minimum support.
*      Pre:	Handed the path
*	  Post:	Returns true if the node at the given path has min support, false otherwise.
*********************************************************************************************/
bool Trie::getHasMinSupport(const vector<int> &path) const
{
  Node *node = traverseTrie(path);
  return node->thisSet.hasMinSupport;
}

/*********************************************************************************************
*  Purpose:	Add a node to the tree with the given path
*      Pre:	Handed the path of the new item
*	  Post:	Item is added to the tree
*********************************************************************************************/
bool Trie::addNode(const vector<int> &path)
{
  Node *node = traverseTrie(path);

  node->mChildren.insert(new Node(path[path.count() - 1]));
  return true;

}


/*********************************************************************************************
*  Purpose:	Destroy a subtrie in the trie.
*      Pre:	Handed the node before which to begin deleting
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
      delete node->mChildren[0];
    }
  }
}


/*********************************************************************************************
*  Purpose:	Get ALL potential paths (itemsets) stored in the tree
*      Pre:	Handed the declared DA<DA<int>> where the paths will be stored.
*	  Post:	All paths stored in the trie are inserted into the array.
*********************************************************************************************/
void Trie::getAllPaths(vector<vector<int>> &allPaths) const
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

void Trie::getAllPathsAtDepth(vector<vector<int>> &pathsAtDepth, int depth) const
{
  getAllPathsAtDepthStart(pathsAtDepth, depth, mRootNode, 0);
}

/*********************************************************************************************
*  Purpose:	Get all paths from the nodes at a certain depth/level of the tree.
*      Pre:	Handed the DA<DA<int>> to store the paths, and what depth/level to get them from.
*	  Post:	pathsAtDepth is filled with the paths at the given depth/level.
*********************************************************************************************/
void Trie::getAllPathsAtDepthStart(vector<vector<int>> &pathsAtDepth, int depth, const Node *currentNode, int currentDepth) const
{
  if (currentDepth == depth)
  {
    pathsAtDepth.insert(currentNode->thisSet.thisSet);
    return;
  }
  else
  {
    for (int i = 0; i < currentNode->mChildren.count(); i++)
    {
      getAllPathsAtDepthStart(pathsAtDepth, depth, currentNode->mChildren[i], currentDepth + 1);
    }
  }
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
bool Trie::removeNode(const vector<int> &path)
{
  Node *node = traverseTrie(path),
    *currentNode;

  for (int i = 0; i < node->mChildren.count(); i++)
  {
    currentNode = node->mChildren[i];
    if (currentNode->mItemId == path[path.count() - 1] && isLeaf(currentNode))
    {
      node->mChildren.removeAt(i);
      delete currentNode;
      return true;
    }
  }

  return false;
}


/*********************************************************************************************
*  Purpose:	Traverse the trie to end of path
*      Pre:	Handed the path to wanted node
*	  Post:	Wanted node is returned
*********************************************************************************************/
Trie::Node* Trie::traverseTrie(const vector<int> &path) const
{
  Node *node = mRootNode;

  for (int i = 0; i < path.count() - 1; i++)
  {
    for (int j = 0; j < node->mChildren.count(); j++)
    {
      if (node->mChildren[j]->mItemId == path[i])
      {
        return node->mChildren[j];
      }
    }
  }

  return node;
}
