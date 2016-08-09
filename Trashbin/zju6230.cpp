//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6230.cpp
 *  Date : 2016年7月23日 下午1:23:48
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 510;
int g[N][N];
vi h[N];
bool f[N][N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) cin >> g[i][j];

    vpii v;
    rep(i, 0, n) rep(j, 0, m) v.push_back(pii(i, j));
    sort(v.begin(), v.end(), [](const pii& a, const pii& b) -> bool {
      return g[a.first][a.second] > g[b.first][b.second];
    });

    rep(i, 0, n) h[i].clear();
    rep(i, 0, m) rep(j, 0, m) f[i][j] = false;
    int ans = -1;
    for (auto p : v) {
      int x = p.first, y = p.second;
      for (auto z : h[x]) {
        if (f[y][z]) { ans = g[x][y]; break; }
        f[y][z] = f[z][y] = true;
      }
      if (~ans) break;
      h[x].push_back(y);
    }
    cout << ans << endl;
  }
  return 0;
}
