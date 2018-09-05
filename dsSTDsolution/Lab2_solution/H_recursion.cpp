#include<bits/stdc++.h>

using namespace std;

int x, y, T;

void dfs(int x, int y, int stp){
	if (stp > log2(x + y) + 1){
		printf("-1\n");
		return;
	}
	if (x < y) swap(x, y);
	if (y == 0){
		printf("%d\n", stp);
		return;	
	}
	dfs(x - y, y + y, stp + 1);
}

int main(){
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	scanf("%d", &T);
	int cnt = 0;
	while (T--){
		cnt++;
		scanf("%d%d", &x, &y);
		if (!x || !y) printf("0\n");
		else if ((x + y) & 1) printf("-1\n");
		else dfs(x, y, 0);
	}
	return 0;
} 
