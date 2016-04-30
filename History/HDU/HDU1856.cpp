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
#define rrep(i,a,n) for (int i=n-1;i>=a;--i)
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
 *  Name : HDU1856.cpp
 *  Date : 2015年7月15日 下午4:03:22
 *  Copyright : www.fateud.com
 *  Anti-Mage : The magic ends here.
 */
#define maxn 100010

int r[maxn<<1], s[maxn<<1];
int find(int x) {
  return x == r[x] ? x : r[x] = find(r[x]);
}
bool merge(int u, int v) {
  if (u != v) {
    r[v] = u;
    return true;
  }
  return false;
}

map<int,int> trans_map;
int trans(int x) {
  static map<int,int>::iterator it;
  it = trans_map.find(x);
  if (it != trans_map.end()) return it->se;
  int index = trans_map.size();
  r[index] = index; s[index] = 1;
  return trans_map[x] = index;
}

int main() {
  for (int n; scanf("%d", &n) != EOF; ) {
    trans_map.clear();
    int ans = 1;
    rep(i, 0, n) {
      int u, v; scanf("%d%d", &u, &v);
      u = find(trans(u)); v = find(trans(v));
      if (merge(u, v)) s[u] += s[v];
      if (s[u] > ans) ans = s[u];
    }
    printf("%d\n", ans);
  }
  return 0;
}
