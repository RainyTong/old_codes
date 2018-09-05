#include <iostream>
using namespace std;

//常函数的特点：可以使用数据成员，不能修改数据成员

class CStu
{

public:
  int a;

  CStu()
  {
    a = 12;
  }//constructor

  ~CStu()
  {

  }//destructor

  void show() const
  {
    //a = 13;不允许
    cout << "show" << endl;
  }

};

int main()
{
  //常对象只能调用常函数，不能调用普通函数
  const CStu stu;
  stu.show();

  return 0;
}
