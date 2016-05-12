/*
 *	Name : POJ2955.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月19日 下午3:57:25
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 110
int dp[maxN][maxN];

int main() {
	string in;
	while (cin >> in && in != "end") {
		char* s = &in[0];
		int n = in.sz;

		CLEAR(dp, 0x00);
		FOR (i, 2, n) FOR (l, 0, n - i) {
			int r = l + i - 1;
			if ((s[l] == '(' && s[r] == ')') || (s[l] == '[' && s[r] == ']'))
				dp[l][r] = dp[l+1][r-1] + 2;
			FOR (k, l, r - 1)
				exmax(dp[l][r], dp[l][k] + dp[k+1][r]);
		}
		cout << dp[0][n-1] << endl;
	}
	return 0;
}
