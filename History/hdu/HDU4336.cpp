/*
 *	Name : HDU4336.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月19日 上午12:49:48
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 20
int n;
double p[maxN];
double f[1<<maxN];

int main() {
	while (cin >> n) {
		REP(i, n) cin >> p[i];

		REP(i, 1 << n) {
			f[i] = !!i;
			double ps = 0.;
			REP(j, n) {
				if (i & (1 << j)) {
					f[i] += f[i ^ (1 << j)] * p[j];
					ps += p[j];
				}
			}
			f[i] /= (ps ? ps : 1.);
		}

		printf("%.5lf\n", f[(1 << n) - 1]);
	}
	return 0;
}
