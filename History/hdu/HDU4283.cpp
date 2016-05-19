/*
 *	Name : HDU4283.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月19日 上午1:19:26
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 110
int n, v[maxN];
int sum[maxN];
int dp[maxN][maxN];

int main() {
	int T_max; cin >> T_max;
	FOR (T, 1, T_max) {
		cin >> n;
		FOR (i, 1, n) cin >> v[i];

		FOR (i, 1, n) sum[i] = sum[i-1] + v[i];

		FOR (i, 2, n) FOR (l, 1, n - i + 1) {
			int r = l + i - 1;
			dp[l][r] = INT_MAX >> 2;
			FOR (k, 0, r - l)
				exmin(dp[l][r], dp[l+1][l+k] + dp[l+k+1][r] + (k+1) * (sum[r] - sum[l+k]) + v[l] * k);
		}
		printf("Case #%d: %d\n", T, dp[1][n]);
	}
	return 0;
}
