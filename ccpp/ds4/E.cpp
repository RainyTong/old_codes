#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef struct num{
  int value;
  int index;
}ob;

vector<int> get(vector<int> a, int len)
{
    vector<int> res(len, -1);
    stack<int> sta;
    sta.push(0);
    for (int i = 1; i < len; i++)
    {
        while (!sta.empty() && a[i]>a[(sta.top())])
        {
            res[(sta.top())] = a[i];
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
    vector<int> vec1(n);
    for(int i = 0;i<n;i++) {
      cin>>vec1[i];
    }
    vector<int> vec2 = get(vec1,n);
    for (int i = 0; i < n; i++)
    {
        cout << vec2[i] << " ";
    }


    }


return 0;
}
