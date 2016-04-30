/*
 *	Name : CF148D.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月18日 下午6:59:11
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 1010
double f[maxN][maxN];

double search(int w, int b) {
	if (w < 0 || b < 0) return 0.;
	if (f[w][b]) return f[w][b];

	double& ret = f[w][b];
	if (!(w && b)) return ret = (w) ? (1.) : (1e-10);
	ret += w * 1. / (w + b);

	double tmp = b * 1. / (w + b) * (b - 1) / (w + b - 1);
	if (b >= 2) {
		ret += tmp * search(w, b - 3) * (b - 2) / (w + b - 2);
		ret += tmp * search(w - 1, b - 2) * (w) / (w + b - 2);
	}

	return ret;
}

int main() {
	int w, b; cin >> w >> b;
	printf("%.9lf\n", search(w, b));
	return 0;
}
