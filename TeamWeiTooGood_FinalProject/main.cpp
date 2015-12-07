//#include "inputoutput.h"
//#include "apriori.h"
#include "inputoutput.h"
#include "dynamicarray.h"

int main()
{
	bool keepRunning = getContinue();

	cout << "Keep running is " << (keepRunning ? "true" : "false") << ".\n";

  Trie trie;
  DynamicArray<int> path;

  trie.addNode(path, 5);



  system("pause");
	return 0;
}