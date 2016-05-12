//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1520.cpp
 *  Date : 2016年5月13日 上午3:58:16
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 6010;
vi g[N];
int d[N], v[N], dp[N][2];

void dfs(int u) {
  dp[u][0] = 0, dp[u][1] = v[u];
  for (auto &v : g[u]) {
    dfs(v);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += dp[v][0];
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 1, n + 1) g[i].clear(), d[i] = 0;
    rep(i, 1, n + 1) cin >> v[i];
    for (int x, y; cin >> x >> y && x && y; ) g[y].push_back(x), ++d[x];

    int ans = 0;
    rep(i, 1, n + 1) if (!d[i]) dfs(i), ans += max(dp[i][0], dp[i][1]);
    cout << ans << endl;
  }
  return 0;
}
