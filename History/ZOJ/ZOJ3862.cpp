/*
 *	Name : ZOJ3862.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月14日 下午9:49:56
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 100010
typedef pair<int,int> pii;
struct point {
	int x, y;
	point() : x(), y() { }
	point(int a, int b) : x(a), y(b) { }
	bool operator < (const point& o) const { return (x < o.x) || (x == o.x && y < o.y); }
} p[maxN<<1], q[maxN<<1];

int n, m;
map<point, int> mp;
vector<pii> ans;
int v[maxN<<1];

//@ Main Function
int main() {
	int _; cin >> _;
	while (_--) {
		cin >> n; m = n << 1;
		ans.clear(); mp.clear();
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &p[i].x, &p[i].y);
			q[i] = p[i]; mp[p[i]] = i;
		}
		for (int i = 0; i < n; i++) {
			int a, b; scanf("%d%d", &a, &b);
			v[a-1] = b-1, v[b-1] = a-1;
		}

		sort(q, q + m);
		for (int i = 0; i < m; i += 2) {
			int a = mp[q[i]], b = mp[q[i+1]], c = v[a];
			if (c != b) {
				ans.push_back(make_pair(b,c));
				swap(p[b], p[c]);
				mp[p[b]] = b, mp[p[c]] = c;
			}
		}

		printf("%u\n", ans.size());
		for (vector<pii>::iterator i = ans.begin(); i != ans.end(); i++)
			printf("%d %d\n", i->first + 1, i->second + 1);
	}
	return 0;
}
