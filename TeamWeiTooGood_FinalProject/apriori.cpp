/*
Author:           James Keats, David Horntvedt
Class:            CSI-281-02
Assignment:       Apriori
Due Date:         12/12/2015 @ 11:59 PM

Description:
Apriori. What else is there to say.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references
to the work of others. I understand the definition and consequences of plagiarism and acknowledge
that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then
retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/
#include "apriori.h"
#include "timerSystem.h"


/*********************************************************************************************
* Purpose: Add the candidates to the set of itemsets that are large.
*     Pre: Both sets have been properly declared. Candidates has ALREADY BEEN PRUNED
*	 Post: Candidates are added to the list of large itemsets.
*********************************************************************************************/
void addCandidatesToLTree(const DynamicArray<DynamicArray<int>> &candidates, ItemsetHolder &largeItemsets)
{
	for (int i = 0; i < candidates.count(); i++)
		largeItemsets.addNode(candidates[i]);;
}


/*********************************************************************************************
*  Purpose: Calculate the support for candidates at this depth and delete those not meeting
*			minimum support.
*      Pre: Handed transactions and sizeinfo about transactions, as well as what the minimum
*			support is, the holder of candidates, and the depth we're working at.
*	  Post: Candidates is updated to include only those meeting minimum support.
*********************************************************************************************/
void calcCandidateSupport(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, ItemsetHolder& candidates, int depth)
{
	DynamicArray<DynamicArray<int>> itemsets;
	candidates.getAllSetsAtDepth(itemsets, depth);

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
			{
				foundInTransaction = transactions[curTrans][itemsets[curItemset][curItem]];
			}

			//If every item in this set was found in this transaction, increment support
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
*  Purpose:	Calculate the 1-itemsets meeting minimum support and add them to the holder.
*      Pre:	Handed valid transactions and sizeinfo, as well as minimum support and the holder
*			for large itemsets.
*	  Post:	The large 1-itemsets are added to the holder.
*********************************************************************************************/
void calculate1Itemsets(const bool **transactions, const ArrayInfo2D &arrInfo, int minSupport, ItemsetHolder &largeItemsets)
{
	int supportForThisItem;
	DynamicArray<int> paths;

	//For each potential item
	for (int curItem = 0; curItem < arrInfo.sizeJ; curItem++)
	{
		supportForThisItem = 0;

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
					largeItemsets.addNode(paths);
					break;
				}
			}
		}
	}
}


/*********************************************************************************************
*  Purpose:	Generate candidates at the current depth.
*      Pre:	Handed the previous large itemsets, the holder for candidates, and our current k.
*	  Post:	Valid candidates are added to the candidate holder.
*********************************************************************************************/
void candidateGen(const ItemsetHolder &largeItemsets, ItemsetHolder &candidateItemsets, int depth)
{
	DynamicArray<DynamicArray<int>> previousLevelItems;
	DynamicArray<int> thisCandidate;

	largeItemsets.getAllSetsAtDepth(previousLevelItems, depth - 1);

	//Loop through all the combinations of itemsets
	for (int i = 0; i < previousLevelItems.count(); i++)
	{
		for (int j = i + 1; j < previousLevelItems.count(); j++)
		{
			if (!itemsetsHaveFirstKInCommon(previousLevelItems[i], previousLevelItems[j], depth - 2))
				continue;

			if (previousLevelItems[i] == previousLevelItems[j]) continue;

			//Union the two, then add them to candidates
			thisCandidate = previousLevelItems[i];
			thisCandidate.insert(previousLevelItems[j][previousLevelItems[j].count() - 1]);

			candidateItemsets.addNode(thisCandidate);
		}
	}
}


/*********************************************************************************************
*  Purpose:	Check if the two itemsets have the first k elements in common
*      Pre:	Handed two properly initialized itemsets of a size greater than k.
*	  Post:	Return true if the first k items are the same in the two sets.
*********************************************************************************************/
bool itemsetsHaveFirstKInCommon(const DynamicArray<int> &set1, const DynamicArray<int> &set2, int k)
{
	for (int i = 0; i < k; i++)
	{
		if (set1[i] != set2[i])
			return false;
	}

	return true;
}


/*********************************************************************************************
*  Purpose:	Run the apriori algorithm on the given transactions and place the resulting sets
*			in largeItemsets, and the time results in results.
*      Pre:	Handed the loaded transactions and the size of each, as well as the minimum
*			support, and the initialized and cleared items and results.
*	  Post:	largeItemsets and results are updated with the resulting values.
*********************************************************************************************/
void runApriori(const bool **transactions, const ArrayInfo2D &arrInfo, int minSupport, ItemsetHolder &largeItemsets, DynamicArray<AprioriResult> &results)
{
	DynamicArray<DynamicArray<int>> resultsOfThisStep;
	ItemsetHolder candidates;
	TimerSystem timer;
	double timeResult = 0.0;

	timer.startClock();
	calculate1Itemsets(transactions, arrInfo, minSupport, largeItemsets);
	timeResult = timer.getTime();

	largeItemsets.getAllSetsAtDepth(resultsOfThisStep, 1);
	results.insert(AprioriResult(1, resultsOfThisStep.count(), timeResult));

	for (int k = 2;; k++)
	{
		timer.startClock();

		candidateGen(largeItemsets, candidates, k);
		calcCandidateSupport(transactions, arrInfo, minSupport, candidates, k);

		//Check if we have anything to add this step
		candidates.getAllSetsAtDepth(resultsOfThisStep, k);
		if (resultsOfThisStep.count() == 0)
			break;

		addCandidatesToLTree(resultsOfThisStep, largeItemsets);

		timeResult = timer.getTime();
		results.insert(AprioriResult(k, resultsOfThisStep.count(), timeResult));
	}
}
