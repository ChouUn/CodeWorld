/*
 *	Name : ZUCC1382.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月19日 下午7:12:31
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <stdio.h>
#include <string.h>
//@ Program Begin

#define maxN 40
#define maxM 10000010
int n, m, ans;
int a[maxN];
char f[maxM];

void dfs(int id, int sum) {
	if (sum > m) return;
	if (!id) { if (sum > ans) ans = sum; return; }
	if (f[sum] >= id) return;
	dfs(id - 1, sum);
	dfs(id - 1, sum + a[id - 1]);
	f[sum] = id;
}

//@ Main Function
int main() {
	int _; scanf("%d", &_);
	while (_--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		memset(f, 0x00, (m + 1) * sizeof(f[0]));
		ans = 0;
		dfs(n, 0);
		printf("%d\n", ans);
	}
	return 0;
}
