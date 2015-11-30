#include <iostream>
#include <Windows.h>
#include "transaction.h"

int main()
{
	/*
	using namespace std;

	cout << "Apriori: ";

	for (int i = 0; i < 10; i++)
	{
		Sleep(250);
		cout << ".";
	}

	cout << "\nDone!" << endl;

	system("pause");
	return 0;
	*/

	int counter = 0;

	Transaction** myArrayOfTransactions = new Transaction*[100000];

	system("pause");

	delete[] myArrayOfTransactions;
	++counter;

	system("pause");
	return 0;
}