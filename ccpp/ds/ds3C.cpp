#include <iostream>
using namespace std;

typedef struct Node * Noder;

struct Node {
  int value;
  Noder next;
};

int main() {

  int t,n,m;
  cin>>t;

  for(int num1 = 0;num1 < t;num1++) {
    Noder list = new Node;
    Noder ptr = list;
    cin>>n;
    for(int i = 0;i < n;i++) {
      cin>>ptr->value;
      if(i == n-1) {
        ptr->next = 0;
        break;
      }else {
        ptr->next = new Node;
        ptr = ptr->next;
      }
    }
    cin>>m;
    for(int i = 0;i < m;i++) {
      int command;
      cin>>command;
      ptr = list;
      if(command == 1) {
        int x,y;
        cin>>x;
        cin>>y;

        for(int j = 0;j < x-1 ;j++) {
          ptr = ptr->next;
        }
        if(x == 0) {

          ptr = new Node;
          ptr->value = y;
          ptr->next = list;
          list = ptr;

        }else {

        Noder temp = ptr->next;
        ptr->next = new Node;
        ptr = ptr->next;
        ptr->value = y;
        ptr->next = temp;
        ptr = list;

      }

        while(ptr!=0){
          cout<<ptr->value;
          if(ptr->next!=0)
          cout<<" ";
          ptr = ptr->next;
        }
        cout<<endl;

      }else if(command == 2) {
        int x;
        cin>>x;

        for(int j = 0;j < x-1 ;j++) {
          ptr = ptr->next;
        }
        if(x == 0) {
        ptr = ptr->next;
        list = ptr;
        }else {
        ptr->next = ptr->next->next;
        ptr = list;
      }

        while(ptr!=0){
          cout<<ptr->value;
          if(ptr->next!=0)
          cout<<" ";
          ptr = ptr->next;
        }
        cout<<endl;

      }else if(command == 3) {
        int x,y;
        cin>>x;
        cin>>y;

        for(int j = 0;j < x ;j++) {
          ptr = ptr->next;
        }
        
        ptr->value = y;

        ptr = list;
        while(ptr!=0){
          cout<<ptr->value;
          if(ptr->next!=0)
          cout<<" ";
          ptr = ptr->next;
        }
        cout<<endl;


      }else {
      //
      //   Noder head;
      //   head = ptr;
      //   ptr = ptr->next;
      //   Noder temp;
      //   while(ptr!=0){
      //   temp = ptr->next;
      //   ptr->next = head;
      //   head = ptr;
      //   ptr = temp;
      // }
      // list = head;

      Noder p = ptr->next;
      Noder newHead = ptr;
      while(p!=NULL){
        ptr->next = p->next;
        p->next = newHead;
        newHead = p;
        p = ptr->next;
      }

      list = newHead;
      ptr = list;
      while(ptr!=0){
        cout<<ptr->value;
        if(ptr->next!=0)
        cout<<" ";
        ptr = ptr->next;
      }
      cout<<endl;


      }
    }

  }

  return 0;
}
