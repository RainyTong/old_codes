#include <iostream>
using namespace std;
/*拷贝构造
1.形式
2.何时调用：
（1）新建一个对象，并将其初始化为同类现有对象
 (2)函数参数传递对象
（3）函数返回值返回对象
3. 有何功能：
默认的拷贝构造（浅拷贝），逐个复制非静态成员的值
（4.深拷贝）
*/

class CStu{
public:
  CStu()
  {

  }

  CStu(const CStu &a)//拷贝构造，对象创建时调用
  {

  }
};

int main()
{
  CStu st1;
  CStu stNew(st1);
  //CStu stNew = st1;
  //CStu stNew = CStu(st1);//临时对象
  //CStu* stNew = new CStu(st1);


  return 0;

}
