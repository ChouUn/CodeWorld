//@ Including Header
#include <csl_std.h>

/**
 *  Name : L3-2.cpp
 *  Date : 2016年6月4日 下午1:03:46
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 10010;
vi g[N]; int vis[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, k; cin >> n >> m >> k;
  rep(i, 0, m) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  while (k--) {
    memset(vis, 0x00, sizeof vis);
    int x; cin >> x; vis[x] = 1;
    auto ans = make_pair(n + 1, x);
    queue<pii> q; q.push(ans);
    while (!q.empty()) {
      auto u = q.front(); q.pop();
      for (auto &i : g[u.second]) {
        if (vis[i]) continue; vis[i] = true;
        auto v = make_pair(u.first - 1, i);
        if (v < ans) ans = v;
        q.push(v);
      }
    }
    if (ans.second == x) cout << 0 << endl;
    else cout << ans.second << endl;
  }
  return 0;
}
