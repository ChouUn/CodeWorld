/*
 *	Name : ZOJ3867.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月16日 上午3:11:38
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

//@ Main Function
int main() {
	int _; cin >> _;
	while (_--) {
		int a1, d1; cin >> a1 >> d1;
		int a2, d2; cin >> a2 >> d2;
		d2 -= a1, d1 -= a2;
		if (!a1) {
			printf("Invalid\n");
			continue;
		}
		printf(d1 > 0 ? "%d %d " : "Discard ", a1, d1);
		printf(d2 > 0 ? "%d %d\n" : "Discard\n", a2, d2);
	}
	return 0;
}
