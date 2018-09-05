#include <iostream>
#include <stack>
#include <string>
using namespace std;

typedef struct num{
  int value = -1;
  int index;
}ob;


int main(){
  int t = 0;
  cin>>t;
  int n;

  for(int num = 0;num < t;num++){
    cin>>n;
    ob vec1[n];
    for(int i = 0;i<n;i++) {
      cin>>vec1[i].value;
      vec1[i].index = i+1;
    }

    int vec2[n];
    for(int i = 0;i<n;i++){
      vec2[i] = -1;
    }
    stack<int> sta;
    sta.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!sta.empty() && vec1[i].value>vec1[(sta.top())].value)
        {
            vec2[(sta.top())] = vec1[i].index;
            sta.pop();
        }
        sta.push(i);
    }





    string s = "";

    for (int i = 0; i < n; i++)
    {
      if(vec2[i] == -1){

        s+="0";
        s+="\n";
      }else {
      

        s+= to_string(vec2[i]);
        s+= "\n";
      }
    }
    cout<<s;



    }


return 0;
}
