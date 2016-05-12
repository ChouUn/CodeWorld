#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
using namespace std;

typedef pair<int,int>   pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef long long       int64;

#ifdef _WIN32
#define i64         "%I64d"
#else
#define i64         "%lld"
#endif

#define rep(i,a,n)  for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define trv(i,n)    for (__typeof((n).end()) i=(n).begin(); i!=(n).end(); i++)
#define pb(x)       push_back(x)
#define mp(x,y)     make_pair(x,y)
#define ms(x)       memset(x, sizeof(x));
#define sz(x)       (int)((x).size())

#define mod         1000000007
#define eps         1e-9
const int DX[]      = {1,0,-1,0};
const int DY[]      = {0,1,0,-1};
int _, __;
/*
 *  Name : HDU1213.cpp
 *  Date : 2015年6月4日 下午4:12:00
 *  Copyright : www.fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxN 1010
int f[maxN];

int find(int u) {
  return (u == f[u]) ? (u) : (f[u] = find(f[u]));
}

int main() {
  for (int n; scanf("%d", &n) != EOF && n; ) {
//  for (scanf("%d", &_); _; _--) {
    //printf("Case #%d:\n", __++);
    int m; scanf("%d", &m);
    rep(i, 1, n + 1) f[i] = i;
    int ans = n;
    while (m--) {
      int u, v; scanf("%d%d", &u, &v);
      int x = find(u), y = find(v);
      if (x == y) continue;
      f[x] = y; ans--;
    }
    printf("%d\n", ans - 1);
  }
  return 0;
}
