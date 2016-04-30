/*
 *	Name : gym100548F.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月7日 下午6:45:35
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
//@ Using Namespace
using namespace std;
//@ Macro Loop Define
#define FOR(i,m,n)	for(int _s=m, _t=n+1-2*((n)<(m)), _d=1-2*((n)<(m)), i=_s; i!=_t; i+=_d)
#define REP(i,n)	for(int _t=n, i=0; i<_t; i+=1)
#define RREP(i,n)	for(int i=n-1; i>=0; i-=1)
//@ Faster Input
typedef long long Int64;
inline int getint() {
	int ret = 0; bool ok = 0, neg = 0; while (int c = getchar()) {
	if (c >= '0' && c <= '9') ret = (ret << 3) + (ret << 1) + c - '0', ok = 1;
	else if (ok) break; else if (c == '-') neg = 1; } return neg ? -ret : ret;
}
//@ Program Begin

#define maxK 1000010
#define mod 1000000007LL
Int64 invi[maxK], ck[maxK];

Int64 ModPow(Int64 x, int n) {
	Int64 ret = 1;
	while (n) {
		if (n & 1) ret = ret * x % mod;
		x = x * x % mod; n >>= 1;
	}
	return ret;
}

//@ Main Function
int main() {
	for (int i = 1; i < maxK; i++) invi[i] = ModPow(i, mod - 2);
	
	for (int _case = getint(), __case = 1; _case; _case--, __case++) {
		int n = getint(), m = getint(), k = getint();

		Int64 cmk = 1;
		for (int i = 1; i <= k; i++)
			cmk = cmk * (m - i + 1) % mod * invi[i] % mod;

		ck[0] = 1;
		for (int i = 1; i <= k; i++)
			ck[i] = ck[i - 1] * (k - i + 1) % mod * invi[i] % mod;

		Int64 ans = 0;
		for (int i = k, sgn = 1; i >= 1; i--, sgn = -sgn)
			ans = (ans + sgn * (i * ModPow(i - 1, n - 1) % mod * ck[i] % mod)) % mod;
		ans = (ans + mod) % mod * cmk % mod;

		printf("Case #%d: %I64d\n", __case, ans);
	}
	return 0;
}
