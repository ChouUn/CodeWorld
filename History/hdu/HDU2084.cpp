/*
 *	Name : HDU2084.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月7日 下午3:38:33
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 110

int f[maxN][maxN];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		FOR(i, 1, n) {
			FOR(j, 1, i) {
				scanf("%d", f[i] + j);
				f[i][j] += max(f[i-1][j-1], f[i-1][j]);
			}
		}

		int ans = 0;
		FOR(i, 1, n) exmax(ans, f[n][i]);
		printf("%d\n", ans);
	}
	return 0;
}
