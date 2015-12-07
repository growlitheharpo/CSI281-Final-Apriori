#include "apriori.h"


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
*********************************************************************************************/
void addCandidatesToLTree(Trie& candidates, Trie& largeItemsets, int depth)
{

}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
void calcCandidateSupport(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie& candidates, int depth)
{

}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
void calculate1Itemsets(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie& largeItemsets)
{

}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
void candidateGen(const Trie& largeItemsets, Trie& candidateItemsets, int depth)
{

}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
void runApriori(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie& largeItemsets)
{
	Trie candidates;

	calculate1Itemsets(transactions, arrInfo, minSupport, largeItemsets);

	for (int k = 2;; k++)
	{
		candidateGen(largeItemsets, candidates, k);
		calcCandidateSupport(transactions, arrInfo, minSupport, candidates, k);

		if (pruneCandidates(candidates, k) == false)
			break;

		addCandidatesToLTree(candidates, largeItemsets, k);
	}
}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: RETURNS TRUE IF ANY ITEMS ARE LEFT IN CANDIDATES, RETURNS FALSE IF ALL CANDIDATES
*			AT THIS DEPTH WERE PRUNED
*********************************************************************************************/
bool pruneCandidates(Trie& candidates, int depth)
{

}