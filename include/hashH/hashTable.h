#ifndef _hashTable_
#define _hashTable_
#include "global.h"
using namespace std;

template <class T>
class stringToInt
{
public:
  size_t operator()(const string theKey)
  {
    unsigned long hashValue = 0;
    int length = (int)theKey.length();
    for (int i = 0; i < length; i++)
    {
      hashValue = 5 * hashValue + theKey.at(i);
    }
    return size_t(hashValue);
  }
};

template <class K, class E>
class hashTable
{
public:
  hashTable(int theDivisor);
  ~hashTable();

  int search(const K &theKey) const;
  pair<const K, E> *find(const K &theKey) const;
  void insert(const pair<const K, E> &thePair);
  void erase(const K &theKey);

private:
  pair<const K, E> **table;
  stringToInt<K> sti;
  int dSize;
  int divisor;
};
#endif