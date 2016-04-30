//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1520.cpp
 *  Date : 2016年3月23日 下午6:49:30
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 6010
int w[N], d[N];
vi g[N];
int f[N][2];

void dfs(int u) {
  f[u][0] = 0;
  f[u][1] = w[u];
  for (auto &v : g[u]) {
    dfs(v);
    f[u][0] += max(f[v][0], f[v][1]);
    f[u][1] += f[v][0];
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, n) cin >> w[i], d[i] = 0, g[i].clear();
    for (int x, y; cin >> x >> y, x && y; ) g[--y].push_back(--x), ++d[x];
    int ans = 0;
    rep(i, 0, n) if (!d[i]) {
      dfs(i);
      ans += max(f[i][0], f[i][1]);
    }
    cout << ans << endl;
  }
  return 0;
}
