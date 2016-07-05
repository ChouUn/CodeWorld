//@ Including Header
#include <csl_std.h>

/**
 *  Name : jsk 2016 - R7A.cpp
 *  Date : 2016年7月3日 下午1:40:31
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 310;
const int M = 10;
const int oo = INT_MAX / 2;
int n, g[N][N];
int f[M][N][N];
ll ans;

void floyd(int id, int l, int r) {
  rep(k, l, r + 1) rep(i, 0, n) rep(j, 0, n)
    if (f[id][i][k] + f[id][k][j] < f[id][i][j])
      f[id][i][j] = f[id][i][k] + f[id][k][j];
}

void dfs(int id, int l, int r) {
  if (l == r) {
    rep(i, 0, n) if (i != l) {
      rep(j, 0, n) if (j != l && i != j) {
        ans += (f[id][i][j] >= oo ? -1 : f[id][i][j]);
      }
    }
    return;
  }
  int m = (l + r) / 2;
  rep(i, 0, n) rep(j, 0, n) f[id + 1][i][j] = f[id][i][j];
  floyd(id + 1, l, m);
  dfs(id + 1, m + 1, r);

  rep(i, 0, n) rep(j, 0, n) f[id + 1][i][j] = f[id][i][j];
  floyd(id + 1, m + 1, r);
  dfs(id + 1, l, m);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  rep(i, 0, n) rep(j, 0, n) cin >> g[i][j];
  rep(i, 0, n) rep(j, 0, n) if (g[i][j] == -1) g[i][j] = oo;

  rep(i, 0, n) rep(j, 0, n) f[0][i][j] = g[i][j];
  ans = 0;
  dfs(0, 0, n - 1);
  cout << ans << endl;

  return 0;
}
