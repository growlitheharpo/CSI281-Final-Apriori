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
#ifndef APRIORI_RESULT_H
#define APRIORI_RESULT_H

struct AprioriResult
{
	int mDepth, mNumOfItemsetsAtThisDepth;
	double mTimeForThisDepth;

	AprioriResult()
	{
		mDepth = 0;
		mNumOfItemsetsAtThisDepth = 0;
		mTimeForThisDepth = 0.0;
	}

	AprioriResult(int depth, int numOfSets, double time)
	{
		this->mDepth = depth;
		this->mNumOfItemsetsAtThisDepth = numOfSets;
		this->mTimeForThisDepth = time;
	}
};

#endif