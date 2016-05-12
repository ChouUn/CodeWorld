/*
 *	Name : zju3868.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��16�� ����11:45:31
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 1000010
#define mod 998244353

long long powmod(int a, int b) {
	long long ret = 1, tmp = a;
	for (; b; tmp = tmp * tmp % mod, b >>= 1)
		if (b & 1) ret = ret * tmp % mod;
	return ret;
}

int cnt[maxN], f[maxN];

//@ Main Function
int main() {
	int _; cin >> _;
	for (; _ > 0; _--) {
		int n, k, m = 0; cin >> n >> k;
		memset(cnt, 0x00, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			cnt[x]++; m = max(m, x);
		}

		for (int i = m; i > 0; i--) {
			int sum = cnt[i]; f[i] = 0;
			for (int j = i << 1; j <= m; j += i)
				sum += cnt[j], f[i] = (f[i] - f[j] + mod) % mod;
			f[i] = (f[i] + powmod(2, sum) - 1) % mod;
		}

		int ans = 0;
		for (int i = m; i > 0; i--) if (f[i])
			ans = (ans + powmod(i, k) * f[i]) % mod;
		printf("%d\n", ans);
	}
	return 0;
}
