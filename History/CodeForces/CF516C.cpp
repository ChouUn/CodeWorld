/*
 *	Name : CF516C.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年2月18日 上午1:09:29
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>
#include <SegmTreeCopy.h>

#define maxN 100010

struct node {
	Int64 a, b, c;
	node() : a(-(LONG_LONG_MAX >> 1)), b(a), c(a) { }
	node operator + (const node &that) {
		node res;
		res.a = max(a, that.a);
		res.b = max(b, that.b);
		res.c = max(c, that.c);
		exmax(res.c, a + that.b);
		return res;
	}
	static node init(size_t n);
};

int n, m, N;
Int64 d[maxN*2], h[maxN*2];
Int64 w[maxN*2];

node node::init(size_t n)
{
	node ret;
	ret.a = 2 * h[n] - w[n];
	ret.b = 2 * h[n] + w[n];
	ret.c = -(LONG_LONG_MAX >> 1);
	return ret;
}

int main() {
	// Input
	cin >> n >> m; N = n * 2;
	FOR(i, 1, n) scanf(FMT, d + i);
	FOR(i, 1, n) scanf(FMT, h + i);

	// Init
	FOR(i, 1, n) d[i+n] = d[i];
	FOR(i, 1, n) h[i+n] = h[i];
	FOR(i, 2, N) w[i] = w[i-1] + d[i-1];

	SegmTree<node> g(N, node::init);
	g.build();

	// Solve
	while (m--) {
        size_t l, r; cin >> l >> r;
		if (l <= r) {
			size_t tmp = l;
			l = r + 1;
			r = tmp + n - 1;
		}
		else {
			size_t tmp = l;
			l = r + 1;
			r = tmp - 1;
		}
//		cout << l << ' ' << r << endl;
		node ans = g.get(l, r);
		cout << ans.c << endl;
	}
	return 0;
}
