//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : hdu3003.cpp
 *  Date : 2016年4月26日 下午12:56:31
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(ll n; cin >> n && n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cout << (csl::pow(1ll, 2ll, n - 1, n) + 1) % n << '\n';
  }
  return 0;
}
