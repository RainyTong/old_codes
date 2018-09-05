#include <iostream>
using namespace std;

int main(){
  int t = 0;
  cin>>t;
  int n;

  for(int num = 0;num < t;num++){
    cin>>n;
    int output[n];
    int ci[n];
    for(int i = 0;i<n;i++){
      cin>>ci[i];
    }
    int stack[n];
    int top = -1;
    for(int i = n-1 ;i >= 0;i--){
      if(top == -1 ){
					output[i] = 0;
					top++;
					stack[top] = i+1;
				}else if(top != -1 && ci[i] < ci[stack[top]-1]){
					output[i] = stack[top];
					top++;
					stack[top] = i+1;
				}else if(top != -1 && ci[i] >= ci[stack[top]-1]){//1jiancha

					while(ci[i] >= ci[stack[top]-1]){
						top--;
						if(top == -1){
							break;
						}
					}

					if(top != -1)
					output[i] = stack[top];
					else{
						output[i] = 0;
						top++;
						stack[top] = i+1;
					}
					top++;
					stack[top] = i+1;
				}
    }
    for(int i = 0;i<n;i++){
      cout<<output[i]<<endl;
    }



  }
}
