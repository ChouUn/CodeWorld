/*
 *	Name : CF518C.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年2月25日 上午1:10:16
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 100010

int n, m, k;
int p[maxN], a[maxN];

void change(int px, int x) {
	int py = px - 1;
	int y = a[py];
	swap(p[x], p[y]);
	swap(a[px], a[py]);
}

int main() {
	cin >> n >> m >> k;
	REP(i,n) cin >> a[i];
	REP(i,n) p[a[i]] = i;

	Int64 ans = 0;
	while (m--) {
		int order;
		cin >> order;
		ans += p[order] / k + 1;
		if (p[order]) change(p[order], order);
	}

	cout << ans << endl;
	return 0;
}
