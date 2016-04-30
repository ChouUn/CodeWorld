/*
 *	Name : POJ1062.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年2月21日 下午7:45:53
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>
#include <Graph.h>

#define maxN 110

Graph<int> g(maxN);
int n, m, l[maxN];
bool used[maxN];
int dist[maxN];

int main() {
	cin >> m >> n;
	FOR(i, 1, n) {
		int w, k, u;
		cin >> w >> l[i] >> k;
		g.add_edge(0, i, w);
		while (k--) {
			cin >> u >> w;
			g.add_edge(u, i, w);
		}
	}

	int ans = INT_MAX;
	FOR(i, max(l[1]-m,0), l[1]) {
		used[0] = 0;
		FOR(j, 1, n)
			used[j] = !((l[j] >= i) && (l[j] <= (i + m)));
		g.Dijkstra(0, dist, used);
		if (used[1]) exmin(ans, dist[1]);
	}
	cout << ans << endl;

	return 0;
}
