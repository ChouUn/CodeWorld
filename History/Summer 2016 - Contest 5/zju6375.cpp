//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : zju6375.cpp
 *  Date : 2016年7月10日 上午10:05:50
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
    ll k, p, q, l, r; cin >> k >> p >> q >> l >> r;
    int ans = 0;
    rep(i, 0, 82) {
      ll a = p * csl::pow(ll(1), ll(i), k) + q;
      int b = a, s = 0;
      while (b) s += b % 10, b /= 10;
      ans += (s == i && l <= a && a <= r);
    }
    cout << ans << endl;
  }
  return 0;
}
