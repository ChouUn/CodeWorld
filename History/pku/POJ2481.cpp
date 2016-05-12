/*
 *	Name : POJ2481.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月4日 上午10:20:05
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>
#include <Fenwick.h>

#define maxN 100010

struct node {
	int l, r;
	int i, s;
};

bool cmp(const node &a, const node &b) {
	return (a.r == b.r) ? (a.l < b.l) : (a.r > b.r);
}

bool idx(const node &a, const node &b) {
	return a.i < b.i;
}

int n;
node g[maxN];

Fenwick<int> f;

int main() {
	while (cin >> n && n) {
		REP(i, n) {
			scanf("%d %d", &g[i].l, &g[i].r);
			g[i].i = i;
		}

		f.resize(maxN);
		sort(g, g + n, cmp);

		REP(i, n) {
			g[i].s = (i && g[i].l == g[i-1].l && g[i].r == g[i-1].r)
					? g[i-1].s : f.get(g[i].l + 1);
			f.set(g[i].l + 1, 1);
		}

		sort(g, g + n, idx);
		REP(i, n)
			printf("%d%c", g[i].s, (i + 1 == n ? '\n' : ' '));
	}
	return 0;
}
