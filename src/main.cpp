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
  cout << ++a << endl;
  cout << a++ << endl;

  int b = 1;

  int *c = &b;

  print = p;

  system("pause");
  return 0;
}