//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5695.cpp
 *  Date : 2016年5月21日 下午8:26:33
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
vector<int> g[N];
int h[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    rep(i, 1, n + 1) g[i].clear(), h[i] = 0;
    while (m--) {
      int u, v; cin >> u >> v;
      g[u].push_back(v), ++h[v];
    }

    priority_queue<int> q;
    rep(i, 1, n + 1) if (!h[i]) q.push(i);
    ll ans = 0; int mi = n + 1;
    while (!q.empty()) {
      int u = q.top(); q.pop();
      mi = min(mi, u), ans += mi;
      for (auto v : g[u]) if (--h[v] == 0) q.push(v);
    }
    cout << ans << endl;
  }
  return 0;
}
