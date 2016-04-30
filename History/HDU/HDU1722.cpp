/*
 *	Name : HDU1722.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月6日 下午11:39:00
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int main() {
	int p, q;
	while (cin >> p >> q) {
		cout << p + q - __gcd(p, q) << endl;
	}
	return 0;
}
