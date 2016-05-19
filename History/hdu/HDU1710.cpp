/*
 *	Name : HDU1710.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月14日 下午10:23:48
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 1010
queue<int> p;
int q[maxN], f;

void dfs(int s, int t) {
	if (s >= t) return;
	int c = p.front(); p.pop();
	dfs(s, q[c]);
	dfs(q[c] + 1, t);
	printf("%d%c", c, (--f) ? ' ' : '\n');
}

//@ Main Function
int main() {
	for (int n; cin >> n; n--) {
		for (int i = 0; i < n; i++) { int m; cin >> m; p.push(m); }
		for (int i = 0; i < n; i++) { int m; cin >> m; q[m] = i; }
		f = n; dfs(0, n);
	}
	return 0;
}
