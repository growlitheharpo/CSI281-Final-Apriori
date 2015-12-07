#ifndef APRIORI_H
#define APRIORI_H

#include "basefunctions.h"
#include "trie.h"

void addCandidatesToLTree(Trie& candidates, Trie& largeItemsets, int depth);
void calcCandidateSupport(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie&  candidates, int depth);
void calculate1Itemsets(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie& largeItemsets);
void candidateGen(const Trie& largeItemsets, Trie& candidateItemsets, int depth);
void runApriori(const bool **transactions, const ArrayInfo2D& arrInfo, int minSupport, Trie& largeItemsets);
bool pruneCandidates(Trie& candidates, int depth);

#endif