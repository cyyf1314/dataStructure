#include "global.h"
#include "linkedBinaryTree.h"
using namespace std;

int tolerance;
struct booster
{
  int degradeToLeaf,
      degradeFromParent;
  bool boosterHere;

  void output(ostream &out) const
  {
    out << boosterHere << " " << degradeFromParent << " " << degradeToLeaf << " ";
  }
};

ostream &operator<<(ostream &out, booster x)
{
  x.output(out);
  return out;
}

void placeBoosters(binaryTreeNode<booster> *x) // 配合后序遍历使用，充分利用递归的特性
{

  // 初始化x节点的衰减
  x->element.degradeToLeaf = 0;
  // 分左右子节点计算衰减量，同时计算x节点的degradeToLeaf值与记录需要放置放大器的节点
  binaryTreeNode<booster> *y = x->leftChild;
  if (y != NULL)
  {
    int degradation = y->element.degradeFromParent +
                      y->element.degradeToLeaf;
    if (degradation > tolerance)
    {
      y->element.boosterHere = true;
      x->element.degradeToLeaf = y->element.degradeFromParent;
    }
    else
    {
      x->element.degradeToLeaf = degradation;
    }
  }

  y = x->rightChild;
  if (y != NULL)
  {
    int degradation = y->element.degradeFromParent +
                      y->element.degradeToLeaf;
    if (degradation > tolerance)
    {
      y->element.boosterHere = true;
      degradation = y->element.degradeFromParent;
    }
    if (x->element.degradeToLeaf < degradation)
    {
      x->element.degradeToLeaf = degradation;
    }
  }
}