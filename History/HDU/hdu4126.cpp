//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu4126.cpp
 *  Date : 2015年12月23日 下午8:25:23
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 3010;
int n, g[N][N], w[N], dp[N][N];
bool v[N], f[N][N];
vector<int> h[N];

void prim() {
  rep(i, 0, n) v[i] = 0, w[i] = 0;
  v[0] = true;
  rep(j, 1, n) {
    int k = 0;
    rep(i, 0, n) {
      if(v[i]) continue;
      if(g[k][w[k]] == -1 || (~g[i][w[i]] && g[i][w[i]] < g[k][w[k]])) k = i;
    }
    v[k] = true;
    rep(i, 0, n) {
      if(v[i]) continue;
      if(g[i][w[i]] == -1 || (~g[i][k] && g[i][k] < g[i][w[i]])) w[i] = k;
    }
  }
}

int cal(int a, int b) {
  return ~a && ~b ? min(a, b) : ~a ? a : b;
}

int dfs(int root, int u, int f) {
  int res = -1;
  rep(i, h[u].begin(), h[u].end()) {
    int v = *i;
    if(v == f) continue;
    int tmp = dfs(root, v, u);
    res = cal(res, tmp);
    dp[u][v] = dp[v][u] = cal(tmp, dp[u][v]);
  }
  if(root != f) res = cal(res, g[root][u]);
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int m; cin >> m;
    if(n == 0 && m == 0) break;

    rep(i, 0, n) rep(j, 0, n) g[i][j] = dp[i][j] = -1, f[i][j] = false;
    while(m--) { int u, v, w; cin >> u >> v >> w; g[u][v] = g[v][u] = w; }

    prim();
    rep(i, 0, n) h[i].clear();
    int cnt = 0;
    rep(i, 1, n) {
      int u = i, v = w[i];
      h[u].push_back(v), h[v].push_back(u);
      f[u][v] = f[v][u] = true, cnt += g[u][v];
    }

    rep(i, 0, n) dfs(i, i, -1);

    int q; cin >> q;
    double ans = 0;
    rep(i, 0, q) {
      int u, v, w; cin >> u >> v >> w;
      ans += f[u][v] ? cnt - g[u][v] + cal(dp[u][v], w) : cnt;
    }
    cout.setf(ios::fixed);
//    cout << setprecision(4) << ans / q << endl;
    printf("%.4f\n", ans / q);
  }
  return 0;
}
