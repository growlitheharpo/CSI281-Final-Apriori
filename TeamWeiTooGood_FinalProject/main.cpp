//#include "inputoutput.h"
//#include "apriori.h"
#include "inputoutput.h"
#include "dynamicarray.h"

int main()
{
	bool keepRunning = getContinue();

	cout << "Keep running is " << (keepRunning ? "true" : "false") << ".\n";

	DynamicArray<int> myArray(5);

	myArray.insert(5);
	myArray.insert(6);
	myArray.insert(7);
	myArray.insert(8);

	for (int i = 0; i < myArray.count(); i++)
		cout << myArray[i] << " ";
	cout << endl;

	for (int i = 0; i < myArray.count(); i++)
		myArray[i] = 2;

	for (int i = 0; i < myArray.count(); i++)
		cout << myArray[i] << " ";
	cout << endl;


	system("pause");
	return 0;
}