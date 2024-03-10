#ifndef _linkedBinaryTree_
#define _linkedBinaryTree_
#include "binaryTree.h"
template <class E>
class linkedBinaryTree : public binaryTree<binaryTreeNode<E>>
{
public:
  linkedBinaryTree(){root=NULL;
  
  treeSize=0;}
  ~linkedBinaryTree(){erase();}

  virtual bool empty() const {return treeSize==0;}
  virtual int size()const{return treeSize;}
  virtual void preOrder(void (*theList)(binaryTreeNode<E>*)) {
    visit=theList;
    preOrder(root);
  }
  virtual void inOrder(void (*theList)(binaryTreeNode<E> *)) {
    visit=theList;
    inOrder(root);
  }
  virtual void postOrder(void (*theList)(binaryTreeNode<E> *)) {
    visit=theList;
    postOrder(root);
  }
  virtual void levelOrder(void (*theList)(binaryTreeNode<E> *)) {
    visit=theList;
    levelOrder(root);
  }
  void erase(){
    preOrder(dispose);//为什么调用后序遍历？因为得先存储节点中的指针域，才能删除，后序的函数操作是最后才执行，所以符合
    root=NULL;
    treeSize=0;
  }
  void preOrderOutput(){
    preOrder(output);
    cout<<endl;
  }

  int height(){return height(root);}
  int height(binaryTreeNode<E>*t);


private:
  binaryTreeNode<E> *root;
  int treeSize;

  // 与递归和单例模式有关
  static void (*visit)(binaryTreeNode<E> *); // 函数指针可以使用占位参数，但实现函数必须要相同类型且有形参
  static void preOrder(binaryTreeNode<E> *t);
  static void inOrder(binaryTreeNode<E> *t);
  static void postOrder(binaryTreeNode<E> *t);
  static void levelOrder(binaryTreeNode<E> *t);
  static void dispose(binaryTreeNode<E> *t) { delete t; }
  static void output(binaryTreeNode<E>*t){cout<<t->element<<" ";}
};

#endif



