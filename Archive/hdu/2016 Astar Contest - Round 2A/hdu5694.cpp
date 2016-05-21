//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5694.cpp
 *  Date : 2016年5月21日 下午7:48:09
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

ll solve(ll x, int y) {
  if (x == 0) return 0;
  if (x == 1) return y;
  ll m = 1;
  while (m < x) m = m * 2 + 1;
  ll p = m / 2, q = p / 2, res = q + 1 + y;
  return res + solve(x - p - 1, x - p - 1 <= q);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    ll l, r; cin >> l >> r;
    cout << solve(r, 1) - solve(l - 1, 1) << endl;
  }
  return 0;
}
