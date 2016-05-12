//@ Including Header
#include <csl_std.h>

/**
 *  Name : fhc2016-1d.cpp
 *  Date : 2016年1月9日 下午1:48:57
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

struct node {
  int s[26], cnt;
  node() : cnt() { memset(s, 0x00, sizeof s); }
};

#define maxn 310
#define maxm 100010
node g[maxm]; int gn;
char s[maxm];
int n, k, f[maxm][maxn];

void build(int m, char* p) {
  if(!*p) { ++g[m].cnt; return; }
  int c = *p - 'a';
  if(!g[m].s[c]) g[gn] = node(), g[m].s[c] = gn++;
  build(g[m].s[c], p + 1);
}

void dfs(int u) {
  memset(f[u], 0x3f, sizeof f[u]);
  rep(i, 0, g[u].cnt + 1) f[u][i] = i;
  rep(i, 0, 26) {
    int v = g[u].s[i];
    if(!v) continue;
    dfs(v);
    per(p, 0, k + 1) rep(q, 0, p + 1) {
      f[u][p] = min(f[u][p], f[v][q] + f[u][p - q] + 2);
    }
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    cin >> n >> k;
    gn = 1; g[0] = node();
    rep(i, 0, n) cin >> s, build(0, s);

    dfs(0);
    std::cout << "Case #" << __ << ": " << f[0][k] << endl;
  }
  return 0;
}
