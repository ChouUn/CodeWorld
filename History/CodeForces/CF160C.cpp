/*
 *	Name: CF160C.cpp
 *	Author: CHN.ChouUn
 *	Date: 2015年2月9日 下午10:56:02
 *	Copyright: www.fateud.com
 *	Email: ChouUnSoft@gmail.com
 *	Description: None
 */

#include <standard.h>

#define maxN 100010
typedef pair<int,Int64> pil;

int n; Int64 k;
int a[maxN];

int main() {
	cin >> n >> k;
	REP(i,n) scanf("%d", a+i);
	
	sort(a, a+n);
	vector<pil> p;
	REP(i,n)
		if (i && a[i] == a[i-1])
			p[p.sz-1].Y ++;
		else
			p.inb(mp(a[i], 1LL));

	REP(i,p.sz) {
		if (k > p[i].Y * n) {
			k -= p[i].Y * n;
			continue;
		}
		REP(j,p.sz) {
			if (k > p[i].Y * p[j].Y) {
				k -= p[i].Y * p[j].Y;
				continue;
			}
			cout << p[i].X << " " << p[j].X << endl;
			return 0;
		}
	}
	return 0;
}
