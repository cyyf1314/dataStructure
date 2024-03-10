#ifndef _binaryTree_
#define _binaryTree_
#include "global.h"
using namespace std;

template <class T>
struct binaryTreeNode
{
  T element;
  binaryTreeNode<T> *leftChild, *rightChild;

  binaryTreeNode()
  {
    leftChild = rightChild = NULL;
  }
  binaryTreeNode(const T &theElement)
  {
    element = theElement;
    leftChild = rightChild = NULL;
  }
  binaryTreeNode(const T &theElement, binaryTreeNode<T> *theLeftChild, binaryTreeNode<T> *theRightChild)
  {
    element = theElement;
    leftChild = theLeftChild;
    rightChild = theRightChild;
  }
};

// abstrct class
template <class T>
class binaryTree
{
public:
  virtual ~binaryTree();
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual void preOrder(void (*)(T *)) = 0;
  virtual void inOrder(void (*)(T *)) = 0;
  virtual void postOrder(void (*)(T *)) = 0;
  virtual void levelOrder(void (*)(T *)) = 0;
};

#endif
