//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6508.cpp
 *  Date : 2016年7月18日 上午9:49:17
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 1010;
vi g[N];
int d[N], e[N], v[N], f[N];

void dfs(int u) {
  v[u] = 1;
  for (auto v : g[u]) if (!::v[v]) dfs(v);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;

    memset(d, 0x00, sizeof d);
    memset(e, 0x00, sizeof e);
    memset(v, 0x00, sizeof v);
    rep(i, 0, n) g[i].clear(), f[i] = i;

    rep(i, 0, m) {
      int u, v; cin >> u >> v;
      ++d[--u], ++e[--v];
      g[u].push_back(v);
    }

    sort(f, f + n, [](int a, int b) -> bool {
      return e[a] != e[b] ? e[a] < e[b] : d[a] > d[b];
    });
    int ans = 0;
    rep(i, 0, n) if (!v[f[i]]) ++ans, dfs(f[i]);
    cout << ans << endl;
  }
  return 0;
}
