//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju3927.cpp
 *  Date : 2016年4月12日 上午12:23:25
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
    int x, y = 0;
    rep(i, 0, 4) cin >> x, y += x;
    cout << (y >= 80 ? "Yes\n" : "No\n");
  }
  return 0;
}
