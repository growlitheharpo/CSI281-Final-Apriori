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

#include <iostream>
#include <vector>

int main()
{
  //bool keepRunning = getContinue();
  //cout << "Keep running is " << (keepRunning ? "true" : "false") << ".\n";


  Trie trie;

  vector<int> path;
  vector<vector<int>> allPaths;

  path.push_back(5);
  trie.addNode(path);

  path.clear();
  path.push_back(7);
  trie.addNode(path);

  path.push_back(8);
  trie.addNode(path);

  trie.getAllPaths(allPaths);

  for (int i = 0; i < allPaths.size(); i++)
  {
    for (int j = 0; j < allPaths[i].size(); j++)
    {
      cout << allPaths[i][j];
    }
  }
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