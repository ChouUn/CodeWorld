//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6325.cpp
 *  Date : 2016年7月8日 上午8:55:12
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 510;
int g[N][N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    rep(i, 1, n + 1) rep(j, 1, m + 1) cin >> g[i][j];

    int q; cin >> q;
    while (q--) {
      int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
      int ans = 0;
      rep(i, x0, x1 + 1) rep(j, y0, y1 + 1) {
        if (i + 1 != i_n && g[i][j] && g[i + 1][j]) ++ans;
        if (j + 1 != j_n && g[i][j] && g[i][j + 1]) ++ans;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
