/*
 *	Name : BC31A.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年2月28日 下午6:57:51
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 100010
int n, k, data[maxN];

int main() {
	int T; cin >> T;
	while (T --) {
		cin >> n >> k;
		REP(i,n) scanf("%d", data + i);
		sort(data, data + n);

		Int64 ans = 0;
		int l = 0;
		REP(r, n) {
			while (l < r && data[l] + k < data[r]) l ++;
			ans += r - l;
		}
		cout << ans << endl;
	}
	return 0;
}
