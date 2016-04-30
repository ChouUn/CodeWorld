/*
 *	Name : standard.h 纸农の标准库
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
#define RREP(i,n)	for(int i=n-1;i>=0;i--)
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


#ifndef _TEMPLATE_MODINT
#define _TEMPLATE_MODINT 1

#ifndef _TEMPLATE_STANDARD
#include <standard.h>
#endif 	/* _TEMPLATE_STANDARD */

template <Int64 _Key = 1000000007ll>
class ModInt {
// Name : ModInt 64位无符号自取模整型
// Copyright : www.fateud.com
public	:
	typedef ModInt<_Key>		_Self;
	typedef Int64				value_type;
	typedef Int64 &			reference;
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


#ifndef _TEMPLATE_MATRIX
#define _TEMPLATE_MATRIX 1

#ifndef _TEMPLATE_STANDARD
#include <standard.h>
#endif 	/* _TEMPLATE_STANDARD */

template <typename _Tp, size_t _Sz>
class Matrix {
// Name : Matrix 矩阵
// Copyright : www.fateud.com
public	:
	typedef Matrix<_Tp, _Sz>		_Self;
	typedef _Tp						value_type;
	typedef _Tp &					reference;
private	:
	size_t _h, _w;
	value_type _data[_Sz][_Sz];
public	:
	Matrix() : _h(_Sz), _w(_Sz) { clear(); }
	Matrix(size_t __h, size_t __w) : _h(__h), _w(__w) { clear(); }
	static _Self basic(size_t __n) { _Self __res(__n, __n); REP(i,__n) __res._data[i][i] = 1; return __res; }
	inline static _Self basic(const _Self& target) { return basic(target._h); }
	inline size_t height() const { return _h; }
	inline size_t width() const { return _w; }
	inline reference at(size_t x, size_t y) { return _data[x][y]; }
	inline void clear() { CLEAR(_data, 0x00); }
	_Self & operator += (_Self other) { REP(i,_h) REP(j,_w) at(i,j) += other.at(i,j); return (*this); }
	_Self & operator *= (_Self other) { _Self __res(_h, other._w); REP(i,__res._h) REP(j,__res._w) REP(k,_w) __res.at(i,j) += (*this).at(i,k) * other.at(k,j); *this = __res; return (*this); }
	_Self operator + (const _Self other) const { return _Self(*this) += other; }
	_Self operator * (const _Self other) const { return _Self(*this) *= other; }
	_Self operator ^ (uInt64 __k) { _Self n = *this, __res = basic(*this); while (__k) { if (__k & 1) __res *= n; n *= n, __k >>= 1; } return __res; }
};

#endif /* _TEMPLATE_MATRIX */

typedef ModInt<1000000007> mInt;
typedef Matrix<mInt,3> Mat;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n < 2) {
        	cout << 0 << endl;
        	continue;
        }
        Mat p(1,2);
        p.at(0,0) = 1; p.at(0,1) = 0;

        Mat q(2,2);
        q.at(0,0) = 0; q.at(0,1) = 3;
        q.at(1,0) = 1; q.at(1,1) = 2;

        p *= (q ^ n);
        mInt ans = p.at(0, 0);
        cout << ans.get() << endl;
    }
    return 0;
}
