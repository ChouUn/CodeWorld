/*
 *	Name : zucc1511.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��3��26�� ����3:30:02
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
/*
 *	Name : ChouUn's Standard Library ֽũ�α�׼��
 *	Copyright : www.fateud.com
 *
 *	���¹���Ĭ�ϲ�����, ���б�Ҫ����#includeǰ����
 *	#define CSL_STD_CONTAINER
 *		��������, ������ݵĺ궨��
 *	#define CSL_STD_DEBUG
 *		���Թ���, ֧�ֳ�����ͣ����������Ϳ������
 *	#define CSL_STD_MATH
 *		��ѧ����, ֧�ָ������ͺ�λ�����Լ�ģ�廯����
 *	#define CSL_STD_FASTIO
 *		���׹���, ֧�������廪�Ŀ����������ģ��
 */

#define _TEMPLATE_CSL_VERSION 20150325C

#ifndef _TEMPLATE_CSL_STD
#define _TEMPLATE_CSL_STD 1

//@ C Library Wrappers
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <climits>
//@ Input / Output
#include <iostream>
//@ Math and Numerics
#include <algorithm>
//@ Other Utilities
#include <string>

#ifdef CSL_STD_CONTAINER
//@ Containers
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
//@ Other Utilities
#include <utility>
//@ define for pair
#define X				first
#define Y				second
#define mp(a,b)			make_pair(a,b)
typedef pair<int,int>	pii;
typedef vector<int>		vi;
typedef vector<pii>		vpii;
//@ define for iterator
#define op				begin()
#define ed				end()
#define tp(x)			__typeof((x).op)
	#define rop			rbegin()
	#define red			rend()
	#define rtp(x)		__typeof((x).rop)
#define all(x)			(x).op, (x).ed
//@ define for travel container
#define TRV(i,n)		for(tp(n) i=(n).op;i!=(n).ed;i++)
#define RTRV(i,n)		for(rtp(n) i=(n).rop;i!=(n).red;i++)
#endif /* CSL_STD_CONTAINER */

#ifdef CSL_STD_DEBUG
//@ C Library Wrappers
#include <ctime>
#include <cassert>
//@ Input / Output
#include <sstream>
#include <fstream>
//@ Math and Numerics
#include <limits>
//@ define for debug
#define PAUSE()		system("pause")
#define PRINT(x)	cout << #x << " = " << x << endl
#endif /* CSL_STD_DEBUG */

#ifdef CSL_STD_MATH
//@ Math and Numerics
#include <complex>
#include <numeric>
#include <bitset>
#include <functional>
#endif /* CSL_STD_MATH */

namespace csl
{
	//@ define for math calculate
	#define l(x)		((x)<<1)
	#define	r(x)		(l(x)^1)
	#define	u(x)		((x)>>1)
	#define eps			((1e-9))

	template<typename _Tp>
	_Tp
	sqr(_Tp x)
	{ return x * x; }

	template<typename _Tp>
	bool
	exmax(_Tp &a, const _Tp b)
	{ return (a < b) ? ((a = b) || 1) : (0); }

	template<typename _Tp>
	bool
	exmin(_Tp &a, const _Tp b)
	{ return (a > b) ? ((a = b) || 1) : (0); }

} // namespace csl

namespace csl
{
	//@ define for ACM/ICPC
	#define FOR(i,m,n)\
		for(int __s = (m),\
				__t = (n) + 1 - 2 * ((n) < (m)),\
				__d = 1 - 2 * ((n)<(m)),\
				i = __s;\
				i != __t;\
				i += __d)

	#define REP(i,n)\
		for(int __t = n,\
				i = 0;\
				i < __t;\
				i += 1)

	#define per(i,n)\
		for(int i = n - 1;\
				i >= 0;\
				i -= 1)

} // namespace csl

namespace csl
{
	//@ define for 64 bit integer
	typedef long long			Int64;
	typedef unsigned long long	uInt64;
	#define	 FMT				"%I64d"
	#ifdef	 unix
	#undef	 FMT
	#define	 FMT				"%lld"
	#endif

#ifdef CSL_STD_FASTIO
	class _fastio
	{
	// Name : Faster Input/Output �����������
	// Copyright : www.fateud.com, Thanks for deskmate ZRC's help (from THU)
	private	:
		const static size_t _size = 1 << 18;
		char _in[_size], _out[_size];
	public	:
		_fastio()
		{
			setvbuf(stdin, _in, _IOFBF, _size);
			setvbuf(stdout, _out, _IOFBF, _size);
		}
	} _io_hacker;
#endif /* CSL_STD_FASTIO */

	int
	getuint()
	{
		int ret = 0, vld = 0;
		while (true) {
			int ch = getchar() - 48;
			if (ch > -1 && ch < 10)
			{
				ret = (ret << 3) + (ret << 1) + ch,
				vld = 1;
			}
			else if (vld) break;
		}
		return ret;
	}
} // namespace csl

#endif	/* _TEMPLATE_CSL_STD */


//@ Using Namespace
using namespace std;
using namespace csl;

#define maxN 110
double f[maxN];

int main() {
	f[7] = 0.;
	f[8] = 1.;
	
	int t; cin >> t;
	while (t--) {
		int n; double p;
		cin >> n >> p;
		double q = 1. - p;

		for (int i = 9; i <= n; i++) {
			f[i] = f[i-1] + 1. / q;
		}

		printf("%.4f\n", f[n]);
	}
	return 0;
}
