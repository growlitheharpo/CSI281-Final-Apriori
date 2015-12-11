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

//Public functions
/*********************************************************************************************
*  Purpose:	Add a node to the tree with the given path
*      Pre:	Handed the path of the new item
*	  Post:	Item is added to the tree
*********************************************************************************************/
bool Trie::addNode(const DynamicArray<int> &path)
{
  Node *node = traverseTrie(path);
  Node *newNode = new Node(path[path.size() - 1]);

  newNode->thisSet.thisSet = path;

  if (newNode != NULL)
  {
    node->mChildren.push_back(newNode);
    return true;
  }
  else
    return false;
}

/*********************************************************************************************
*  Purpose: Clear trie
*      Pre:	Trie must be initialized
*	  Post:	Trie is empty
*********************************************************************************************/
void Trie::clear()
{
  for (int i = 0; i < mRootNode->mChildren.count(); i++)
  {
    removeAll(mRootNode->mChildren[i]);
  }

  while (mRootNode->mChildren.count() > 0)
  {
    delete mRootNode->mChildren[0];
    mRootNode->mChildren.removeAt(0);
  }
}

/*********************************************************************************************
*  Purpose:	Display all paths to screen
*      Pre:	Trie must be initialized
*	  Post:	All paths are displayed on screen
*********************************************************************************************/
void Trie::displayAllPaths()
{
  DynamicArray<DynamicArray<int>> allPaths;

  getAllPaths(allPaths);

  for (int i = 0; i < allPaths.size(); i++)
  {
    for (int j = 0; j < allPaths[i].size(); j++)
    {
      cout << allPaths[i][j] << " ";
    }
    cout << endl;
  }
}

/*********************************************************************************************
*  Purpose:	Display all paths at a certain depth to screen
*      Pre:	Trie must be initialized and a depth must be passed in
*	  Post:	All paths at a certain depth are displayed on screen
*********************************************************************************************/
void Trie::displayAllPathsAtDepth(int depth)
{
  DynamicArray<DynamicArray<int>> allPathsDepth;

  getAllPathsAtDepth(allPathsDepth, depth);

  cout << "\nDepth: " << depth << endl;
  for (int i = 0; i < allPathsDepth.size(); i++)
  {
    for (int j = 0; j < allPathsDepth[i].size(); j++)
    {
      cout << allPathsDepth[i][j] << " ";
    }
    cout << endl;
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
    allPaths.push_back(thisNodesChildren);

    for (int i = 0; i < currentNode->mChildren.size(); i++)
      nodeQueue.enqueue((currentNode->mChildren[i]));
  }

  //Remove rootNode
  allPaths.removeAt(0);
}

/*********************************************************************************************
*  Purpose:	Get ALL potential paths (itemsets) stored in the tree at a given depth
*      Pre:	Handed the declared DA<DA<int>> where the paths will be stored and the depth.
*	  Post:	All paths stored in the trie at the given depth are inserted into the array.
*********************************************************************************************/
void Trie::getAllPathsAtDepth(DynamicArray<DynamicArray<int>> &pathsAtDepth, int depth) const
{
  DynamicArray<DynamicArray<int>> allPaths;
  getAllPaths(allPaths);

  for (int i = 0; i < allPaths.size(); i++)
  {
    if (allPaths[i].size() == depth)
    {
      pathsAtDepth.push_back(allPaths[i]);
    }
  }
}

/*********************************************************************************************
*  Purpose:	Determine if the node at a given node meets minimum support.
*      Pre:	Handed the path
*	  Post:	Returns true if the node at the given path has min support, false otherwise.
*********************************************************************************************/
bool Trie::getHasMinSupport(const DynamicArray<int> &path) const
{
  Node *node = traverseTrie(path);
  return node->thisSet.hasMinSupport;
}

/*********************************************************************************************
*  Purpose:	Is the trie empty?
*      Pre:	None
*	  Post:	True if root has no children, false otherwise
*********************************************************************************************/
bool Trie::isEmpty() const
{
  return mRootNode->mChildren.size() == 0;
}

/*********************************************************************************************
*  Purpose:	Remove a node at a given path.
*      Pre:	Handed the path to remove the node from.
*	  Post:	Returns false if the item could not be found, otherwise true and item is removed.
*********************************************************************************************/
bool Trie::removeNode(const DynamicArray<int> &path)
{
  Node *node = traverseTrie(path),
    *currentNode;

  for (int i = 0; i < node->mChildren.size(); i++)
  {
    currentNode = node->mChildren[i];
    if (currentNode->mItemId == path[path.size() - 1] && isLeaf(currentNode))
    {
      node->mChildren.removeAt(i);
      delete currentNode;
      return true;
    }
  }

  return false;
}

/*********************************************************************************************
*  Purpose:	Set minimum support for the node at a given path
*      Pre:	Handed the path to the node, and whether or not it has support
*	  Post:	Node is updated
*********************************************************************************************/
void Trie::setMinSupport(const DynamicArray<int> &path, bool hasMinSupport)
{
  Node *node = traverseTrie(path);
  node->thisSet.hasMinSupport = hasMinSupport;
}

//Private Functions
/*********************************************************************************************
*  Purpose:	Determine if a given node is a leaf.
*      Pre:	Handed a node.
*	  Post:	True if node is a leaf, false otherwise.
*********************************************************************************************/
bool Trie::isLeaf(Node *node) const
{
  return node->mChildren.size() == 0;
}

/*********************************************************************************************
*  Purpose:	Remove node and all children
*      Pre:	Handed a node to delete
*	  Post:	Node and subtrie is deleted
*********************************************************************************************/
void Trie::removeAll(Node *node)
{
  if (isLeaf(node))
    return;
  
  for (int i = 0; i < node->mChildren.count(); i++)
  {
    removeAll(node->mChildren[i]);
  }

  while (node->mChildren.count() > 0)
  {
    delete node->mChildren[0];
    node->mChildren.removeAt(0);
  }
}

/*********************************************************************************************
*  Purpose:	Traverse the trie to end of path
*      Pre:	Handed the path to wanted node
*	  Post:	Wanted node is returned
*********************************************************************************************/
Trie::Node* Trie::traverseTrie(const DynamicArray<int> &path) const
{
  Node *node = mRootNode;

  for (int i = 0; i < path.size() - 1; i++)
  {
    for (int j = 0; j < node->mChildren.size(); j++)
    {
      if (node->mChildren[j]->mItemId == path[i])
      {
        return node->mChildren[j];
      }
    }
  }

  return node;
}


