/*
 *	Name : HDU2476.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月19日 下午4:24:27
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 110
int dp[maxN][maxN];
int ans[maxN];

int main() {
	string a, b;
	while (cin >> a >> b) {
		assert(a.sz == b.sz);
		int n = a.sz;

		CLEAR(dp, 0x00);
		REP (i, n) dp[i][i] = 1;
		FOR (k, 2, n) FOR (l, 0, n - k) {
			int r = l + k - 1;
			dp[l][r] = dp[l+1][r] + 1;
			FOR (k, l + 1, r)
				if (b[l] == b[k])
					exmin(dp[l][r], dp[l+1][k] + dp[k+1][r]);
		}

		REP (r, n) {
			if (a[r] == b[r])
				ans[r] = r ? ans[r-1] : 0;
			else {
				ans[r] = dp[0][r];
				REP (l, r)
					exmin(ans[r], ans[l] + dp[l+1][r]);
			}
		}
		cout << ans[n - 1] << endl;
	}
	return 0;
}
