#include "inputoutput.h"
#include <fstream>
#include <string>

/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
bool getContinue()
{
	return true;
}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
string getFileName()
{
	return "";
}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
int	getMinimumSupport(int totalTransactionCount)
{
	return 0;
}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
void initializeTransactionArray(bool **transactions, ArrayInfo2D &arrayInfo, int sizeI, int sizeJ)
{
	transactions = new bool*[sizeI];
	for (int i = 0; i < sizeI; i++)
	{
		transactions[i] = new bool[sizeJ];

		for (int j = 0; j < sizeJ; j++)
		{
			transactions[i][j] = false;
		}
	}

	arrayInfo.sizeI = sizeI;
	arrayInfo.sizeJ = sizeJ;
}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
bool loadData(bool **transactions, ArrayInfo2D &arrayInfo, const string &filename)
{
	ifstream fin;

	fin.open(filename);
	if (!fin.good())
		return false;

	int currentTransaction, currentItem;
	int numTransactions, numItems;

	//Determine the size of our array and initialize it
	parseFileName(numTransactions, numItems, filename);
	initializeTransactionArray(transactions, arrayInfo, numTransactions, numItems);

	//Actually load the data
	fin >> currentTransaction >> currentItem;
	while (!fin.eof())
	{
		transactions[currentTransaction][currentItem] = true;
		fin >> currentTransaction >> currentItem;
	}

	return true;
}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
void outputResults(double time, const Trie& largeItemsets)
{

}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
void parseFileName(int &transactions, int &items, const string &filename)
{
	//Values in title
	string transactionsStr = "";   //D value
	string itemsStr = "";          //N value

	//Track what to store from filename string
	bool readN = false;
	bool readD = false;

	for (int i = 0; i < filename.size(); i++)
	{
		if (toupper(filename[i]) == toupper('k'))
			readN = readD = false;

		if (readN)
			itemsStr += filename[i];
		else if (readD)
			transactionsStr += filename[i];

		if (toupper(filename[i]) == toupper('n'))
			readN = true;
		else if (toupper(filename[i]) == toupper('d'))
			readD = true;
	}

	transactions = static_cast<int>(stof(transactionsStr) * 1000);
	items = static_cast<int>(stof(itemsStr) * 1000);
}
