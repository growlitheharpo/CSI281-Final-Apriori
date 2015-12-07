//#include "inputoutput.h"
//#include "apriori.h"
#include "inputoutput.h"
#include "dynamicarray.h"

int main()
{
	bool keepRunning = getContinue();

	cout << "Keep running is " << (keepRunning ? "true" : "false") << ".\n";

	DynamicArray<int> myArray(5), myArray2(5);

	myArray.insert(5);
	myArray.insert(6);
	myArray.insert(7);
	myArray.insert(8);
	myArray2.insert(5);
	myArray2.insert(6);
	myArray2.insert(7);
	myArray2.insert(8);

	cout << "myArray == myArray2 is " << ((myArray == myArray2) ? "true" : "false") << endl;

	for (int i = 0; i < myArray.count(); i++)
		cout << myArray[i] << " ";
	cout << endl;

	for (int i = 0; i < myArray.count(); i++)
		myArray[i] = 2;

	for (int i = 0; i < myArray.count(); i++)
		cout << myArray[i] << " ";
	cout << endl;

	cout << "myArray == myArray2 is " << ((myArray == myArray2) ? "true" : "false") << endl;

	system("pause");
	return 0;
}