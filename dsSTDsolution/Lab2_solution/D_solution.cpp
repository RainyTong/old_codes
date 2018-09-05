#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5432;

int T, n, m, a[MAXN];

bool solve(int x){
	int l = 0, r = n;
	while (l < r){
		int mid = l + (r - l) / 2;
		if (a[mid] == x) return true;
		if (a[mid] > x) r = mid;
		else l = mid + 1;
	}
	return false;
}

int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		int flag = 0;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++){
				int goal = m - a[i] - a[j];
				if (solve(goal) && goal != a[j] && goal != a[i]){
					flag = 1;
					break;
				}
			}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
