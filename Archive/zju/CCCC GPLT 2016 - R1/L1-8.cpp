//@ Including Header
#include <csl_std.h>

/**
 *  Name : L1-8.cpp
 *  Date : 2016年6月4日 下午2:25:56
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int x; cin >> x;
  cout << (x + 1) % 7 + 1 << endl;
  return 0;
}
