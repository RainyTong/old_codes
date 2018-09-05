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
		int cnt = 0;
		for (int i = 0; i < n; i++){
			if (solve(m - a[i])) cnt++;
		}
		printf("%d\n", cnt / 2);
	}
	return 0;
}
