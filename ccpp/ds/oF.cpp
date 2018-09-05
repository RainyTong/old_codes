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
  string str;
  cin>>t;

  for(int num1 = 0;num1 < t;num1++) {

    cin>>str;
    Noder head = new Node;
    Noder ptr = head;

    for(int i = 0; i < str.length(); i++) {

      char le = str.at(i);
      ptr->letter = le;

      if(i != str.length() - 1) {

        ptr->next = new Node;
        ptr = ptr->next;

      } else {

        ptr->next = 0;

      }

    }

    ptr = head;

    cin>>n;

    for(int i = 0; i < n; i++) {

      int command;
      cin>>command;

      if(command == 1) {

        char le;
        int pos;
        cin>>le>>pos;

        for(int j = 0;j < pos-2 ;j++) {
          ptr = ptr->next;
        }
        if(pos == 1) {

          ptr = new Node;
          ptr->letter = le;
          ptr->next = head;
          head = ptr;

        }else {

        Noder temp = ptr->next;
        ptr->next = new Node;
        ptr = ptr->next;
        ptr->letter = le;
        ptr->next = temp;
        ptr = head;

      }

    } else {

      int pos;
      cin>>pos;
      // index = pos-1
      for(int j = 1; j < pos; j++) {

        ptr = ptr->next;

      }
      cout<<ptr->letter<<endl;
      ptr = head;

    }

  }


  }

}
