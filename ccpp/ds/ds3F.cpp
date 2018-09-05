#include <iostream>
#include <string>
using namespace std;

typedef struct Node * Noder;

struct Node {
  char letter;
  Noder next;
};

int main() {

  int t,n;
  cin>>t;

  for(int num1 = 0;num1 < t;num1++) {
    string str;
    cin>>str;
    cin>>n;
    string printStr = 0;
    for(int i = 0;i < n;i++) {
      int command;
      cin>>command;
      if(command == 1) {
        char* ch;
        int pos;
        cin>>ch;
        cin>>pos;
        str.insert(pos-1,ch);
      }else {
        int pos;
        cin>>pos;
        printStr+=str[pos-1];
        // printStr+='/n';
      }
    }
    cout<<printStr;
  }

}
