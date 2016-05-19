/*
 *	Name : HDU2040.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月3日 下午2:40:47
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int solve(int n) {
	int res = 0;
	for (int i = 1; i * i <= n; i ++) {
		if (n % i) continue;
		res += i;
		res += n / i * (i * i != n);
	}
	return res - n;
}

int main() {
	int T; cin >> T;
	while (T --) {
		int a; cin >> a;
		int b; cin >> b;
		if (solve(a) == b && solve(b) == a)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
