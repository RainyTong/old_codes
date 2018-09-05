#include <iostream>
using namespace std;

class CPeople
{
public:
  int a;
  void fun()
  {
    cout << "fun" << a << endl;
  }
};

int main()
{
  //声明对象的两个方法
  //1.栈区的对象变量
  CPeople op;
  op.a = 12;
  op.fun();

  //2.指针变量(堆区)
  CPeople* op1 = new CPeople;
  op1->a = 14;
  op1->fun();

  delete op1;
  return 0;
}
