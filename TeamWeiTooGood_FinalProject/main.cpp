//#include "inputoutput.h"
//#include "apriori.h"
#include "inputoutput.h"
#include "dynamicarray.h"
#include "apriori.h"

int main()
{
	//bool keepRunning = getContinue();
	//cout << "Keep running is " << (keepRunning ? "true" : "false") << ".\n";

	/*
	Trie trie;
	DynamicArray<int> path;

	trie.addNode(path, 5);*/

	DynamicArray<int> array1, array2, output;

	array1.insert(2);
	array1.insert(3);
	array1.insert(4);

	array2.insert(2);
	array2.insert(3);
	array2.insert(5);


	array1.display();
	array2.display();
	
	unionTwoArrays(array1, array2, output);


	array1.display();
	array2.display();
	output.display();

	system("pause");
	return 0;
}