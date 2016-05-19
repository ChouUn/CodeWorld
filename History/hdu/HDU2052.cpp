/*
 *	Name : HDU2052.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月3日 下午4:10:06
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int main() {
	int n, m;
	while (cin >> m >> n) {
		FOR(i, 0, n + 1) {
			cout << ((i == 0 || i == n + 1) ? '+' : '|');
			FOR(j, 1, m) {
				cout << ((i == 0 || i == n + 1) ? '-' : ' ');
			}
			cout << ((i == 0 || i == n + 1) ? '+' : '|');
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
