#include <iostream>
using namespace std;

int main() {
  //int* p1 = (int*)malloc(sizeof(int)); ----c
  int* p1 = new int(121);//空间的申请（可以直接对它初始化）

  //int* p2 = (int*)malloc(5*sizeof(int)); ----c
  int* p2 = new int[5];//数组空间的申请
  p2[0] = 1;
  p2[1] = 2;

  int* p3 = new int[3];//数组没有初始化的方式
  memset(p3,0,5*4);//memory set:给数组赋一个相同的值

  *p1 = 12;//空间的写
  cout << *p1 <<endl; //空间的读
  cout << p2[0] << " " << p2[1] << endl;

  delete p1;//空间的释放
  delete[] p2;

  return 0;
}
