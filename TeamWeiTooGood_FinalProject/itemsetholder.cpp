#include "itemsetholder.h"
#include "simpleQueue.h"


/*********************************************************************************************
*  Purpose:	Default constructor
*      Pre:	None
*	  Post:	Trie is initialized
*********************************************************************************************/
ItemsetHolder::ItemsetHolder()
{
	myContents.clear();
}


/*********************************************************************************************
*  Purpose:	Destructor
*      Pre:	None
*	  Post:	Trie is destroyed and memory is released.
*********************************************************************************************/
ItemsetHolder::~ItemsetHolder()
{
	clearTrie();
}


/*********************************************************************************************
*  Purpose:	Set minimum support for the node at a given path
*      Pre:	Handed the path to the node, and whether or not it has support
*	  Post:	Node is updated
*********************************************************************************************/
void ItemsetHolder::setMinSupport(const DynamicArray<int> &path, bool hasMinSupport)
{
	int level = path.count();
	for (int i = 0; i < myContents[level].count(); i++)
	{
		if (path == myContents[level][i]->thisSet)
		{
			myContents[level][i]->hasMinSupport = true;
			break;
		}
	}
}


/*********************************************************************************************
*  Purpose:	Determine if the node at a given node meets minimum support.
*      Pre:	Handed the path
*	  Post:	Returns true if the node at the given path has min support, false otherwise.
*********************************************************************************************/
bool ItemsetHolder::getHasMinSupport(const DynamicArray<int> &path) const
{
	int level = path.count();
	if (level >= myContents.count()) return false;

	for (int i = 0; i < myContents[level].count(); i++)
	{
		if (path == (myContents[level][i]->thisSet))
			return myContents[level][i]->hasMinSupport;
	}

	return false;
}


/*********************************************************************************************
*  Purpose:
*      Pre:
*	  Post:
*********************************************************************************************/
bool ItemsetHolder::getPathExists(const DynamicArray<int> &path) const
{
	int level = path.count();

	if (level >= myContents.count())
		return false;

	for (int i = 0; i < myContents[level].count(); i++)
	{
		if (path == myContents[level][i]->thisSet)
		{
			return true;
		}
	}

	return false;
}


/*********************************************************************************************
*  Purpose:	Add a node to the tree with the given itemId and path
*      Pre:	Handed the path and the id of the new item
*	  Post:	Item is added to the tree
*********************************************************************************************/
bool ItemsetHolder::addNode(const DynamicArray<int> &path, int itemId)
{
	return addNode(path);
}


/*********************************************************************************************
*  Purpose:	Add a node to the tree with the given path
*      Pre:	Handed the path of the new item
*	  Post:	Item is added to the tree
*********************************************************************************************/
bool ItemsetHolder::addNode(const DynamicArray<int> &path)
{
	int level = path.count();
	while (level >= myContents.count())
		myContents.insert(DynamicArray<Itemset*>());

	myContents[level].insert(new Itemset(path));

	return true;
}


/*********************************************************************************************
*  Purpose:	Get ALL potential paths (itemsets) stored in the tree
*      Pre:	Handed the declared DA<DA<int>> where the paths will be stored.
*	  Post:	All paths stored in the trie are inserted into the array.
*********************************************************************************************/
void ItemsetHolder::getAllPaths(DynamicArray<DynamicArray<int>> &allPaths) const
{
	allPaths.clear();

	for (int i = 0; i < myContents.count(); i++)
	{
		for (int j = 0; j < myContents[i].count(); j++)
		{
			allPaths.insert(myContents[i][j]->thisSet);
		}
	}
}


/*********************************************************************************************
*  Purpose:
*      Pre:
*	  Post:
*********************************************************************************************/
void ItemsetHolder::getAllPathsAtDepth(DynamicArray<DynamicArray<int>> &pathsAtDepth, int depth) const
{
	pathsAtDepth.clear();

	if (depth >= myContents.count()) return;

	for (int j = 0; j < myContents[depth].count(); j++)
	{
		pathsAtDepth.insert(myContents[depth][j]->thisSet);
	}
}



/*********************************************************************************************
*  Purpose:	Is the trie empty?
*      Pre:	None
*	  Post:	True if root has no children, false otherwise
*********************************************************************************************/
bool ItemsetHolder::isEmpty() const
{
	return (myContents.count() > 0);
}


/*********************************************************************************************
*  Purpose:	Remove a node at a given path.
*      Pre:	Handed the path to remove the node from.
*	  Post:	Returns false if the item could not be found, otherwise true and item is removed.
*********************************************************************************************/
bool ItemsetHolder::removeNode(const DynamicArray<int> &path)
{
	int level = path.count();

	if (level >= myContents.count()) return false;

	for (int i = 0; i < myContents[level].count(); i++)
	{
		if (path == myContents[level][i]->thisSet)
		{
			myContents[level].removeAt(i);
			return true;
		}
	}

	return false;
}


/*********************************************************************************************
*  Purpose:
*      Pre:
*	  Post:
*********************************************************************************************/
void ItemsetHolder::clearTrie()
{
	for (int i = myContents.count() - 1; i >= 0; i--)
	{
		for (int j = myContents[i].count() - 1; j >= 0; j--)
		{
			delete myContents[i][j];
		}

		myContents[i].clear();
	}

	myContents.clear();
}
