/*
 *	Name : zju3860.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��14�� ����5:10:06
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

//@ Main Function
int main() {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		vector<int> g;
		while (n--) {
			int m; cin >> m;
			g.push_back(m);
		}
		sort(g.begin(), g.end());
		cout << (g[0] == g[1] ? g.back() : g.front()) << endl;
	}
	return 0;
}
