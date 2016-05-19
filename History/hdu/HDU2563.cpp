/*
 *	Name : HDU2563.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月8日 下午5:07:04
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 25

Int64 g[maxN][maxN];
Int64 f[maxN];

int main() {
	FOR(i, 0, maxN - 1) g[0][i] = i ? 2 : 1;
	FOR(i, 1, maxN - 1) {
		REP(j, maxN) {
			g[i][j] = 0;
			for (int k = 1; k <= j; k++) {
				g[i][j] += (k == 1 ? 1 : 2) * g[i-1][j-k];
			}
		}
	}

	FOR(i, 0, maxN - 1) {
		FOR(j, 0, i) f[i] += g[j][i];
	}

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}
