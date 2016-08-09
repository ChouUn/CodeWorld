#include <vector>
#include <algorithm>

namespace hungary {
  const int V;
  std::vector<int> g[V];
  int match[V], ans; bool vis[V];
  void build(int n) {
    for (int i = 0; i < n; ++i) g[i].clear();
  }
  inline void add_edge(int u, int v) {
    g[u].push_back(v);
  }
  bool aug(int u) {
    for (auto v : g[u]) if (!vis[v]) {
      vis[v] = true;
      if (!~match[v] || aug(match[v])) return match[v] = u, true;
    }
    return false;
  }
  void query(int n, int m) {
    std::fill_n(match, m, -1), ans = 0;
    for (int i = 0; i < n; ++i) std::fill_n(vis, m, false), ans += aug(i);
  }
};
