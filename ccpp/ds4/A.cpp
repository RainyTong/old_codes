#include <iostream>
#include <stack>
using namespace std;

int main(){
  int t = 0;
  cin>>t;
  int n,m;

  for(int num = 0;num < t;num++){

    cin>>n;
    cin>>m;
    int command;

    stack<int> st;
    for(int i = 0;i<m;i++) {
      int size = st.size();
      cin>>command;
      if(command == 1) {
        int x;
        cin>>x;

        if(size < n) {
          st.push(x);
        }else if(size == n) {
          cout<<x<<endl;
        }

      }else if(command == 2) {
        if(size>0) {
          cout<<st.top()<<endl;
          st.pop();
        }
      }

    }

    //print
    int sizeNow = st.size();
    for(int i = 0;i<sizeNow;i++) {
      cout<<st.top()<<endl;//
      st.pop();
    }

  }//

  return 0;
}
