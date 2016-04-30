/*
 *	Name : BC33B.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月14日 下午7:17:05
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

map<int,bool> g;
map<int,bool> p;
int m;

void sd(int id, int n, bool f, int r);
void su(int id, int n, bool f, int r);

void sd(int id, int n, bool f, int r) {
	if (id == m) { p[r] = true; return; }
	if (!f) su(id, n, 1, r);
	for (int i = n - 1; i >= 1; i--) {
		if (g[i]) continue;
		g[i] = true;
		sd(id + 1, i, f, r * 10 + i);
		g[i] = false;
	}
}

void su(int id, int n, bool f, int r) {
	if (id == m) { p[r] = true; return; }
	if (!f) sd(id, n, 1, r);
	for (int i = n + 1; i <= m; i++) {
		if (g[i]) continue;
		g[i] = true;
		su(id + 1, i, f, r * 10 + i);
		g[i] = false;
	}
}

int main() {
	FOR(i, 4, 9) {
		p.clear();
		m = i;
		su(0, 0, 0, 0);
		sd(0, i + 1, 0, 0);
		cout << "i = " << i << " " << p.size() << endl;
//		TRV(i, p) cout << (i->X) << endl;
	}
	return 0;
}
