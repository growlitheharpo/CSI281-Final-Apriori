#include "inputoutput.h"
#include "apriori.h"
#include "timerSystem.h"

//Name this main once we're ready to start
int actualMain()
{
  TimerSystem timer;
  Trie largeItemsets;
  ArrayInfo2D transactionSizeInfo;
  bool **transactions = NULL;

  string filename = "";
  bool keepRunning = true;
  int minimumSupport = 0;
  double time;

  while (keepRunning)
  {
    filename = getFileName();

    if (!loadData(transactions, transactionSizeInfo, filename))
      continue;

    minimumSupport = getMinimumSupport(transactionSizeInfo.sizeJ);

    timer.startClock();
    runApriori(const_cast<const bool**>(transactions), transactionSizeInfo, minimumSupport, largeItemsets);
    time = timer.getTime();

    outputResults(time, largeItemsets);

    keepRunning = getContinue();
  }

  return 0;
}

int main()
{
  //bool keepRunning = getContinue();
  //cout << "Keep running is " << (keepRunning ? "true" : "false") << ".\n";


  Trie trie;

  DynamicArray<int> path;
  DynamicArray<DynamicArray<int>> allPaths;

  trie.addNode(path, 5);
  trie.addNode(path, 7);
  trie.addNode(path, 10);

  path.insert(5);
  trie.addNode(path, 4);
  trie.addNode(path, 3);
  trie.addNode(path, 2);
  trie.addNode(path, 1);


  trie.getAllPaths(allPaths);

  for (int i = 0; i < allPaths.count(); i++)
    allPaths[i].display();

  /*
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
  output.display();*/




  system("pause");
  return 0;
}