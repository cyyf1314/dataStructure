#include "maxHeap.h"

template <class T>
maxHeap<T>::maxHeap(int length) // 模版类中的成员函数不能用默认参数
{
  arrayLength = length;
  heap = new T[arrayLength];
  heapSize = 0;
}

template <class T>
void maxHeap<T>::push(const T &theElement)
{
  if (heapSize == arrayLength - 1)
  {
    changeLength1D(heap, arrayLength, 2 * arrayLength);
    arrayLength *= 2;
  }

  int currentNode = ++heapSize;
  while (currentNode != 1 && heap[currentNode / 2] < theElement) // 与根节点进行比较，若大于，则向上层移动。这里利用c++中除法/只保留整数位的特性
  {
    heap[currentNode] = heap[currentNode / 2];
    currentNode = currentNode / 2;
  }
  heap[currentNode] = theElement;
}

template <class T>
void maxHeap<T>::pop()
{
  if (heapSize == 0)
  {
    throw "queue is empty";
  }

  // 记录最后一个元素，为最后一个元素寻找合适的节点，是由删除头元素引起的的位置前进
  T lastElement = heap[heapSize - 1];

  copy(heap + 1, heap + heapSize, heap);
  heapSize--;
  // 从根开始，为最后一个元素寻找位置，同时调整其他节点的位置。关键在于移层和左右子节点以及根节点的比较
  int currentNode = 1,
      child = 2; // 将原先根的左右孩子进行比较
  while (child<=heapSize)
  {
    if (child < heapSize && heap[child] < heap[child + 1]) // 考虑元素只有一个或两个的情况
    {
      child++;
    }
    if (lastElement >= heap[child])
    {
      break;
    }
    heap[currentNode] = heap[child]; // 此时，相当于child位置为空
    currentNode = child;
    child *= 2; // 向下层移动
  }
  heap[currentNode] = lastElement;
}

template <class T>
const T &maxHeap<T>::top()
{
  return heap[0];
}

template <class T>
void maxHeap<T>::initialize(T *theHeap, int theSize) // 利用二叉树的性质，一根两子的特点，可以从中间节点开始作为子节点进行检索。
{
  delete[] heap;
  heap = theHeap;
  heapSize = theSize;

  for (int root = heapSize / 2; root <= 1; root--) // 以根节点为基点，向下检索
  {
    T rootElement = heap[root];

    int child = root * 2;

    while (child <= heapSize)
    {
      if (child < heapSize && heap[child] < heap[child] + 1)
      {
        child++;
      }
      if (rootElement >= heap[child])
      {
        break;
      }
      heap[child / 2] = heap[child];
      child *= 2;
    }
    heap[child / 2] = rootElement;
  }
}