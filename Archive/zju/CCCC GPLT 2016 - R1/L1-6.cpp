//@ Including Header
#include <csl_std.h>

/**
 *  Name : L1-6.cpp
 *  Date : 2016年6月4日 下午2:17:25
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; cin >> n;
  int x = 0, y = 0, z;
  rep(i, 0, n) cin >> z, ++(z & 1 ? x : y);
  cout << x << " " << y << endl;
  return 0;
}
