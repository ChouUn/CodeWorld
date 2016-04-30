/*
 *    Name : BC30A.cpp
 *    Author : CHN.ChouUn
 *    Date : 2015年2月14日 下午7:00:18
 *    Copyright : www.fateud.com
 *    Email : ChouUnSoft@gmail.com
 *    Description : None
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
//@ Stream And String Library
#include <string>
#include <cstring>
#include <complex>
#include <sstream>
#include <iostream>
using namespace std;
//@ Standard Template Library
#define mp(a,b)        make_pair(a,b)
#define X            first
#define Y            second
#define sz            size()
#define op            begin()
#define ed            end()
#define all(x)        (x).op, (x).ed
#define type(x)        __typeof((x).op)
    //@ reserve
    #define rop            rbegin()
    #define red            rend()
    #define rtype(x)    __typeof((x).rop)
#define inf(x)        push_front(x)
#define def()        pop_front()
#define inb(x)        push_back(x)
#define deb()        pop_back()
#define inc(x)        insert(x)
#define dec(x)        erase(x)
#define lb(x)        lower_bound(x)
#define ub(x)        upper_bound(x)
//@ Binary Tree Quickly Func
#define l(x)        ((x)<<1)
#define     r(x)        ((x)<<1|1)
#define     u(x)        ((x)>>1)
#define     lson(x)    l(x), (l), (mid)
#define     rson(x)    r(x), (mid + 1), (r)
#define     lowbit(x)    ((x)&-(x))
//@ For ACM/ICPC D.S.&A.
#define PAUSE()        system("pause")
#define PRINT(x)    cout << #x << " = " << x << endl
#define CLEAR(x,c)    memset(x,c,sizeof(x))
#define FOR(i,m,n)    for(int i=m;i!=(n+1-2*(n<m));i=i+1-2*(n<m))
#define REP(i,n)     for(__typeof(n) i=0;i<(n);i++)
#define REP1(i,n)     for(__typeof(n) i=1;i<=(n);i++)
#define RREP(i,n)    for(__typeof(n) i=(n)-1;i>=0;i--)
#define RREP1(i,n)    for(__typeof(n) i=(n);i>0;i--)
#define TRV(i,n)    for(type(n) i=(n).op;i!=(n).ed;i++)
#define RTRV(i,n)    for(rtype(n) i=(n).rop;i!=(n).red;i++)
//@ 64 Bit Integer for win/unix
#define     FMT        "%I64d"
#ifdef     unix
#undef     FMT
#define     FMT        "%lld"
#endif
//@ Mathematics && New Type
#define PI            3.14159265358979323846264338
#define EXP            2.71828182845904523536028747
#define     EPS        (1e-9)
typedef pair<int,int>            pii;
typedef vector<int>            vi;
typedef vector<pii>                vpii;
typedef long long                Int64;
typedef unsigned long long    uInt64;
template<typename T>    T sqr(T x) {return x * x;}
template<typename T>    bool exmax(T &a, T b) {return (b > a) ? (a = b) || 1 : 0;}
template<typename T>    bool exmin(T &a, T b) {return (b < a) ? (a = b) || 1 : 0;}
/*
    Name :
    Author : CHN.ChouUn
    Date : 09/02/15 11:43
    Copyright : www.fateud.com
    Email : ChouUnSoft@gmail.com
    Description : None
*/

#endif    /* _TEMPLATE_STANDARD */

#define maxN 110
typedef pair<Int64,int> pli;

int n;
Int64 val[maxN];

bool check(Int64 a, Int64 b, Int64 c) {
    if ((a + b) % INT_MAX == c)
        return 1;
    else
        return 0;
}

int main() {
    int Case = 0;
    while (scanf("%d", &n) != EOF) {
        REP(i,n) scanf(FMT, val + i);

        sort(val, val + n);
        vector<pli> data;
        REP(i,n) {
            if (i && val[i] == val[i-1]) {
                data.back().Y ++;
            }
            else {
                data.inb(mp(val[i], 1));
            }
        }

        int ans = 0, m = data.sz;
        if (m == 1) {
        	ans = -1;
        	goto end;
        }
        REP(i, m) {
            if (!i)
                ans += data[i].Y * check(data[m-1].X, data[i].X, data[i+1].X);
            else if (i == m - 1)
                ans += data[i].Y * check(data[i-1].X, data[i].X, data[0].X);
            else
                ans += data[i].Y * check(data[i-1].X, data[i].X, data[i+1].X);
        }
        end:;
        printf("Case #%d: %d\n", ++Case, ans);
    }
    return 0;
}
