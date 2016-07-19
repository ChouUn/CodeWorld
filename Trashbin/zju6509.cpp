//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6509.cpp
 *  Date : 2016年7月18日 上午11:33:27
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 2010;
int g[N][N];
double f[N][N];

double solve(double a, double b) {
  // a + ab + b - ab = a + b
  return (1 + b) * a + b * (1 - a);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) cin >> g[i][j];
    rep(i, 0, n) rep(j, 0, m) if (i || j) {
      int a = g[0][0] + 1 - i - j;
      int b = g[i][j];
      if (a <= 0) f[i][j] = 0;
      else f[i][j] = a * 1. / (a + b);
    }
    double ans = 0;
    rep(i, 0, n) rep(j, 0, m) if (i || j) {
      if (i + j > g[0][0]) continue;
      double cnt = 0;
      if (i) cnt = max(cnt, solve(f[i][j], f[i - 1][j]));
      if (j) cnt = max(cnt, solve(f[i][j], f[i][j - 1]));
      f[i][j] = cnt;
      ans = max(ans, cnt);
    }
    cout << fixed << setprecision(8) << ans << endl;
  }
  return 0;
}
