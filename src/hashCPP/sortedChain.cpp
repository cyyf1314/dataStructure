#include "sortedChain.h"
using namespace std;
template <class K, class E>
sortedChain<K, E>::sortedChain()
{
  size = 0;
  firstNode = NULL;
}

template <class K, class E>
int sortedChain<K, E>::size() const
{
  return dSize;
}

template <class K, class E>
pair<const K, E> *sortedChain<K, E>::find(const K &theKey) const
{
  pairNode<const K, E> *currentNode = firstNode;
  while (currentNode != NULL && currentNode->next.first != theKey)
  {
    currentNode = currentNode->next;
  }
  if (currentNode->element.first != theKey)
  {
    return NULL;
  }
  return &currentNode->element;
}

template <class K, class E>
void sortedChain<K, E>::insert(const pair<const K, E> &thePair)
{
  pairNode<const K, E> *p = firstNode, *lp = NULL; // 有三种情况，链表为空，关键字以存在或不存在，不存在情况下需要有变量记录最后一个节点，因此引入lp
  while (p != NULL && p->element.first != thePair.first)
  {
    lp = p; // 之后一个节点
    p = p->next;
  }
  if (p != NULL && p->element.first == thePair.first)
  {
    p->element.second != thePair.second;
    return;
  }

  pair<const K, E> *newNode = new pair<const K, E>(thePair, p);
  if (lp == NULL) // 这段if-else语句，将为空，只有一个节点，或有很多节点的情况都包含了，充分利用了lp与p的关系
  {
    firstNode = newNode;
  }
  else
  {
    lp->next = newNode;
  }
  size++;
}

template <class K, class E>
void sortedChain<K, E>::erase(const K &theKey)
{
  pairNode<const K, E> *p = firstNode, *lp = NULL; // 有三种情况，为第一个节点，关键字以存在,关键字不存在或链表为空
  while (p != NULL && p->element.first != theKey)
  {
    lp = p; // 之后一个节点
    p = p->next;
  }
  if (p != NULL && p->element.first == theKey)
  {
    if (lp == NULL)
    {
      firstNode = p->next;
    }
    else
    {
      lp->next = p->next;
    }
    delete p;
    size--;
  }
  else
  {
    throw "list is null";
  }
}