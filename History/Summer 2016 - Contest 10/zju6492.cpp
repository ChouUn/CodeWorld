//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6492.cpp
 *  Date : 2016年7月17日 上午8:22:36
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
    int n, m; cin >> n >> m;
    cout << ((n & 1) && (m & 1) ? "Alice" : "Bob") << endl;
  }
  return 0;
}
