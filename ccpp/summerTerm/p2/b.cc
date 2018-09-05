#include <iostream>
using namespace std;

int main()
{
  //变量起别名

  //1.基本数据类型的引用：
  int a = 11;
  int &c = a; //声明变量a的一个引用c，c是a的一个别名
  int &d = a;
  int &e = c;

  //注：声明引用的时候就要初始化：int &d;是不允许的

  //2.常量的引用：12 12.23 ‘q’
  const int &f = 12;
  //f = 13;是不允许的，常量的引用不可更改

  //3.数组的引用：
  //一维数组：
  int arr1[12];
  int (&g)[12] = arr1; //引用 类型
  g[2] = 13;
  cout << arr1[2] << endl;

  //二维数组：
  int arr2[2][3]; 
  int (&h)[2][3] = arr2;

  //4.指针的引用：
  int b =14;
  int* p = &b;
  int* (&ptr) = p;

  return 0;
}
