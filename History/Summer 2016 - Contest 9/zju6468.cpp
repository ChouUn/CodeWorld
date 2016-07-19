//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6468.cpp
 *  Date : 2016年7月15日 上午3:29:27
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
    rep(i, 0, 38) { int x; cin >> x; }
    int m1, m2, c1, c2, c3, s; cin >> m1 >> m2 >> c1 >> c2 >> c3 >> s;
    int ans = INT_MIN;
    ans = max(ans, 5 * -11 * c3);
    ans = max(ans, 5 * -13 * c3 + 3 * s);
    ans = max(ans, (5 * c1 - 11 * c3) * 5 + -2 * m1);
    ans = max(ans, (3 * c2 - 13 * c3) * 5 + -2 * m2 + 3 * s);
    cout << ans << endl;
  }
  return 0;
}

