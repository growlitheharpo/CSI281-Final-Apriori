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

int main()
{
  //bool keepRunning = getContinue();
  //cout << "Keep running is " << (keepRunning ? "true" : "false") << ".\n";


  Trie trie;

  vector<int> path;
  vector<vector<int>> allPaths;
  vector<vector<int>> allPathsDepth;

  path.push_back(1);
  trie.addNode(path);
  path.push_back(2);
  trie.addNode(path);
  path.push_back(3);
  trie.addNode(path);

  path.pop_back();
  path.push_back(4);
  trie.addNode(path);

  path.pop_back();
  path.push_back(5);
  trie.addNode(path);



  path.clear();
  path.push_back(10);
  trie.addNode(path);
  path.push_back(11);
  trie.addNode(path);
  path.push_back(12);
  trie.addNode(path);
  path.push_back(13);
  trie.addNode(path);
  path.push_back(14);
  trie.addNode(path);

  path.pop_back();
  path.push_back(15);
  trie.addNode(path);

  //trie.getAllPathsAtDepth(allPathsDepth, 2);

  trie.getAllPaths(allPaths);

  for (int i = 0; i < allPaths.size(); i++)
  {
    for (int j = 0; j < allPaths[i].size(); j++)
    {
      cout << allPaths[i][j] << " ";
    }
    cout << endl;
  }

  cout << "\ndepth 2\n";
  for (int i = 0; i < allPathsDepth.size(); i++)
  {
    for (int j = 0; j < allPathsDepth[i].size(); j++)
    {
      cout << allPathsDepth[i][j] << " ";
    }
    cout << endl;
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