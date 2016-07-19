//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6567.cpp
 *  Date : 2016年7月19日 上午9:43:24
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 310;
double dp[2][N][N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    double p, q; cin >> p >> q;

    memset(dp[0], 0, sizeof dp[0]);
    dp[0][0][n] = 1;
    rep(k, 0, m) {
      auto g = dp[k&1], h = dp[(k&1)^1];
      memset(h, 0, sizeof dp[0]);
      rep(i, 0, n + 1) rep(j, 0, n + 1) {
        if (!g[i][j]) continue;
        if (i || j) {
          if (j) {
            double l = j * 1. / (i + j);
            h[i][j - 1] += g[i][j] * p * l;
            h[i + 1][j - 1] += g[i][j] * q * l;
          }
          if (i) {
            double l = i * 1. / (i + j);
            h[i - 1][j] += g[i][j] * (p + q) * l;
          }
          h[i][j] += g[i][j] * (1 - p - q);
        }
        else
          h[i][j] += g[i][j];
      }
//      rep(i, 0, n + 1) { rep(j, 0, n + 1) cout << h[i][j] << " "; cout << endl; } cout << endl;
    }
    auto f = dp[m&1];
    double ans = 0;
    rep(i, 0, n + 1) rep(j, 0, n + 1) if (f[i][j]) ans += (n - i - j) * f[i][j];
    cout << fixed << setprecision(6) << ans << endl;
  }
  return 0;
}
