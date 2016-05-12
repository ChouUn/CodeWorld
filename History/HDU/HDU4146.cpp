#define _USE_MATH_DEFINES
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
using namespace std;

typedef pair<int,int>       pii;
typedef vector<int>         vi;
typedef vector<pii>         vpii;
typedef long long           ll;
typedef unsigned long long  ull;

#ifdef _WIN32
#define i64         "%I64d"
#else
#define i64         "%lld"
#endif
#define rep(i,a,n)  for (int i=a;i<n;++i)
#define per(i,a,n) for (int i=n-1;i>=a;--i)
#define trv(i,n)    for (__typeof((n).end()) i=(n).begin();i!=(n).end();++i)
#define fi      first
#define se      second
#define pb      push_back
#define mp      make_pair
#define ms(x)   memset(x, 0x00, sizeof(x))
#define mod     (1000000007)
#define eps     (1e-9)

const int DX[] = {1,0,-1,0};
const int DY[] = {0,1,0,-1};
int _, __ = 0;
/*
 *  Name : HDU4146.cpp
 *  Date : 2015年7月18日 上午10:12:56
 *  Copyright : www.fateud.com
 *  Anti-Mage : The magic ends here.
 */
#define maxn 1010
char g[maxn][maxn];
int a[maxn], b[maxn];
int main() {
//  for (; scanf("%d", &_) != EOF; ) {
  for (scanf("%d", &_); _; _--) {
    printf("Case #%d: ", ++__);
    ms(a); ms(b);
    int n; scanf("%d", &n);
    rep(i, 0, n) scanf("%s", g[i]);
    int m; scanf("%d", &m);
    while (m--) {
      int x, y; scanf("%d%d", &x, &y);
      x--; y--; a[x] ^= 1; b[y] ^= 1;
    }
    int ans = 0;
    rep(i, 0, n) {
      rep(j, 0, n) {
        if ((a[i] + b[j]) & 1)
          ans += (g[i][j] == 'b');
        else
          ans += (g[i][j] == 'w');
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
