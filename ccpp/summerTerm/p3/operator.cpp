#include <iostream>
using namespace std;

class CStu{
private:
  int nAge;

public:

  CStu(int age){
  nAge = age;
  }
friend ostream& operator << (ostream& os, const CStu& st);
};

ostream& operator << (ostream& os, const CStu& st){

  os << st.nAge;
  return os;
}

int main(){

  CStu st1(12);
  CStu st2(13);
  cout << st1 << st2;

  return 0;
}
