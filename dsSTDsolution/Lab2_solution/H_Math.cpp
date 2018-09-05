#include<bits/stdc++.h>

using namespace std;

int res = 0;

int x, y;

int gcd(int x, int y){
	return y == 0 ? x : gcd(y, x % y);
}

int lowbit(int x){
	return x & -x;
}

int main(){
	freopen("test.in", "r", stdin);
	freopen("test.res", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &x, &y);
		if (!x || !y) printf("0\n");
		else if ((x + y) & 1) printf("-1\n");
		else if (x == y) printf("1\n");
		else {
			if (abs(x - y) % ((x + y) / lowbit(x + y)) == 0) res = log2(lowbit(x + y)) - log2(lowbit(abs(x - y))) + 1;
				else res = -1;
			if (res >= 0 && res < log2(x + y) + 1) printf("%d\n", res);
			else printf("-1\n");	
		}
	}
	return 0;
}
