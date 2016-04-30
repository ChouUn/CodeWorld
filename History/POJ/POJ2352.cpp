/*
 *	Name : POJ2352.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月4日 下午9:31:01
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>
#include <Fenwick.h>

#define maxN 15010

Fenwick<int> f;
int ans[maxN];

int main() {
	int n; cin >> n;
	f.resize(maxN << 2);
	REP(i, n) {
		int x, y; scanf("%d %d", &x, &y);
		ans[f.get(x + 1)] ++;
		f.set(x + 1, 1);
	}
	REP(i, n) printf("%d\n", ans[i]);
	return 0;
}
