#include<bits/stdc++.h>

using namespace std;

int T, n;

int main(){
	cin >> T;
	while (T--){
		scanf("%d", &n);
		printf("%lld\n", 1ll * n * (n + 1) * (2 * n + 1) / 6);
	}
	return 0;
} 
