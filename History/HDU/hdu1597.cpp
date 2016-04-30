//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1597.cpp
 *  Date : 2016年4月26日 下午5:20:09
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    ll n; cin >> n;
    ll m = sqrt(n * 2) - 1, s = m * (m + 1) / 2;
    while (s + (m + 1) <= n) s += ++m;
    int ans = (n - s - 1) % 9 + 1;
    if (s == n) ans = (m - 1) % 9 + 1;
    cout << ans << endl;
  }
  return 0;
}
