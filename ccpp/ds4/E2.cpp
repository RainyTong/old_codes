#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

typedef struct num{
  int value = -1;
  int index;
}ob;

vector<int> get(vector<ob> a, int len)
{
    vector<int> res(len, -1);
    stack<int> sta;
    sta.push(0);
    for (int i = 1; i < len; i++)
    {
        while (!sta.empty() && a[i].value>a[(sta.top())].value)
        {
            res[(sta.top())] = a[i].index;
            sta.pop();
        }
        sta.push(i);
    }
    return res;
}


int main(){
  int t = 0;
  cin>>t;
  int n;

  for(int num = 0;num < t;num++){
    cin>>n;
    vector<ob> vec1(n);
    for(int i = 0;i<n;i++) {
      cin>>vec1[i].value;
      vec1[i].index = i+1;
    }
    vector<int> vec2 = get(vec1,n);
    string s = "";

    for (int i = 0; i < n; i++)
    {
      if(vec2[i] == -1){
        // cout<<"0"<<endl;
        s+="0";
        s+="\n";
      }else {
        // cout << vec2[i] << endl;

        s+= to_string(vec2[i]);
        s+= "\n";
      }
    }
    cout<<s;


    }


return 0;
}
