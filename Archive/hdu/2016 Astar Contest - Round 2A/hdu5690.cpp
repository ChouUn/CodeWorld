//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : hdu5690.cpp
 *  Date : 2016年5月21日 下午5:23:39
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ":\n";
    ll x, m, c, k; cin >> x >> m >> k >> c;
    // (10 ^ m - 1) / 9 = c (mod k)
    ll b = (csl::pow(1ll, 10ll, m, 9 * k) + 9 * k - 1) / 9;
    cout << (b * x % k == c ? "Yes" : "No") << endl;
  }
  return 0;
}
