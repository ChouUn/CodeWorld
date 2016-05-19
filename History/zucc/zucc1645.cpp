//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1645.cpp
 *  Date : 2016年5月17日 下午9:06:25
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 510;
int a[N][N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    rep(i, 1, n + 1) rep(j, 1, m + 1) cin >> a[i][j];
    rep(i, 0, n + 1) rep(j, 0, m + 1)
      if (i && j) a[i][j] += max(a[i - 1][j], a[i][j - 1]);
      else a[i][j] = -INT_MAX / 2;
    cout << a[n][m] << endl;
  }
  return 0;
}
