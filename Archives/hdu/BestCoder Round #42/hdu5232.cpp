//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5232.cpp
 *  Date : 2015年11月24日 上午12:54:29
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    int ans = 2 * n;
    rep(i, 0, n) rep(j, 0, n) {
      int t; cin >> t;
      ans += t;
    }
    cout << ans << '\n';
  }
  return 0;
}
