//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1624.cpp
 *  Date : 2016年3月29日 下午6:00:26
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 210
#define M 210
typedef pair<int,list<int>> node;

int n, m;
int a[N], b[N], c[N];
vector<int> g[N];
int f[N][M], h[M];

inline void update(int& x, int y) {
  if (x == -1 || y < x) x = y;
}

node dfs(int u) {
  node ret;
  f[u][0] = a[u], fill_n(f[u] + 1, m, -1);
  rep(w, 0u, g[u].size()) {
    int v = g[u][w];
    node tmp = dfs(v);
    copy(f[u], f[u] + m + 1, h);
    fill(f[u], f[u] + m + 1, -1);
    rep(i, 0, m + 1) rep(j, 0, i + 1)
      if (~f[v][j] && ~h[i-j]) update(f[u][i], f[v][j] + h[i-j]);
    ret.first += tmp.first, ret.second.merge(tmp.second);
  }
  if (u) {
    int sum = ret.first + c[u], cnt = 0;
    update(f[u][++cnt], sum);
    for (auto i = ret.second.begin(); i != ret.second.end(); ++i)
      update(f[u][++cnt], sum += *i);
  }
  return ret.first += b[u], ret.second.merge(list<int>(1, c[u] - b[u])), ret;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> n >> m;
    rep(i, 0, n + 1) g[i].clear();
    rep(i, 1, n + 1) {
      int p; cin >> p;
      cin >> a[i] >> b[i] >> c[i];
      g[p].push_back(i);
      b[i] = min(a[i], b[i]);
    }

    a[0] = b[0] = c[0] = 0, dfs(0);
    int ans = -1;
    rep(i, 0, m + 1) if (~f[0][i]) update(ans, f[0][i]);
    cout << ans << endl;
  }
  return 0;
}
