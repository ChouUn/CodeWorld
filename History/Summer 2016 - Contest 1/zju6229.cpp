//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6229.cpp
 *  Date : 2016年7月22日 下午8:43:05
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 110;

#include <vector>
#include <algorithm>
namespace hungary {
  const int V = ::N * ::N / 2;
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

char g[N][N];
int f[N][N], h[N][N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n && n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, n) cin >> g[i];

    int m1 = 0, cnt = 0;
    rep(i, 0, n) {
      rep(j, 0, n)
        if (g[i][j] == 'S') f[i][j] = m1, cnt = 1;
        else if (cnt) ++m1, cnt = 0;
      if (cnt) ++m1, cnt = 0;
    }
    int m2 = 0;
    rep(j, 0, n) {
      rep(i, 0, n)
        if (g[i][j] == 'S') h[i][j] = m2, cnt = 1;
        else if (cnt) ++m2, cnt = 0;
      if (cnt) ++m2, cnt = 0;
    }

    hungary::build(m1);
    rep(i, 0, n) rep(j, 0, n)
      if (g[i][j] == 'S') hungary::add_edge(f[i][j], h[i][j]);
    hungary::query(m1, m2);
    cout << hungary::ans << endl;
  }
  return 0;
}
