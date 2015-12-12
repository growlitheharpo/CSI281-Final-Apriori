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