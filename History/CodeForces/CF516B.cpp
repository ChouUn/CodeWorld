/*
 *	Name : CF516B.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年2月18日 上午1:21:42
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

/*
 *	Name : standard.h 纸农の标准库
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */
#ifndef _TEMPLATE_STANDARD
#define _TEMPLATE_STANDARD 1

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <numeric>
#include <algorithm>
#include <functional>
//@ Standard Template Library
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
//@ Stream and String Library
#include <string>
#include <cstring>
#include <complex>
#include <sstream>
#include <iostream>
using namespace std;
//@ Standard Template Library
#define mp(a,b)		make_pair(a,b)
#define X			first
#define Y			second
#define sz			size()
#define op			begin()
#define ed			end()
#define all(x)		(x).op, (x).ed
#define type(x)		__typeof((x).op)
	//@ Reserve_Iterator
	#define rop			rbegin()
	#define red			rend()
	#define rtype(x)	__typeof((x).rop)
#define inf(x)		push_front(x)
#define inb(x)		push_back(x)
#define def()		pop_front()
#define deb()		pop_back()
#define inc(x)		insert(x)
#define dec(x)		erase(x)
#define lb(x)		lower_bound(x)
#define ub(x)		upper_bound(x)
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
#define FOR(i,m,n)	for(int i=m;i!=(n+1-2*(n<m));i=i+1-2*(n<m))
#define REP(i,n) 	for(__typeof(n) i=0;i<(n);i++)
#define REP1(i,n) 	for(__typeof(n) i=1;i<=(n);i++)
#define RREP(i,n)	for(__typeof(n) i=(n)-1;i>=0;i--)
#define RREP1(i,n)	for(__typeof(n) i=(n);i>0;i--)
#define TRV(i,n)	for(type(n) i=(n).op;i!=(n).ed;i++)
#define RTRV(i,n)	for(rtype(n) i=(n).rop;i!=(n).red;i++)
//@ 64 Bit Integer for win/unix
#define	 FMT		"%I64d"
#ifdef	 unix
#undef	 FMT
#define	 FMT		"%lld"
#endif
//@ Mathematics && New Type
#define PI			3.14159265358979323846264338
#define EXP			2.71828182845904523536028747
#define	EPS			(1e-9)
typedef pair<int,int>		pii;
typedef vector<int>			vi;
typedef vector<pii>			vpii;
typedef long long			Int64;
typedef unsigned long long	uInt64;
template<typename T> T sqr(T x) {return x * x;}
template<typename T> bool exmax(T &a, T b) {return (b > a) ? (a = b) || 1 : 0;}
template<typename T> bool exmin(T &a, T b) {return (b < a) ? (a = b) || 1 : 0;}

#endif	/* _TEMPLATE_STANDARD */


#define maxN 2010

const int dir[][2] = {
	{-1, 0}, {1, 0}, {0, -1}, {0, 1},
};

int n, m;
char s[maxN][maxN];
int f[maxN][maxN];

void mul(int i, int j) {
	REP(k,4) {
		int x = i + dir[k][0];
		int y = j + dir[k][1];
		if (x < 0 || y < 0) continue;
		f[x][y] ++;
	}
}

int main() {
	// Input
	CLEAR(s,'*');
	cin >> n >> m;
	REP1(i,n) {
		scanf("%s", s[i] + 1);
		s[i][m+1] = '*';
	}

	// Init
	REP(i,n+2) {
		REP(j,m+2) {
			if (s[i][j] == '*') mul(i,j);
		}
	}

//	REP1(i,n) {
//		REP1(j,m) cout << f[i][j] << ' ';
//		cout << endl;
//	}

	queue<pii> p;

	REP1(i,n) REP1(j,m) {
		if (s[i][j] == '.') {
			if (f[i][j] > 3) {
				cout << "Not unique" << endl;
				exit(0);
			}
			if (f[i][j] == 3) p.push(mp(i,j));
		}
	}

	// Solve
	while (!p.empty()) {
		int sx = p.front().X;
		int sy = p.front().Y;
		p.pop(); if (s[sx][sy] != '.') continue;

		int d = -1;
		REP(k,4) {
			int tx = sx + dir[k][0];
			int ty = sy + dir[k][1];
			if (s[tx][ty] == '.') d = k;
		}
		if (d == -1) {
			cout << "Not unique" << endl;
			return 0;
		}

		int tx = sx + dir[d][0];
		int ty = sy + dir[d][1];
		switch (d) {
			case 0 : s[sx][sy] = 'v'; s[tx][ty] = '^'; break;
			case 1 : s[sx][sy] = '^'; s[tx][ty] = 'v'; break;
			case 2 : s[sx][sy] = '>'; s[tx][ty] = '<'; break;
			case 3 : s[sx][sy] = '<'; s[tx][ty] = '>'; break;
		}
		mul(sx, sy); mul(tx, ty);
		REP(k,4) {
			int dx = sx + dir[k][0];
			int dy = sy + dir[k][1];
			if (dx < 0 || dy < 0) continue;
			if (f[dx][dy] == 3 && s[dx][dy] == '.') p.push(mp(dx, dy));
		}
		REP(k,4) {
			int dx = tx + dir[k][0];
			int dy = ty + dir[k][1];
			if (dx < 0 || dy < 0) continue;
			if (f[dx][dy] == 3 && s[dx][dy] == '.') p.push(mp(dx, dy));
		}
	}

	REP1(i,n) {
		REP1(j,m) {
			if (s[i][j] == '.') {
				cout << "Not unique" << endl;
				return 0;
			}
		}
	}

	// Output
	REP1(i,n) {
		REP1(j,m)
			putchar(s[i][j]);
		puts("");
	}
//	REP1(i,n) {
//		REP1(j,m) cout << f[i][j] << ' ';
//		cout << endl;
//	}
	return 0;
}
