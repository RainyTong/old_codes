#include <iostream>
using namespace std;

typedef struct Node * Noder;

struct Node {
  long coef;
  long expn;
  Noder next;
};

Noder add(Noder a, Noder b) {

  Noder result = new Node;

  Noder ptrR = result;
  Noder ptrA = a;
  Noder ptrB = b;
  while(true){
    if(ptrA->expn < ptrB->expn){
      ptrR->expn = ptrA->expn;
      ptrR->coef = ptrA->coef;
      ptrR->next = new Node;

      ptrA = ptrA->next;
      if(ptrA==0||ptrB==0)
        break;
        else
        {
            ptrR=ptrR->next;
            continue;
        }
    }
    if(ptrB->expn < ptrA->expn){
      ptrR->expn = ptrB->expn;
      ptrR->coef = ptrB->coef;
      ptrR->next = new Node;

      ptrB = ptrB->next;
      if(ptrA==0||ptrB==0)
        break;
        else
        {
            ptrR=ptrR->next;
            continue;
        }
    }
    if(ptrB->expn == ptrA->expn){
      long co = ptrA->coef + ptrB->coef;

      ptrR->expn = ptrA->expn;
      ptrR->coef = co;
      ptrR->next = new Node;
      ptrA = ptrA->next;
      ptrB = ptrB->next;
      if(ptrA==0||ptrB==0)
        break;
        else{
            ptrR=ptrR->next;
            continue;
        }


    }
  }
  if(ptrA == 0 && ptrB == 0){
    ptrR->next = 0;
  }else if(ptrA == 0){
    ptrR->next = ptrB;
  }else if(ptrB == 0){
    ptrR->next = ptrA;
  }
  return result;
  }



Noder multiPoly(Noder head1, Noder head2, long m) {

  Noder head3 = new Node;

  Noder p1 = head1;
  Noder p2 = head2;
  Noder p3 = head3;

  while(p2) {

    long co = (p1->coef) * (p2->coef);
    long ex = (p1->expn) + (p2->expn);
    p3->coef = co;
    p3->expn = ex;
    p2 = p2->next;

  if(p2 == 0) {
      p3 -> next = 0;
    }else {
      p3->next = new Node;
      p3 = p3->next;
    }

  }


  p1 = p1->next;
  p3 = head3;

  while(p1 != 0) {

  p2 = head2;

  Noder head4 = new Node;
  Noder p4 = head4;

  while(p2) {

        long co = (p1->coef) * (p2->coef);
        long ex = (p1->expn) + (p2->expn);
        p4->coef = co;
        p4->expn = ex;
        p2 = p2->next;

      if(p2 == 0) {
          p4 -> next = 0;
        }else {
          p4->next = new Node;
          p4 = p4->next;
        }

  }

  p1 = p1->next;
  p4 = head4;

  p3 = add(p3,p4);
}

head3 = p3;
return head3;

}

void print(Noder re) {


    while(re!=0){

        if(re->expn == 0){

        if(re->next == 0){
          cout<<re->coef;

          break;
        }else{
          cout<<re->coef;
          re = re->next;
          if(re->coef>0){
            cout<<"+";
          }

          continue;
        }

      }else{

        if(re->coef == 1){

          if(re->expn == 1){
            if(re->next == 0){
              cout<<"x";

              break;
            }else{
              cout<<"x";
              re = re->next;
              if(re->coef>0){
                cout<<"+";
              }

              continue;
            }
          }else{
            if(re->next == 0){
              cout<<"x^"<<re->expn;

              break;
            }else{
              cout<<"x^"<<re->expn;
              re = re->next;
              if(re->coef>0){
                cout<<"+";
              }

              continue;
            }
        }

      }else{

      if(re->expn == 1){
        if(re->next == 0){
          cout<<re->coef<<"x";

          break;
        }else{
          cout<<re->coef<<"x";
          re = re->next;
          if(re->coef>0){
            cout<<"+";
          }

          continue;
        }
      }else{
        if(re->next == 0){
          cout<<re->coef<<"x^"<<re->expn;

          break;
        }else{
          cout<<re->coef<<"x^"<<re->expn;
          re = re->next;
          if(re->coef>0){
            cout<<"+";
          }

          continue;
        }
    }

    }
    }

  }//while


  cout<<endl;
  }



int main() {

  int t = 0;
  cin>>t;
  int n,m;

  for(int num = 0;num < t;num++){

    cin>>n;

    Noder polyn = new Node;
    Noder polym = new Node;

    Noder ptrToN = polyn;
    Noder ptrToM = polym;

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

    Noder result = multiPoly(ptrToM,ptrToN,m);
    print(result);


  }

    return 0;
}
