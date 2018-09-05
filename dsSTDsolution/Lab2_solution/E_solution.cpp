#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1234;
const int MOD = 123456789;

typedef long long ll;

int T, N, K, X;
int a[MAXN], f[MAXN];

int pow_mod(int x, int p, int MOD){
	int res = 1;
	while (p){
		if (p & 1) res = ((ll)res * x) % MOD;
		x = ((ll)x * x) % MOD;
		p >>= 1;
	}
	return res;
}

void solve(){
	int p = K / N;
	for (int i = 0; i < N; i++){
		f[i] = pow_mod(a[i], p, MOD);
	}
	for (int i = 0; i < K % N; i++){
		int pos = (X + i) % N;
		f[pos] = ((ll)f[pos] * a[pos]) % MOD;
	}
		
}

int main(){
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &N, &K, &X);
		for (int i = 0; i < N; i++) scanf("%d", a + i), f[i] = 1;
		solve();
		for (int i = 0; i < N; i++) printf("%d%c", f[i], " \n"[i == N - 1]);
	}
	return 0;
}
