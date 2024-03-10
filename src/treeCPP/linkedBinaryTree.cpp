#include "linkedBinaryTree.h"
#include <queue> //层次遍历中需要使用队列
template <class T>
void linkedBinaryTree<T>::preOrder(binaryTreeNode<T> *t)
{

  if (t != NULL)
  {

    linkedBinaryTree::visit(t);
    preOrder(t->leftChild);
    preOrder(t->rightChild);
  }
}

template <class T>
void linkedBinaryTree<T>::inOrder(binaryTreeNode<T> *t)
{

  if (t != NULL)
  {
    inOrder(t->leftChild);
    linkedBinaryTree::visit(t);

    inOrder(t->rightChild);
  }
}

template <class T>
void linkedBinaryTree<T>::postOrder(binaryTreeNode<T> *t)
{

  if (t != NULL)
  {

    postOrder(t->leftChild);
    postOrder(t->rightChild);
    linkedBinaryTree::visit(t);
  }
}

template <class T>
void linkedBinaryTree<T>::levelOrder(binaryTreeNode<T> *t) // 层次遍历原理：按照从左到右，先遍历根的值，再将左右子树根存储到顺序容器中，执行循环即可
{
  queue<binaryTreeNode<T> *> q;
  while (t != NULL)
  {
    linkedBinaryTree::visit(t); // 可以在存储时同时遍历
    if (t->leftChild)
    {
      q.push(t->leftChild);
    }
    if (t->rightChild)
    {
      q.push(t->rightChild);
    }

    // 提取下一个要访问的节点
    t = q.front();

    cout << " is empty" << endl;
    return;

    q.pop();
  }
}

template <class E>
int linkedBinaryTree<E>::height(binaryTreeNode<E> *t)
{
  if (t == NULL)
  {
    return 0;
  }
  int hl = height(t->leftChild);  // 充分利用递归的方法。为什么不用静态变量？因为在一个递归函数中，变量的生命周期是在一个函数结束的时间。而这里不能用
  int hr = height(t->rightChild); // 静态，因为这里的归过程中返回的都是hr(但代表左右的树高),如果用静态就实现不了这个功能

  if (hl > hr)
  {
    return ++hl;
  }
  else
  {
    return ++hr;
  }
}