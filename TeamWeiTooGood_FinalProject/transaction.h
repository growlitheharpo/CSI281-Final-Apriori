#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "base.h"

struct Transaction
{
	//variables
	int transactionId, itemId;

	//Functions
	Transaction()
	{
		this->transactionId = -1;
		this->itemId = -1;
	}

	Transaction(int transId, int itemId)
	{
		this->transactionId = transId;
		this->itemId = itemId;
	}
};

#endif