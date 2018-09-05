#include <iostream>
using namespace std;

class CStu
{
public:
  static int a; //1.静态成员 类外初始化
  static const int b = 13;
  //2.静态常量整型成员可以在类内初始化

  CStu()//:a(2)不允许
  {
    a = 12;//赋值是可以的
  }
};

int CStu::a = 13; //静态成员的类外初始化


int main()
{
  //3.静态成员/静态函数的调用
  //法一：直接类名作用域
  cout << CStu::a << endl; //输出13，因为没有创建对象，
                           //就没有调用constructor
  CStu st;
  cout << st.a << endl; //输出12，调用constructor重新赋值

  //4.static受访问修饰符的限制
  //5.静态成员没有this指针
  //6.静态函数不能引用数据成员，因为只有对象创建时数据成员才存在，
  //而静态函数和静态成员一直存在


  return 0;
}
