#include "inputoutput.h"
#include <fstream>
#include <string>

/*********************************************************************************************
* Purpose: Determine if the user would like to continue.
*     Pre: None
*	 Post: Returns true if the user enters yes to continue, false otherwise.
*********************************************************************************************/
bool getContinue()
{
	string input;

	do
	{
		cout << "Continue? (Y/N): ";
		getline(cin, input);

		if (input.length() > 1 || (tolower(input[0]) != 'y' && tolower(input[0]) != 'n'))
			continue;
		else if (tolower(input[0]) == 'y')
			return true;
		else
			return false;

	} while (true);
}


/*********************************************************************************************
* Purpose: Get the filename from the user
*     Pre: None
*	 Post: Returns the name of the transaction file that the user entered (no validation)
*********************************************************************************************/
string getFileName()
{
	string filename;

	cout << "Enter the name of the transaction file: ";
	getline(cin, filename);

	return filename;
}


/*********************************************************************************************
* Purpose: Get the value of minimum support from the user
*     Pre: Have the total number of transactions in this itemset.
*	 Post: Returns the minimum number of items necessary
*********************************************************************************************/
int	getMinimumSupport(int totalTransactionCount)
{
	cout << "Enter the desired transactions for minimum support.\n"
		<< "This can either be an exact number of transactions, \n"
		<< "or a percentage of all transactions if you begin with\n"
		<< "a % sign.\n";
	
	string input;
	int support = -1;
	bool enteredPercent, valid;

	do
	{
		enteredPercent = false;
		valid = true;

		cout << "Enter minimum support: ";
		getline(cin, input);

		if (input[0] == '%')
		{
			enteredPercent = true;
			input.erase(0, 1);
		}

		for (size_t i = 0; i < input.size() && valid; i++)
		{
			if (input[i] < '0' || input[i] > '9')
				valid = false;
		}

		if (valid)
			support = (enteredPercent) ? (stoi(input) * static_cast<int>(0.01 * totalTransactionCount)) : stoi(input);

	} while (support < 0 || support > totalTransactionCount);

	return support;
}


/*********************************************************************************************
* Purpose: Initialize the array of transactions with the proper size, and "false" values
*     Pre: Handed the transaction pointer, the array info, and the sizes.
*	 Post: Transactions is initializes and arrayInfo is set to proper values.
*********************************************************************************************/
void initializeTransactionArray(bool** &transactions, ArrayInfo2D &arrayInfo, int sizeI, int sizeJ)
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
* Purpose: Load the transaction data from the disk.
*     Pre: The necessary variables are declared, and filename is initialized.
*	 Post: Returns true if the file could be opened, otherwise false.
*********************************************************************************************/
bool loadData(bool** &transactions, ArrayInfo2D &arrayInfo, const string &filename)
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

	--currentTransaction;
	--currentItem;
	while (!fin.eof())
	{
		transactions[currentTransaction][currentItem] = true;
		fin >> currentTransaction >> currentItem;

		--currentTransaction;
		--currentItem;
	}

	return true;
}


/*********************************************************************************************
* Purpose: Output the results of apriori to the console.
*     Pre: largeItemsets is properly determined, and time is calculated.
*	 Post: Information is outputed.
*********************************************************************************************/
void outputResults(double time, const Trie& largeItemsets)
{
	DynamicArray<DynamicArray<int>> itemsets;
	largeItemsets.getAllPaths(itemsets);

	for (int i = 0; i < itemsets.count(); i++)
	{
		//ex: "Set 1: 4 5
		//	   Set 2: 4 7"
		cout << "Set " << i + 1 << ": ";
		itemsets[i].display();
	}

	cout << "All sets found in " << time << " seconds.";
}


/*********************************************************************************************
* Purpose: Turn a filename into the number of items and transactions.
*     Pre: Handed the filename, and references to transactions and items.
*	 Post: Transactions and items are updated to the correct value.
*********************************************************************************************/
void parseFileName(int &transactions, int &items, const string &filename)
{
	//Values in title
	string transactionsStr = "";   //D value
	string itemsStr = "";          //N value

	//Track what to store from filename string
	bool readN = false;
	bool readD = false;

	for (size_t i = 0; i < filename.size(); i++)
	{
		if (toupper(filename[i]) == toupper('k'))
			readN = readD = false;

		if (readN)
			itemsStr += filename[i];
		else if (readD)
			transactionsStr += filename[i];

		if ((filename[i]) == toupper('n'))
			readN = true;
		else if ((filename[i]) == toupper('d'))
			readD = true;
	}

	transactions = static_cast<int>(stof(transactionsStr) * 1000);
	items = static_cast<int>(stof(itemsStr) * 1000);
}
