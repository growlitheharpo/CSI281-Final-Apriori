#include "apriori.h"


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
*********************************************************************************************/
void addCandidatesToLTree(const DynamicArray<DynamicArray<int>> &candidates, Trie &largeItemsets)
{
	for (int i = 0; i < candidates.count(); i++)
		largeItemsets.addNode(candidates[i], candidates[i][candidates[i].count() - 1]);;
}


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
*********************************************************************************************/
void calcCandidateSupport(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie& candidates, int depth)
{
	DynamicArray<DynamicArray<int>> itemsets;
	candidates.getAllPathsAtDepth(itemsets, depth);

	int currentItemsetSupport;
	bool foundInTransaction;

	//For each potential candidate itemset
	for (int curItemset = 0; curItemset < itemsets.count(); curItemset++)
	{
		currentItemsetSupport = 0; //set this candidate's support to 0

		//for every transaction in the database
		for (int curTrans = 0; curTrans < arrInfo.sizeI; curTrans++)
		{
			foundInTransaction = true;

			//For each item in the itemset, check if it's in this transaction (at least until we find one that isn't there)
			for (int curItem = 0; curItem < itemsets[curItemset].count() && foundInTransaction; curItem++)
				foundInTransaction = transactions[curTrans][itemsets[curItemset][curItem]];

			//If we found everything, increment support
			if (foundInTransaction)
			{
				currentItemsetSupport++;

				//If support is at min support, note that this itemset has support and move on
				if (currentItemsetSupport >= minSupport)
				{
					candidates.setMinSupport(itemsets[curItemset], true);
					break;
				}
			}
		}

		//If it didn't meet minimum support, remove it from the candidate trie
		if (currentItemsetSupport < minSupport)
			candidates.removeNode(itemsets[curItemset]);
	}
}


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
*********************************************************************************************/
void calculate1Itemsets(const bool **transactions, const ArrayInfo2D &arrInfo, int minSupport, Trie &largeItemsets)
{
	int supportForThisItem = 0;
	DynamicArray<int> paths;

	//For each potential item
	for (int curItem = 0; curItem < arrInfo.sizeJ; curItem++)
	{
		//Loop over every transaction
		for (int curTransaction = 0; curTransaction < arrInfo.sizeI; curTransaction++)
		{
			//If this item existed in the transaction, ++ its count
			if (transactions[curTransaction][curItem])
			{
				supportForThisItem++;
				
				//If we hit minimum support, add it and break (to the next item)
				if (supportForThisItem >= minSupport)
				{
					paths.clear();
					paths.insert(curItem);
					largeItemsets.addNode(paths, curItem);
					break;
				}
			}
		}
	}
}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
void candidateGen(const Trie &largeItemsets, Trie &candidateItemsets, int depth)
{
	DynamicArray<DynamicArray<int>> previousLevelItems;
	DynamicArray<int> thisCandidate;

  largeItemsets.getAllPathsAtDepth(previousLevelItems, depth - 1);

	//Loop through all the combinations of itemsets
	for (int i = 0; i < previousLevelItems.count(); i++)
	{
		for (int j = i; j < previousLevelItems.count(); j++)
		{
			//Union the two, then add them to candidates
			unionTwoArrays(previousLevelItems[i], previousLevelItems[j], thisCandidate);
			candidateItemsets.addNode(thisCandidate);
		}
	}
}


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
*********************************************************************************************/
void runApriori(const bool **transactions, const ArrayInfo2D &arrInfo, int minSupport, Trie &largeItemsets)
{
	DynamicArray<DynamicArray<int>> resultsOfThisStep;
	Trie candidates;

	calculate1Itemsets(transactions, arrInfo, minSupport, largeItemsets);

	for (int k = 2;; k++)
	{
		candidateGen(largeItemsets, candidates, k);
		calcCandidateSupport(transactions, arrInfo, minSupport, candidates, k);

		//Check if we have anything to add this step
    candidates.getAllPathsAtDepth(resultsOfThisStep, k);
		if (resultsOfThisStep.count() == 0)
			break;

		addCandidatesToLTree(resultsOfThisStep, largeItemsets);
	}
}


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
*  Source: http://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/
*********************************************************************************************/
void unionTwoArrays(const DynamicArray<int> &array1, const DynamicArray<int> &array2, DynamicArray<int>& output)
{
	output.clear();

	int i = 0, j = 0;
	while (i < array1.count() && j < array2.count())
	{
		if (array1[i] < array2[j])
			output.insert(array1[i++]);
		else if (array2[j] < array1[i])
			output.insert(array2[j++]);
		else
		{
			output.insert(array2[j]);
			j++;
			i++;
		}
	}

	while (i < array1.count())
		output.insert(array1[i++]);

	while (j < array2.count())
		output.insert(array2[j++]);
}