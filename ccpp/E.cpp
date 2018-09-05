#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){

  int T = 0;
  cin>>T;
  for(int num = 0;num<T;num++) {

			int len = 0;
      cin>>len;
			string str;
      cin>>str;

			char t[str.length()];

			for(int i =0;i<str.length();i++){
				t[i] = str.at(i);
			}
			int res = 0;
			for(int k = 1;k <= len;k++){
				int  time = 0;
				if(k==len){
					res+=len;
					break;
				}

				char p[k];
				for(int i =0;i<k;i++){
					p[i] = t[i];
				}
				int[] next = next(*p);

				int i = 0;
				int j = 0;
				while(i<t.length ){

					if(t[i]==p[j]){

							i++;
							j++;

						if(j==p.length){
							time++;
							j = next[j];
						}
					}else{
						i++;

					}
				}

				res += k*time;
			}
			cout<<res;
		}
}

int* next(char[] p){
		int next[p.length+1];
		next[0] = -1;
		   int k = -1;
		   int num2 = 0;
		   while(num2<p.length){
			   if(k == -1 || p[num2] == p[k]){
				   k++;
				   num2++;
				   next[num2] = k;
			   }else{
				   k = next[k];
			   }
		   }
		   return next;
	}
