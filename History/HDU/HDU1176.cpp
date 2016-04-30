/*
 *	Name : HDU1176.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月7日 下午3:53:37
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 100010

struct node {
	int t, x;
	static bool cmp(const node &a, const node &b) {
		return a.t < b.t;
	}
}a[maxN];

int main() {
	int n;
	while (scanf("%d", &n) != EOF && n) {
		REP(i, n) scanf("%d%d", &a[i].x, &a[i].t);
		sort(a, a + n, node::cmp);

		int time = 0, j = 1;
		REP(i, n) {
			if (time == a[i].t) {

			}
			else {

			}
			time = a[i].t;
		}
	}
	return 0;
}
