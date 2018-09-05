#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 123;

int T, n, x, a[MAXN];

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
		scanf("%d%d", &n, &x);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		if (solve(x)) puts("YES");
		else puts("NO");
	}
	return 0;
}
