//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1081.cpp
 *  Date : 2016年5月20日 下午2:06:48
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 110;
int a[N][N], f[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 1, n + 1) rep(j, 1, n + 1) cin >> a[i][j];

    int ans = a[1][1];
    rep(i, 1, n + 1) rep(j, 1, n + 1) ans = max(ans, a[i][j]);
    rep(i, 1, n + 1) rep(j, 1, n + 1) a[i][j] += a[i][j - 1];
    rep(j, 0, n) rep(k, j + 1, n + 1) {
      rep(i, 1, n + 1) f[i] = a[i][k] - a[i][j], f[i] += f[i - 1];
      int mi = f[0];
      rep(i, 1, n + 1) ans = max(ans, f[i] - mi), mi = min(mi, f[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
