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