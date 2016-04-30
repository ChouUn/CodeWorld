/*
 *	Name : BC31C.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年2月28日 下午8:01:54
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>
#include <ModInt.h>

ModInt<> get(int x, int y) {
	if (x > y) return get(y, x);
	ModInt<> res(0);
	if (x <= 0 || y <= 0) return res;
	return res;
}

ModInt<> find(int n, int m, int k) {
	ModInt<> res(0);
	if (m < k || n < k) return res;
	FOR(i, n, k) FOR(j, max(i,m), k) {
		res += find(i - 1, j - 1, k - 1)
				* get(n - i, m - j)
				* get(i - 2, m - j)
				* get(n - i, j - 2);
	}
	return res;
}

int main() {
	int T; cin >> T;
	while (T --) {
		int n, k;
		cin >> n >> k;

		ModInt<> ans = find(n, n, k);

		Int64 tmp = 1;
		REP(i,k) tmp *= i + 1;
		ans *= tmp;

		cout << ans.get() << endl;
	}
	return 0;
}
