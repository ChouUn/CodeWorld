/*
 *	Name : HDU2566.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月6日 下午11:15:59
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		if (m < n) {
			cout << 0 << endl;
			continue;
		}
		int max = (m - n) / 4;
		int min = (m - 2 * n >= 0) ? ((m - 2 * n + 2) / 3) : (0);
		cout << max - min + 1 << endl;
	}
	return 0;
}
