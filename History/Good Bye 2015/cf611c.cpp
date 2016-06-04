//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf611c.cpp
 *  Date : 2015年12月30日 下午11:26:10
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

int n, m;
char g[510][510];
int u[510][510], v[510][510];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;
  rep(i, 1, n + 1) rep(j, 1, m + 1) cin >> g[i][j];
  rep(i, 1, n + 1) rep(j, 1, m + 1) {
    u[i][j] = (g[i][j] == '.' && g[i - 1][j] == '.') + u[i - 1][j] + u[i][j - 1] - u[i - 1][j - 1];
    v[i][j] = (g[i][j] == '.' && g[i][j - 1] == '.') + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
  }

  int q; cin >> q;
  while(q--) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int x = u[x2][y2] - u[x1][y2] - u[x2][y1 - 1] + u[x1][y1 - 1];
    int y = v[x2][y2] - v[x1 - 1][y2] - v[x2][y1] + v[x1 - 1][y1];
    cout << x + y << endl;
  }
  return 0;
}
