#include <iostream>
#include "global.h"
#include "linkedBinaryTree.h"
using namespace std;

void (*print)(int *);

void p(int *a)
{
  cout << *a << endl;
}

int main()
{

  int a = 1;

  int *c = &a;

  print = p;
  print(c);
  system("pause");
  return 0;
}