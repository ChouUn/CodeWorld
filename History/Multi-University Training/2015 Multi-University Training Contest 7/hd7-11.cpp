#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _USE_MATH_DEFINES
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef std::pair<int,int>  pii;
typedef std::vector<int>    vi;
typedef std::vector<pii>    vpii;
typedef long long           ll;
typedef unsigned long long  ull;
#ifdef _WIN32
#define i64     	"%I64d"
#else
#define i64     	"%lld"
#endif
#define rep(i,a,n)  for (int i=(a);i<(n);++i)
#define rrep(i,a,n) for (int i=(n)-1;i>=(a);--i)
#define pb      push_back
#define mp      make_pair
#define mod     (1000000007)
#define eps     (1e-9)
/*
 *  Name : hd7-11.cpp
 *  Date : 2015年8月11日 下午3:23:58
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */
#define maxn 100010
vi g[maxn];
ll f[maxn], fac[maxn];
int h[maxn];
bool dfs(int u, int p) {
  ll res = 1; h[u] = 1;
  int cnt1 = 0, cnt2 = 0;
  rep(i, 0, (int)g[u].size()) {
    int v = g[u][i];
    if (v == p) continue;
    if (!dfs(v, u)) return 0;
    if (h[v] == 1) ++cnt1;
    else ++cnt2, res = res * f[v] % mod;
    if (cnt2 > 2) return 0;
    h[u] += h[v];
  }
  f[u] = (cnt2) ? (2 * res % mod * fac[cnt1] % mod) : fac[cnt1];
  return 1;
}

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, maxn) fac[i] = fac[i-1] * i % mod;
  int _, __ = 0;
  //for (; scanf("%d", &_) != EOF; ) {
  for (scanf("%d", &_); _; _--) {
    printf("Case #%d: ", ++__);
	int n; scanf("%d", &n);
	rep(i, 1, n+1) g[i].clear();
	rep(i, 1, n) {
	  int u, v; scanf("%d%d", &u, &v);
	  g[u].push_back(v);
	  g[v].push_back(u);
	}
	ll ans = (n == 1) ? (1) : (dfs(1, 0) ? (f[1] * 2 % mod) : (0));
	printf(i64 "\n", ans);
  }
  return 0;
}
