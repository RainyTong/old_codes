#include <iostream>
using namespace std;

struct Node{
  int coef;
  int expn;
  Node* next;
};
void initial(Node* &L){
  L = new Node;
  L->next = 0;
}

Node* addPoly(Node* head1,Node* head2){

  Node* head3 = new Node;

  Node* tail3 = head3;
  Node* ptr1 = head1;
  Node* ptr2 = head2;

  while(ptr1!=0&&ptr2!=0){
    if(ptr1->expn < ptr2->expn){

      tail3->coef = ptr1->coef;
      tail3->expn = ptr1->expn;
      //cout<<"("<<tail3->coef<<","<<tail3->expn<<")"<<endl;
      tail3->next = new Node;
      //cout<<"1";
      tail3 = tail3->next;
      //cout<<"2";
      ptr1 = ptr1->next;
      continue;
    }
    if(ptr2->expn < ptr1->expn){

      tail3->coef = ptr2->coef;
      tail3->expn = ptr2->expn;
      tail3->next = new Node;
      tail3 = tail3->next;
      ptr2 = ptr2->next;
      continue;
    }
    if(ptr1->expn == ptr2->expn){

      if(ptr1->coef + ptr2->coef != 0){

        tail3->coef = ptr1->coef + ptr2->coef;
        tail3->expn = ptr1->expn;
        tail3->next = new Node;
        tail3 = tail3->next;

      }

      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
      continue;
    }
  }

  Node* ptr;
  if(ptr1)
  ptr = ptr1;
  else
  ptr = ptr2;
  while(ptr){

    tail3->coef = ptr->coef;
    tail3->expn = ptr->expn;
    tail3->next = new Node;
    tail3 = tail3->next;
    ptr = ptr->next;

  }
  // if(ptr1==0&&ptr2==0){
  //   tail3=0;
  //   return head3;
  // }
  // if(ptr1==0){
  //   tail3 = ptr2;
  // }
  // if(ptr2==0){
  //   tail3 = ptr1;
  // }
  return head3;
}

int main(){
  int t = 0;
  cin>>t;
  int n,m;

  for(int num = 0;num < t;num++){
    cin>>n;
    Node* polyn;
    Node* polym;
    initial(polyn);
    initial(polym);
    Node* ptrToN = polyn;
    Node* ptrToM = polym;

    for(int i = 0;i < n;i++){
      cin>>polyn->coef;
      cin>>polyn->expn;
      if(i == n-1){
        polyn->next = 0;
        break;
      }else{
        polyn->next = new Node;
        polyn = polyn->next;
      }
    }
    cin>>m;
    for(int i = 0;i < m;i++){
      cin>>polym->coef;
      cin>>polym->expn;
      if(i == m-1){
        polym->next = 0;
        break;
      }else{
        polym->next = new Node;
        polym = polym->next;
      }
    }
    // while(ptrToN!=0){
    //
    //   cout<<ptrToN->coef;
    //   ptrToN=ptrToN->next;
    //
    //
    // }
    Node* sum = addPoly(ptrToN,ptrToM);



    Node* p = sum;
    while(p == 0){
      cout<<p->coef<<"x^"<<p->expn;
      p = p->next;
      if(p)
      cout<<"+";
    }

    cout<<endl;
  }
  return 0;
}
