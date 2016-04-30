/*
 *	Name : CF535B.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月18日 下午9:57:28
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

typedef long long ll;

//@ Main Function
int main() {
	int n; cin >> n;
	queue<ll> q;
	q.push(4);
	q.push(7);
	int ans = 0;
	while (!q.empty()) {
		ll m = q.front(); q.pop();
		if (m > n) break;
		q.push(m * 10 + 4);
		q.push(m * 10 + 7);
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
