#ifndef APRIORI_H
#define APRIORI_H

#include "basefunctions.h"
#include "itemsetholder.h"

void addCandidatesToLTree(const DynamicArray<DynamicArray<int>>& candidates, ItemsetHolder& largeItemsets);
void calcCandidateSupport(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, ItemsetHolder&  candidates, int depth);
void calculate1Itemsets(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, ItemsetHolder& largeItemsets);
void candidateGen(const ItemsetHolder& largeItemsets, ItemsetHolder& candidateItemsets, int depth);
bool itemsetsHaveFirstKInCommon(const DynamicArray<int> &set1, const DynamicArray<int> &set2, int k);
void runApriori(const bool **transactions, const ArrayInfo2D &arrInfo, int minSupport, ItemsetHolder &largeItemsets, DynamicArray<AprioriResult> &results);

#endif