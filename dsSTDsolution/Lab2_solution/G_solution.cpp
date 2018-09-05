#include<bits/stdc++.h>

using namespace std;

const int MAXN = 12345;
int T, a[MAXN], Q, x, N;

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", a + i);
		scanf("%d", &Q);
		while (Q--){
			scanf("%d", &x);
			int L = lower_bound(a, a + N, x) - a;
			int R = upper_bound(a, a + N, x) - a;
			if (!(R - L) & 1) printf("-1\n");
			else printf("%d\n", L + 1);
		}
	}
	return 0;
} 
