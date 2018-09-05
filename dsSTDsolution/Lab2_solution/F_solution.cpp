#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 123;

int site[MAXN], T, N, K;
int res;

bool check(int k){
	int pos = site[0], cnt = 1;
	for (int i = 1; i < N; i++){
		if (site[i] - pos >= k)
			cnt++, pos = site[i];
		if (cnt >= K) return true;
	}
	return false;
}

void solve(){
	int l = 0, r = site[N - 1] - site[0] + 1;
	while (l < r){
		int mid = (l + r) >> 1;
		if (check(mid)){
			res = mid;
			l = mid + 1;
		}
		else
			r = mid;
	}
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; i++) scanf("%d", site + i);
		sort(site, site + N);
		res = 0;
		solve();
		printf("%d\n", res);
	}
} 
