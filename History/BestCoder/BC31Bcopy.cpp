/*
 *	Name : BC31B.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年2月28日 下午7:14:31
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int data[1300] = {1,2,3,4,5,6,7,8,9}, n = 9;

int main() {
	for (int i = 0; i < n; i++) {
		int t = data[i] % 10;
		if (data[i] > 1e8) break;
		FOR(j, 1, 9) {
			if (t < j) break;
			if (t % j) continue;
			data[n ++] = data[i] * 10 + j;
		}
	}

	int T; cin >> T;
	while (T--) {
		int l, r; cin >> l >> r;
		cout << ub(data, data + n, r) - lb(data, data + n, l) << endl;
	}
	return 0;
}
