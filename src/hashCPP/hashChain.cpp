#include "hashChain.h"

template <class K, class E>
hashChain<K, E>::hashChain(int theDivisor)
{
  divisor = theDivisor;
  dSize = 0;
  table = new sortedChain<K, E>[theDivisor];
  for (int i = 0; i < theDivisor; i++)
  {
    table[i] = NULL;
  }
}

template <class K, class E>
pair<const K, E> *hashChain<K, E>::find(const K &theKey) const
{
  return table[sti(theKey) % divisor].find(theKey);
}

template <class K, class E>
void hashChain<K, E>::insert(const pair<const K, E> &thePair)
{
  int b = (int)sti(thePair.first) % divisor;
  int n_size = table[b].size(); // 因为sortedChain中insert方法会有关键字已存在的情况，所以用insert方法时要区别开
  table[b].insert(thePair);
  if (table[b].size() > n_size)
  {
    dSize++;
  }
}

template <class K, class E>
void hashChain<K, E>::erase(const K &theKey)
{
  table[sti(theKey) % divisor].erase(theKey);
}