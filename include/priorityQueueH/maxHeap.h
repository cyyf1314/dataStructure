#ifndef _maxHeap_
#define _maxHeap_
#include "maxPriorityQueue.h"
#include "global.h"
using namespace std;
template <class T>
class maxHeap : public maxPriorityQueue<T>
{
public:
  maxHeap();
  maxHeap(int length);
  ~maxHeap() {}
  virtual bool empty() const;
  virtual int size() const;
  virtual const T &top();
  virtual void pop();
  virtual void push(const T &theElement);

  void initialize(T *theHeap, int theSize);

private:
  T *heap; // 将数据看成层级结构，这将非常有趣
  int arrayLength;
  int heapSize;
};

#endif