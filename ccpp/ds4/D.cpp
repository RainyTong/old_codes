
#include<iostream>
#include<deque>
using namespace std;

int main(){
  int t = 0;
  cin>>t;
  for(int i = 0;i<t;i++) {
  deque<int> dq;
  int n;
  cin>>n;

  for(int j = 0;j<n;j++) {
				int side;
        cin>>side;
				int oper,x;
				if(side == 1) {

					cin>>oper;
					if(oper == 1) {
						cin>>x;
						dq.push_front(x);
					}else if(oper == 2) {
						dq.pop_front();
					}


					}else if(side == 2) {
					cin>>oper;
					if(oper == 1) {
						cin>>x;
						dq.push_back(x);
					}else if(oper == 2) {
						dq.pop_back();
					}
				}



			}
      while(dq.empty() != true){
				cout<<dq.front()<<endl;
        dq.pop_front();
			}

    }
  return 0;
}
