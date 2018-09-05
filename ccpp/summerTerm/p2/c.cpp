#include <iostream>
using namespace std;

void fun(int &a)
{
  a = 14;
  cout << a << endl; //14
}

int main()
{

  int b =12;
  fun(b); //用b给a做初始化，a是b的一个引用
          //a与b指向同一块空间

  cout << b << endl; //14

  return 0;
}
