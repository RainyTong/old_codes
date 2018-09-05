#include <iostream>
#include <string>
using namespace std;

typedef struct Node * Noder;

struct Node {

  char letter;
  Noder next;
  Noder front;

};

int main() {

  int t,n;
  string str;
  cin>>t;
  string printout;
  int length = 1;

  for(int num1 = 0;num1 < t;num1++) {

    cin>>str;
    Noder head = new Node;
    head->front = 0;
    Noder ptr = head;
    Noder tail = ptr;

    for(int i = 0; i < str.length(); i++) {

      char le = str.at(i);
      ptr->letter = le;

      if(i != str.length() - 1) {

        Noder temp = ptr;
        ptr->next = new Node;
        ptr = ptr->next;

        ptr->front = temp;
        length++;

      } else {

        ptr->next = 0;

      }

    }
    tail = ptr;
    ptr = head;

    cin>>n;

    for(int i = 0; i < n; i++) {

      int command;
      cin>>command;

      if(command == 1) {

        char le;
        int pos;
        cin>>le>>pos;
        length++;
        Noder t = tail;

        // for(int j = 0;j < pos-2 ;j++) {
        //   ptr = ptr->next;
        // }


        int midOfLength = length/2;

        if(pos <= midOfLength) {

          for(int j = 1; j < pos-1; j++) {

           ptr = ptr->next;

         }


        } else {

         for(int j = length; j > pos; j--) {
           t = t->front;

         }
         ptr = t;

        }

        if(pos == 1) {

          ptr = new Node;
          ptr->front = 0;
          ptr->letter = le;
          ptr->next = head;
          head->front = ptr;
          head = ptr;

        } else if (pos == length) {

          Noder temp = ptr->next;
          Noder temp1 = ptr;
          ptr->next = new Node;
          ptr = ptr->next;
          ptr->front = temp1;
          ptr->letter = le;
          ptr->next = temp;
          tail = ptr;
          ptr = head;

        } else {

        Noder temp = ptr->next;
        Noder temp1 = ptr;
        ptr->next = new Node;
        ptr = ptr->next;
        ptr->front = temp1;
        ptr->letter = le;
        ptr->next = temp;
        ptr->next->front = ptr;
        ptr = head;

      }

    } else {

      int pos;
      cin>>pos;
      Noder t = tail;
      // index = pos-1



      int midOfLength = length/2;

      if(pos <= midOfLength) {

        for(int j = 1; j < pos; j++) {

         ptr = ptr->next;

       }
       printout += ptr->letter;

     } else {

       for(int j = length; j > pos; j--) {
         t = t->front;
       }
       printout += t->letter;

     }


    //
    // for(int j = 0;j<pos-1;j++){
    //   ptr = ptr->next;
    // }
    // cout<<ptr->letter<<endl;

      ptr = head;

    }

  }

  for(int i = 0;i < printout.length();i++) {
    cout<<printout.at(i)<<endl;
  }
  }

}
