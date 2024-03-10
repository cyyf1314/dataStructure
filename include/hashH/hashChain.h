#ifndef _hashChain_
#define _hashChain_
#include "global.h"
#include "sortedChain.h"
#include "hashTable.h"
template <class K, class E>
class hashChain
{
public:
  hashChain(int theDivisor);
  ~hashChain();

  pair<const K, E> *find(const K &theKey) const;
  void insert(const pair<const K, E> &thePair);
  void erase(const K &theKey);

private:
  sortedChain<K, E> **table;
  stringToInt<K> sti;
  int dSize;
  int divisor;
};

#endif