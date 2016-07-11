//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6260.cpp
 *  Date : 2016年7月6日 上午10:23:08
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
    int n; cin >> n;
    rep(i, 0, n) {
      int a, b, c; cin >> a >> b >> c;
      int res = a * 2 * (c / 2);
      if (c & 1) res += (a - b) * 2;
      cout << res << (i == n - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
