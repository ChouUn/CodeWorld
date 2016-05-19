/*
 *	Name : HDU2050.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月3日 下午4:00:55
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int main() {
	int t; cin >> t;
	while (t--) {
		Int64 n; cin >> n;
		Int64 ans = 2 * n * n - n + 1;
		cout << ans << endl;
	}
	return 0;
}
