/*
 *	Name : BC33Btest2.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月14日 下午8:07:31
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int main() {
	uInt64 ans = 2;
	uInt64 mod = 1000000000000000000;
	
	int n = 400;
	for (int i = 3; i <= n; i++) {
		ans = (ans * 2) % mod;
		ans = (ans + 2) % mod;
	}
	cout << ans;
	return 0;
}
