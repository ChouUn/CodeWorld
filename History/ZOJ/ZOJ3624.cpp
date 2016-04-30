/*
 *	Name : ZOJ3624.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月31日 上午12:50:54
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <csl_std.h>
#include <csl_modint.h>

//@ Using Namespace
using namespace csl;

#define maxN 200010
#define mod 100000007
typedef ModInt<mod> mInt;

mInt inv[maxN], fac[maxN];

void Init() {
	fac[0] = 1;
	FOR (i, 1, maxN - 1)
		fac[i] = fac[i - 1] * mInt(i);
	inv[maxN - 1] = fac[maxN - 1] ^ (mod - 2);
	FOR (i, maxN - 1, 1)
		inv[i - 1] = inv[i] * mInt(i);
}

mInt Com(size_t n, size_t m) {
	return fac[n] * inv[m] * inv[n-m];
}

int main() {
	Init();

	int m, n, p, q;
	while (cin >> m >> n >> p >> q) {
		mInt all = Com(m + n, m) * Com(m - p + q, q);
		mInt rst = Com(m + q, m) * Com(m - p + n, n);
		cout << (all - rst).get() << endl;
	}
	return 0;
}
