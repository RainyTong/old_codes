#include <iostream>
using namespace std;

typedef struct Node * Noder;

struct Node{
  int coef;
  int expn;
  Noder next;
};

Noder addPoly(Noder a,Noder b){
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
      int co = ptrA->coef + ptrB->coef;

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


void print(Noder re){

  int numZero = 0;
  int numAll = 0;
  while(re!=0){

    if(re->coef == 0){
      numZero++;
      numAll++;
      re = re->next;
      continue;
    }else{
      if(re->expn == 0){

      if(re->next == 0){
        cout<<re->coef;
        numAll++;
        break;
      }else{
        cout<<re->coef;
        re = re->next;
        if(re->coef>0){
          cout<<"+";
        }
        if(re->coef==0&&re->next!=0){
          if(re->next->coef>0){
            cout<<"+";
          }
        }
        numAll++;
        continue;
      }

    }else{

      if(re->coef == 1){

        if(re->expn == 1){
          if(re->next == 0){
            cout<<"x";
            numAll++;
            break;
          }else{
            cout<<"x";
            re = re->next;
            if(re->coef>0){
              cout<<"+";
            }
            if(re->coef==0&&re->next!=0){
              if(re->next->coef>0){
                cout<<"+";
              }
            }
            numAll++;
            continue;
          }
        }else{
          if(re->next == 0){
            cout<<"x^"<<re->expn;
            numAll++;
            break;
          }else{
            cout<<"x^"<<re->expn;
            re = re->next;
            if(re->coef>0){
              cout<<"+";
            }
            if(re->coef==0&&re->next!=0){
              if(re->next->coef>0){
                cout<<"+";
              }
            }
            numAll++;
            continue;
          }
      }

    }else if(re->coef == -1){

      if(re->expn == 1){
        if(re->next == 0){
          cout<<"-x";
          numAll++;
          break;
        }else{
          cout<<"-x";
          re = re->next;
          if(re->coef>0){
            cout<<"+";
          }
          if(re->coef==0&&re->next!=0){
            if(re->next->coef>0){
              cout<<"+";
            }
          }
          numAll++;
          continue;
        }
      }else{
        if(re->next == 0){
          cout<<"-x^"<<re->expn;
          numAll++;
          break;
        }else{
          cout<<"-x^"<<re->expn;
          re = re->next;
          if(re->coef>0){
            cout<<"+";
          }
          if(re->coef==0&&re->next!=0){
            if(re->next->coef>0){
              cout<<"+";
            }
          }
          numAll++;
          continue;
        }
    }

  }else{

    if(re->expn == 1){
      if(re->next == 0){
        cout<<re->coef<<"x";
        numAll++;
        break;
      }else{
        cout<<re->coef<<"x";
        re = re->next;
        if(re->coef>0){
          cout<<"+";
        }
        if(re->coef==0&&re->next!=0){
          if(re->next->coef>0){
            cout<<"+";
          }
        }
        numAll++;
        continue;
      }
    }else{
      if(re->next == 0){
        cout<<re->coef<<"x^"<<re->expn;
        numAll++;
        break;
      }else{
        cout<<re->coef<<"x^"<<re->expn;
        re = re->next;
        if(re->coef>0){
          cout<<"+";
        }
        if(re->coef==0&&re->next!=0){
          if(re->next->coef>0){
            cout<<"+";
          }
        }
        numAll++;
        continue;
      }
  }

  }
  }
}
}//while

if(numZero == numAll){
  cout<<"0";
}
cout<<endl;
}
int main(){

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

    Noder result = addPoly(ptrToM,ptrToN);
    print(result);


  }

    return 0;
}
