#include "hashTable.h"

template <class K, class E>
hashTable<K, E>::hashTable(int theDivisor)
{
  divisor = theDivisor;
  dSize = 0;
  table = new pair<const K, E> *[theDivisor];
  for (int i = 0; i < theDivisor; i++)
  {
    table[i] = NULL;
  }
}

template <class K, class E>
int hashTable<K, E>::search(const K &theKey) const
{
  // 对应函数，算出起始通
  int i = (int)sti(theKey) % divisor;
  int j = i;
  do
  {
    if (table[j] == NULL || table[j]->first == theKey)
    {
      return j;
    }
    j = (j + 1) % divisor; // 数学探究规律，要进行下一个并可以回到原来的数值，那么同样用取余的操作，并进行加一，数学规律

  } while (j != i);
  return j;
}

template <class K, class E>
pair<const K, E> *hashTable<K, E>::find(const K &theKey) const
{
  int b = search(theKey);
  if (table[b]->first == theKey)
  {
    return table[b];
  }
  return NULL;
}

template <class K, class E>
void hashTable<K, E>::insert(const pair<const K, E> &thePair)
{
  int b = search(thePair.first);

  if (table[b] == NULL)
  {
    table[b] = new pair<const K, E>(thePair);
    dSize++;
  }
  else
  {
    if (table[b].first == thePair.first)
    {
      table[b].second = thePair.second;
    }
    else
    {
      throw "hashTable have fulled";
    }
  }
}

template <class K, class E>
void hashTable<K, E>::erase(const K &theKey)
{
  int b = search(theKey);
  if (table[b] == NULL)
  {
    throw " not exists";
  }
  else
  {
    delete table[b];
    dSize--;
  }
}