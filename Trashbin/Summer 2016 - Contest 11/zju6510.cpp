//@ Including Header
#include <csl_std.h>
#include <graph.h>

/**
 *  Name : zju6510.cpp
 *  Date : 2016年7月18日 上午9:49:17
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 1010;
const int M = 5010;
int a[M], b[M];
vi g[N];
int p[N][N];

int mat[N], chk[N];
bool dfs(int u) {
  for (auto v : g[u]) if (!chk[v]) {
    chk[v] = true;
    if (mat[v] == -1 || dfs(mat[v]))
      return mat[v] = u, true;
  }
  return false;
}
int hungarian(int n) {
  int ans = 0;
  memset(mat, -1, sizeof(mat));
  for (int u = 0; u < n; ++u)
    if (mat[u] == -1) {
      memset(chk, 0, sizeof(chk));
      if (dfs(u)) ++ans;
    }
  return ans;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    rep(i, 0, m) cin >> a[i] >> b[i], --a[i], --b[i];

    csl::graph<int> G;
    G.build(n, m);
    rep(i, 0, m) G.add_edge(a[i], b[i], 1);
    csl::tarjan<int> tarjan;
    tarjan.scc(G);

    int nn = tarjan.size();
    rep(i, 0, nn) rep(j, 0, nn) p[i][j] = 0;
    rep(i, 0, m) {
      int u = tarjan[a[i]], v = tarjan[b[i]];
      if (u == v) continue;
      if (p[u][v]) continue;
      p[u][v] = 1;
    }
    rep(i, 0, nn) g[i].clear();
    rep(i, 0, nn) rep(j, 0, nn) if (p[i][j]) g[i].push_back(j);

    cout << nn - hungarian(nn) << endl;
  }
  return 0;
}
