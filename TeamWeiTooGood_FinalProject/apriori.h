#ifndef APRIORI_H
#define APRIORI_H

#include "basefunctions.h"
#include "trie.h"

void addCandidatesToLTree(const vector<vector<int>>& candidates, Trie& largeItemsets);
void calcCandidateSupport(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie&  candidates, int depth);
void calculate1Itemsets(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie& largeItemsets);
void candidateGen(const Trie& largeItemsets, Trie& candidateItemsets, int depth);
void runApriori(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie& largeItemsets);
void unionTwoArrays(const vector<int>& array1, const vector<int> &array2, vector<int>& output);

#endif