#include "apriori.h"


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
*********************************************************************************************/
void addCandidatesToLTree(const vector<vector<int>> &candidates, Trie &largeItemsets)
{
	for (int i = 0; i < candidates.size(); i++)
		largeItemsets.addNode(candidates[i]);;
}


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
*********************************************************************************************/
void calcCandidateSupport(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie& candidates, int depth)
{
	vector<vector<int>> itemsets;
	candidates.getAllPathsAtDepth(itemsets, depth);

	int currentItemsetSupport;
	bool foundInTransaction;

	//For each potential candidate itemset
  for (int curItemset = 0; curItemset < itemsets.size(); curItemset++)
	{
		currentItemsetSupport = 0; //set this candidate's support to 0

		//for every transaction in the database
		for (int curTrans = 0; curTrans < arrInfo.sizeI; curTrans++)
		{
			foundInTransaction = true;

			//For each item in the itemset, check if it's in this transaction (at least until we find one that isn't there)
      for (int curItem = 0; curItem < itemsets[curItemset].size() && foundInTransaction; curItem++)
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
  vector<int> paths;

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
					paths.push_back(curItem);
					largeItemsets.addNode(paths);
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
  vector<vector<int>> previousLevelItems;
  vector<int> thisCandidate;

  largeItemsets.getAllPathsAtDepth(previousLevelItems, depth - 1);

	//Loop through all the combinations of itemsets
  for (int i = 0; i < previousLevelItems.size(); i++)
	{
    for (int j = i; j < previousLevelItems.size(); j++)
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
	vector<vector<int>> resultsOfThisStep;
	Trie candidates;

	calculate1Itemsets(transactions, arrInfo, minSupport, largeItemsets);

	for (int k = 2;; k++)
	{
		candidateGen(largeItemsets, candidates, k);
		calcCandidateSupport(transactions, arrInfo, minSupport, candidates, k);

		//Check if we have anything to add this step
    candidates.getAllPathsAtDepth(resultsOfThisStep, k);
    if (resultsOfThisStep.size() == 0)
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
void unionTwoArrays(const vector<int> &array1, const vector<int> &array2, vector<int>& output)
{
	output.clear();

	int i = 0, j = 0;
  while (i < array1.size() && j < array2.size())
	{
		if (array1[i] < array2[j])
			output.push_back(array1[i++]);
		else if (array2[j] < array1[i])
      output.push_back(array2[j++]);
		else
		{
      output.push_back(array2[j]);
			j++;
			i++;
		}
	}

  while (i < array1.size())
    output.push_back(array1[i++]);

  while (j < array2.size())
    output.push_back(array2[j++]);
}