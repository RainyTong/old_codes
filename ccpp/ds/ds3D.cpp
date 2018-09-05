#include <iostream>
using namespace std;

typedef struct Node * Noder;

struct Node {
  int index;
  Noder next;
};

int main() {

  int t,n,k;
  cin>>t;
  for(int num1 = 0;num1 < t;num1++) {
    cin>>n;
    cin>>k;
    Noder head = new Node;
    Noder ptr = head;
    head->index = 0;
    int in = 0;
    for(int i = 1;i < n;i++) {
      ptr->next = new Node;
      ptr = ptr->next;
      in++;
      ptr->index = in;
    }
    ptr->next = head;
    ptr = head;
    while(ptr->next != ptr) {


    for(int i = 0;i < k-1;i++){
      ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
    ptr = ptr->next;

  }
  cout<<ptr->index<<endl;
  }
}
