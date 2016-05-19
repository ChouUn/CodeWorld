/*
 *	Name : ZUCC1177.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月12日 上午7:46:24
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <iostream>
using namespace std;

typedef long long	Int64;
#define REP(i,n)	for(int _t=n,i=0;i<_t;i++)

int main() {
	int n;
	while (cin >> n) {
		int f[3] = {0, 0, 0};

		int opt = 0;
		REP(i, n) {
			int ele; cin >> ele;
			opt += ele / 3, ele %= 3;
			f[ele] ++;
		}

		Int64 ans = opt;
		if (f[2] && opt > 0) ans += f[2], f[2] = 0;
		while (f[1] && opt > 1) ans++, f[1]--, opt--;
		while (opt > 2) {
			ans += opt / 3;
			opt = opt / 3 + opt % 3;
		}
		cout << ans << endl;
	}
	return 0;
}
