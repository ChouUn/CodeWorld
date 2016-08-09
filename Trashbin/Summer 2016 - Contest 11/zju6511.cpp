//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6511.cpp
 *  Date : 2016年7月18日 上午9:39:36
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
    ull n; cin >> n;
    cout << 63 - __builtin_clzll(n) << endl;
  }
  return 0;
}
