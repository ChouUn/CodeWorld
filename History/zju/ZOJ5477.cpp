/*
 *	Name : zju5477.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��15�� ����9:31:26
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 12
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m, t;
char mp[maxN][maxN];
bool vis[maxN][maxN][4];

struct node {
	int x, y, time, cur;
	node() : x(), y(), time(), cur() { }
	node(int a, int b, int c, int d) : x(a), y(b), time(c), cur(d) { }
	bool operator == (const node& b) const { return x == b.x && y == b.y; }
	bool valid() { return x >= 0 && x < n && y >= 0 && y < m && mp[x][y] == '.'; }
} src, tar;

int solve() {
	queue<node> q;
	memset(vis, 0x00, sizeof(vis));
	q.push(src);
	while (!q.empty()) {
		node u = q.front(); q.pop();
		if (!u.valid()) continue;
		if (u == tar) return u.time;
		int dir = ((u.cur - u.time / t) % 4 + 4) % 4;
		if (vis[u.x][u.y][dir]) continue; vis[u.x][u.y][dir] = true;
		q.push(node(u.x, u.y, u.time + 1, u.cur));
		q.push(node(u.x, u.y, u.time + 1, (u.cur + 1) % 4));
		q.push(node(u.x, u.y, u.time + 1, (u.cur + 3) % 4));
		q.push(node(u.x + dx[dir], u.y + dy[dir], u.time + 1, u.cur));
	}
	return -1;
}

//@ Main Function
int main() {
	int _; cin >> _;
	while (_--) {
		cin >> n >> m >> t;
		for (int i = 0; i < n; i++) cin >> mp[i];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mp[i][j] == '@') { src = node(i, j, 0, 0); mp[i][j] = '.'; }
				if (mp[i][j] == '$') { tar = node(i, j, 0, 0); mp[i][j] = '.'; }
			}
		}

		int ans = solve();
		if (ans > 0)
			printf("%d\n", ans);
		else
			printf("YouBadbad\n");
	}
	return 0;
}
