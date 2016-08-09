//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6208.cpp
 *  Date : 2016年7月5日 上午9:19:22
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 510;
int n, m, g[N][N];

bool check(int x) {
  rep(i, 0, n) rep(j, 0, m) {
    if (g[i][j] < x) continue;
    rep(p, 0, n) {
      if (i == p) continue;
      if (g[p][j] < x) continue;
      rep(q, 0, m) {
        if (j == q) continue;
        if (g[i][q] < x) continue;
        if (g[p][q] < x) continue;
        return true;
      }
    }
  }
  return false;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) cin >> g[i][j];
    int l = 0, r = 1e9 + 10;
    while (l < r) {
      int x = (l + r) / 2 + 1;
      if (check(x)) l = x;
      else r = x - 1;
    }
    cout << l << endl;
  }
  return 0;
}
