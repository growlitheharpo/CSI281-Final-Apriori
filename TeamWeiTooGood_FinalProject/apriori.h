#ifndef APRIORI_H
#define APRIORI_H

#include "basefunctions.h"
#include "trie.h"

void addCandidatesToLTree(const DynamicArray<DynamicArray<int>>& candidates, Trie& largeItemsets);
void calcCandidateSupport(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie&  candidates, int depth);
void calculate1Itemsets(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie& largeItemsets);
void candidateGen(const Trie& largeItemsets, Trie& candidateItemsets, int depth);
bool itemsetsHaveFirstKInCommon(const DynamicArray<int> &set1, const DynamicArray<int> &set2, int k);
void runApriori(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie& largeItemsets);
void unionTwoArrays(const DynamicArray<int>& array1, const DynamicArray<int> &array2, DynamicArray<int>& output);

#endif