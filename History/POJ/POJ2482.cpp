/*
 *	Name : POJ3397.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月5日 上午10:26:39
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>
#include <Segmtree.h>

struct segm_node {
	typedef segm_node		_Self;
	Int64 val, sum;
	segm_node() : val(), sum() { }
	segm_node(Int64 __val, Int64 __sum) : val(__val), sum(__sum) { }
	static _Self init(size_t __n) {
		return _Self(0, 0);
	}
	static _Self merge(const _Self& a, const _Self& b) {
		return segm_node(0, max(a.sum, b.sum));
	}
	void update(const _Self& other) {
		val += other.val, sum += other.val;
	}
};

struct node {
	Int64 x1, x2, y, c;
	static bool cmp(const node &a, const node &b) {
		return (a.y != b.y) ? (a.y < b.y) : (a.c < b.c);
	}
};

#define maxN 10010

Segmtree<segm_node> f;
int n, w, h;
node g[maxN << 1];
Int64 a[maxN << 1];

int main() {
	while (scanf("%d%d%d", &n, &w, &h) != EOF) {
		REP(i, n) {
			Int64 x, y, c; scanf(FMT FMT FMT, &x, &y, &c);
			a[l(i)] = x, a[r(i)] = x + w - 1;
			g[l(i)].x1 = g[r(i)].x1 = a[l(i)];
			g[l(i)].x2 = g[r(i)].x2 = a[r(i)];
			g[l(i)].y = y, g[r(i)].y = y + h;
			g[l(i)].c = c, g[r(i)].c = -c;
		}

		sort(g, g + n * 2, node::cmp);
		sort(a, a + n * 2);
		size_t end = unique(a, a + n * 2) - a;

		f.resize(end);
		Int64 ans = 0;
		REP(i, n * 2) {
			size_t l = lower_bound(a, a + end, g[i].x1) - a + 1;
			size_t r = lower_bound(a, a + end, g[i].x2) - a + 1;
			f.set(l, r, segm_node(g[i].c, 0));
			exmax(ans, f.get(1, end).sum);
		}
		cout << ans << endl;
	}
	return 0;
}
