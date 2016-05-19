/*
 *	Name : HDU2051.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月3日 下午4:04:11
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		string ans;
		while (n) {
			ans = (char)((n & 1) + '0') + ans;
			n >>= 1;
		}
		cout << ans << endl;
	}
	return 0;
}
