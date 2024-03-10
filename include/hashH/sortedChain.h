#ifndef _sortedChain_
#define _sortedChain_
#include "global.h"
using namespace std;

template <class K, class E>
struct pairNode
{
  pairNode() {}
  pairNode(const pair<const K, E> &thePair, pairNode<K, E> *theNext)
  {
    element.first = thePair.first;
    element.second = thePair.second;
    next = theNext;
  }
  pair<const K, E> element;
  pairNode<K, E> *next;
};

template <class K, class E>
class sortedChain
{
public:
  sortedChain();
  ~sortedChain();
  int size() const;
  pair<const K, E> *find(const K &theKey) const;
  void insert(const pair<const K, E> &thePair);
  void erase(const K &theKey);

private:
  pairNode<const K, E> *firstNode;
  int dSize;
};
#endif