//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6227.cpp
 *  Date : 2016年7月22日 下午1:50:30
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 810;
int n, m, k;
vpii g[N];

bool vis[N];
bool check(int lo, int hi) {
  fill_n(vis + 1, n, false);
  queue<int> p, q;
  vis[1] = true, p.push(1);
  rep(i, 0, k + 1) {
    if (i) {
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto ui : g[u]) {
          int v = ui.first;
          if (!vis[v]) vis[v] = true, p.push(v);
        }
      }
    }
    while (!p.empty()) {
      int u = p.front(); p.pop(); q.push(u);
      for (auto ui : g[u]) {
        int v = ui.first, w = ui.second;
        if (!vis[v] && lo <= w && w <= hi) vis[v] = true, p.push(v);
      }
    }
  }
  return vis[n];
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> n >> m >> k;
    rep(i, 1, n + 1) g[i].clear();

    vi h; h.reserve(m);
    while (m--) {
      int u, v, w; cin >> u >> v >> w;
      g[u].push_back(make_pair(v, w));
      g[v].push_back(make_pair(u, w));
      h.push_back(w);
    }
    sort(h.begin(), h.end());
    h.resize(unique(h.begin(), h.end()) - h.begin());

    int ans = h.back() - h.front();
    for (int l = 0, r = 0, m = h.size(); r < m; ++l, r = max(l, r)) {
      while (r < m && !check(h[l], h[r])) ++r;
      if (r < m) ans = min(ans, h[r] - h[l]);
    }
    cout << ans << endl;
  }
  return 0;
}
