/*
 *	Name : BC34B.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��3��21�� ����7:19:46
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */


#ifndef _TEMPLATE_STANDARD
#define _TEMPLATE_STANDARD 1

//@ C Library Wrappers
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <cstddef>
//@ Containers
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
//@ Input / Output
#include <sstream>
#include <fstream>
#include <iostream>
//@ Math and Numerics
#include <limits>
#include <complex>
#include <numeric>
#include <algorithm>
//@ Other Utilities
#include <bitset>
#include <string>
#include <utility>
#include <functional>
using namespace std;
//@ Standard Template Library
#define mp(a,b)		make_pair(a,b)
#define X			first
#define Y			second
#define sz			size()
#define op			begin()
#define ed			end()
#define all(x)		(x).op, (x).ed
#define tp(x)		__typeof((x).op)
	#define rop		rbegin()
	#define red		rend()
	#define rtp(x)	__typeof((x).rop)
#define inf			push_front
#define inb			push_back
#define def			pop_front
#define deb			pop_back
#define inc			insert
#define dec			erase
#define lb			lower_bound
#define ub			upper_bound
//@ Binary Tree Quickly Func
#define l(x)		((x)<<1)
#define	r(x)		((x)<<1|1)
#define	u(x)		((x)>>1)
#define	lson(x)		l(x), (l), (mid)
#define	rson(x)		r(x), (mid + 1), (r)
#define	lowbit(x)	((x)&-(x))
//@ For ACM/ICPC D.S.&A.
#define PAUSE()		system("pause")
#define PRINT(x)	cout << #x << " = " << x << endl
#define CLEAR(x,c)	memset(x,c,sizeof(x))
#define FOR(i,m,n)	for(int _s=(m),_t=(n)+1-2*((n)<(m)),_d=1-2*((n)<(m)),i=_s;i!=_t;i=i+_d)
#define REP(i,n)	for(int _t=n,i=0;i<_t;i++)
#define per(i,n)	for(int i=n-1;i>=0;i--)
#define TRV(i,n)	for(tp(n) i=(n).op;i!=(n).ed;i++)
#define RTRV(i,n)	for(rtp(n) i=(n).rop;i!=(n).red;i++)
//@ 64 Bit Integer for win/unix
#define	 FMT		"%I64d"
#ifdef	 unix
#undef	 FMT
#define	 FMT		"%lld"
#endif
//@ Mathematics & New Type / Func
#define PI			3.14159265358979323846264338
#define EXP			2.71828182845904523536028747
#define	EPS			(1e-9)
typedef pair<int,int>		pii;
typedef vector<int>			vi;
typedef vector<pii>			vpii;
typedef long long			Int64;
typedef unsigned long long	uInt64;
template<typename _Tp> _Tp sqr(_Tp x) { return x * x; }
template<typename _Tp> bool exmax(_Tp &a, const _Tp b) { return (b > a) ? ((a = b) || 1) : 0; }
template<typename _Tp> bool exmin(_Tp &a, const _Tp b) { return (b < a) ? ((a = b) || 1) : 0; }
int getint() { int ret = 0; bool ok=0, neg=0; while (true) { int c = getchar();
	if (c >= '0' && c <= '9') ret = (ret<<3) + (ret << 1) + c - '0', ok = 1;
    else if (ok) break; else if (c=='-') neg=1; } return neg ? -ret : ret; }
#endif	/* _TEMPLATE_STANDARD */

#define maxN 50010
int n, w, h;
int a[maxN];
Int64 g[maxN], f[maxN];

int main() {
	while (scanf("%d%d%d", &n, &w, &h) != EOF) {
		Int64 sum = 0;
		g[0] = f[0] = 0;
		FOR (i, 1, n) {
			scanf("%d", a + i);
			sum += a[i];
			a[i] -= h;
			if (a[i] < 0) {
				g[i] = g[i-1] - a[i];
				f[i] = f[i-1];
			}
			else {
				g[i] = g[i-1];
				f[i] = f[i-1] + a[i];
			}
		}

		if (sum < (Int64)w * h) {
			puts("-1");
			continue;
		}

		Int64 ans = 0xffffffffffffLL;
		FOR (i, 1, w + n - 1) {
			int r = min(i, n);
			int l = max(0, i - w);
			Int64 t1 = g[r] - g[l];
			Int64 t2 = f[r] - f[l];
			t1 += (Int64)(w - (r - l)) * h;
			Int64 t3 = max(t1, t2);
			exmin(ans, t3);
		}
		printf(FMT "\n", ans);
	}
	return 0;
}
