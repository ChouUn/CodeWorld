/*
 *	Name : CF521A.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��3��2�� ����2:53:05
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#ifndef _TEMPLATE_STANDARD
#define _TEMPLATE_STANDARD 1

//@ C Library Wrappers
#include <cmath>
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

#endif	/* _TEMPLATE_STANDARD */

#ifndef _TEMPLATE_MODINT
#define _TEMPLATE_MODINT 1

#ifndef _TEMPLATE_STANDARD
#include <standard.h>
#endif 	/* _TEMPLATE_STANDARD */

template <uInt64 _Key = 1000000007ull>
class ModInt {
// Name : ModInt 64λ�޷�����ȡģ����
// Copyright : www.fateud.com
public	:
	typedef ModInt<_Key>		_Self;
	typedef uInt64				value_type;
	typedef uInt64 &			reference;
private	:
	value_type _data;
public	:
    ModInt(void) : _data() { }
	ModInt(value_type __data) : _data(__data % _Key) { }
	inline value_type get(void) const { return (*this)._data; }
	inline _Self & set(const value_type __data) { _data = __data % _Key; return (*this); }
	reference operator * () { return _data; }
	_Self & operator = (const value_type __data) { return set(__data); }
	_Self & operator += (const _Self other) { if ((_data += other._data) >= _Key) _data -= _Key; return (*this); }
	_Self &	operator -= (const _Self other) { if ((_data += _Key - other._data) >= _Key) _data -= _Key; return (*this); }
	_Self & operator *= (const _Self other) { _data = _data * other._data % _Key; return (*this); }
	_Self operator + (const _Self other) const { return ModInt(*this) += other; }
	_Self operator - (const _Self other) const { return ModInt(*this) -= other; }
	_Self operator * (const _Self other) const { return ModInt(*this) *= other; }
	_Self operator ^ (value_type p) { _Self ret = 1, tmp = *this; while (p) { if (p & 1) ret *= tmp; tmp *= tmp, p >>= 1; } return ret; }
};

#endif /* _TEMPLATE_MODINT */


int n;
string s;

int main() {
	cin >> n;
	cin >> s;

	int f[26] = {0};
	REP(i, n) f[s[i] - 'A'] ++;

	int m = 0;
	REP(i, 26) exmax(m, f[i]);

	int p = 0;
	REP(i, 26) p += m == f[i];

	ModInt<> ans = p;
	ans = ans ^ n;
	cout << *ans << endl;
	
	return 0;
}
