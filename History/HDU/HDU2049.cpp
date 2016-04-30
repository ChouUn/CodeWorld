/*
 *	Name : HDU2049.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月3日 下午3:05:46
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 21

Int64 f[maxN] = {1, 0};

int main() {
	FOR(i,2,20) f[i] = (i-1) * (f[i-1] + f[i-2]);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int m; cin >> m;

		Int64 ans = 1;
		REP(i,m) ans *= n - i;
		REP(i,m) ans /= i + 1;
		ans *= f[m];

		cout << ans << endl;
	}
	return 0;
}
