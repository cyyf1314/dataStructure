#ifndef _global_
#define _global_
#include <iostream>
#include <cstddef>
#include <string>
#include <algorithm>
using namespace std;
template <class T>
void changeLength1D(T *&a, int oldLength, int newLength) // 为什么用了指针变量又用引用？因为数组的数组名本身是一个指针变量，存储地址，如果只用指针变量，是不会对原始指针
{                                                        // 即实参修改，所以要用引用
  T *temp = new T[newLength];
  int number = min(oldLength, newLength);
  copy(a, a + number, temp);
  delete[] a;
  a = temp;
}

#endif