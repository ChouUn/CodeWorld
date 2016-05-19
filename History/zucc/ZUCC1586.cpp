/*
 *	Name : ZUCC1586.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月20日 下午7:42:15
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 110
#define maxK 30
#define maxC 30
typedef pair<int,int> pii;

struct node {
	int x, y;
	int s, t;
	node() : x(), y(), s(), t() { }
	node(int a, int b, int c, int d) : x(a), y(b), s(c), t(d) { }
	bool operator == (const node& b) { return x == b.x && y == b.y; }
};

int n, m, k;
char mp[maxN][maxN];
node src, tar;
bool f[maxN][maxN][maxK];
pii g[maxC];
map<pii, pii> h;

int solve() {
	queue<node> q;
	q.push(src);
	while (!q.empty()) {
		node now = q.front(); q.pop();
		if (now.x < 0 || now.y < 0 || now.x >= n || now.y >= m || now.s > k) continue;
		if (now == tar) return now.t;
		if (f[now.x][now.y][now.s]) continue; f[now.x][now.y][now.s] = true;
		q.push(node(now.x - 1, now.y, now.s, now.t + 1));
		q.push(node(now.x + 1, now.y, now.s, now.t + 1));
		q.push(node(now.x, now.y - 1, now.s, now.t + 1));
		q.push(node(now.x, now.y + 1, now.s, now.t + 1));
		if (mp[now.x][now.y] != '*') {
			pii v = h[make_pair(now.x, now.y)];
			q.push(node(v.first, v.second, now.s + 1, now.t + 1));
		}
	}
	return -1;
}

//@ Main Function
int main() {
	while (scanf("%d%d%d", &n, &m, &k) != EOF && (n || m || k)) {
		memset(f, 0x00, sizeof(bool) * n * maxN * maxK);
		memset(g, 0xff, sizeof(g));
		h.clear();
		for (int i = 0; i < n; i++)
			scanf("%s", mp[i]);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mp[i][j] == '@') {
					mp[i][j] = '*';
					src = node(i, j, 0, 0);
				}
				if (mp[i][j] == '$') {
					mp[i][j] = '*';
					tar = node(i, j, 0, 0);
				}
				if (mp[i][j] != '*') {
					int c = mp[i][j] - 'a';
					if (g[c].first == -1) {
						g[c] = make_pair(i, j);
					}
					else {
						pii v = make_pair(i,j);
						h[g[c]] = v;
						h[v] = g[c];
					}
				}
			}
		}
		printf("%d\n", solve());
	}
	return 0;
}
