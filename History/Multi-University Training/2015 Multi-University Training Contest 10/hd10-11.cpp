#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int,int>  pii;
typedef std::vector<int>    vi;
typedef std::vector<pii>    vpii;
typedef long long           ll;
typedef unsigned long long  ull;
#ifdef _WIN32
#define i64         "%I64d"
#else
#define i64         "%lld"
#endif
#define rep(i,a,n)  for (int i=(a);i<(n);++i)
#define per(i,a,n) for (int i=(n)-1;i>=(a);--i)
#define pb      push_back
#define mp      make_pair
#define mod     (1000000007)
#define eps     (1e-9)
/*
 *  Name : hd10-11.cpp
 *  Date : 2015年8月20日 下午3:05:09
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 100010
int n;
vector<pii> g[maxn];
int f[maxn], p[maxn];

void bfs(int s) {
  queue<int> q;
  q.push(s); p[s] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    rep(i, 0, (int)g[u].size()) {
      int v = g[u][i].first;
      int w = g[u][i].second;
      if (v == p[u]) continue;
      q.push(v);
      f[v] = f[u] ^ w;
      p[v] = u;
    }
  }
}

int nn, a[maxn], b[maxn];
int find(int x) {
  int l = 1, r = nn;
  while (l < r) {
    int m = (l + r) >> 1;
    if (x > a[m]) l = m + 1;
    else r = m;
  }
  return x == a[l] ? b[l] : 0;
}

//@ Main Function
int main() {
  int _;
  //for (; scanf("%d", &_) != EOF; ) {
  for (scanf("%d", &_); _; _--) {
    //printf("Case #%d:\n", ++__);
	scanf("%d", &n);
	rep(i, 1, n+1) g[i].clear();
	rep(i, 1, n) {
	  int u, v, w; scanf("%d%d%d", &u, &v, &w);
	  g[u].push_back(make_pair(v, w));
	  g[v].push_back(make_pair(u, w));
	}

	f[1] = 0;
	bfs(1);

	rep(i, 1, n+1) a[i] = f[i];
	sort(a+1, a+n+1);

	nn = 1; b[1] = 1;
	rep(i, 2, n+1) {
	  if (a[i] == a[nn]) ++b[nn];
	  else ++nn, a[nn] = a[i], b[nn] = 1;
	}

	int m; scanf("%d", &m);
	while (m--) {
	  int x; scanf("%d", &x);
	  ll ans = 0;
	  if (x == 0)
	    rep(i, 1, nn+1) ans += b[i] * (b[i] + 1ll);
	  else
	    rep(i, 1, n+1) ans += find(f[i] ^ x);
	  printf(i64 "\n", ans / 2);
	}
  }
  return 0;
}
