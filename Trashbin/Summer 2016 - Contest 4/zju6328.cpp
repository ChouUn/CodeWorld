//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6328.cpp
 *  Date : 2016年7月8日 上午8:42:13
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 310;
char g[N][N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> g[i];

    bool flag = g[0][0] == g[0][1];
    rep(i, 0, n) {
      if (g[i][i] != g[0][0]) flag = true;
      if (g[i][n-1-i] != g[0][0]) flag = true;
    }
    rep(i, 0, n) rep(j, 0, n) {
      if (i == j || n - 1 - i == j) continue;
      if (g[i][j] != g[0][1]) flag = true;
    }
    cout << (flag ? "NO" : "YES") << endl;
  }
  return 0;
}
