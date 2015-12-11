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

  trie.displayAllPaths();

  path.clear();
  path.push_back(1);
  trie.removeNode(path);
  path.push_back(2);
  path.push_back(5);
  trie.removeNode(path);

  path.clear();
  path.push_back(10);
  path.push_back(11);
  path.push_back(12);
  trie.removeNode(path);
  path.push_back(13);
  path.push_back(14);
  trie.removeNode(path);


  cout << endl;
  trie.displayAllPaths();

  system("pause");
  return 0;
}