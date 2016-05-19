/*
 *	Name : HDU2059.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月3日 下午4:32:32
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 110

int l, n, c, t, vr, vt1, vt2;
int p[maxN];
double f[maxN];

int main() {
	while (cin >> l) {
		cin >> n >> c >> t;
		cin >> vr >> vt1 >> vt2;
		FOR(i, 1, n) cin >> p[i];
		p[0] = 0; p[n + 1] = l;

		f[0] = 0.0;
		FOR(i, 1, n+1) {
			f[i] = 1e30;
			REP(j, i) {
				exmin(f[i], f[j] + (p[i] - p[j]) * 1.0 / vt2);
				if (p[i] - p[j] > c)
					exmin(f[i], f[j] + (p[i] - p[j] - c) * 1.0 / vt2 + c * 1.0 / vt1 + t * (!!j));
				else
					exmin(f[i], f[j] + (p[i] - p[j]) * 1.0 / vt1 + t * (!!j));
			}
		}

		if (f[n+1] > l * 1.0 / vr)
			puts("Good job,rabbit!");
		else
			puts("What a pity rabbit!");
	}
	return 0;
}
