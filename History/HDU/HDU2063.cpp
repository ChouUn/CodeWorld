/*
 *	Name : HDU2063.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月3日 下午6:49:52
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>
#include <ForwList.h>
#include <Graph.h>

int main() {
	Graph<bool> g;

	int k, m, n;
	while (cin >> k && k) {
		cin >> m >> n;

		g.resize(n + m);

		while (k--) {
			int u, v; cin >> u >> v;
			g.add_edge(u - 1, m + v - 1, true);
		}

		cout << g.Hungary() << endl;
	}

	return 0;
}
