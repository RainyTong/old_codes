#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isNumber(char s) {
    string opers = "^";
    for (int i = 0; i < opers.length(); i++) {
        if (s == opers.at(i)) {
            return false;
        }
    }
    return true;
}

int main() {

  string infix;
  cin>>infix;
  string postfix;
  int num = 0;
  for(int i = 0;i < infix.length();i++) {
    if(isNumber(infix.at(i))) {
      postfix += infix.at(i);
    }
    if(infix.at(i) == '^') {
      num++;
    }
  }

  cout<<postfix;
  for(int i = 0;i < num;i++) {
    cout<<'^';
  }
  cout<<endl;
  return 0;

}
