//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf673a.cpp
 *  Date : 2016年5月8日 上午9:16:11
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; cin >> n;
  int ans = 0;
  rep(i, 0, n) {
    int x; cin >> x;
    if (ans + 15 >= x) ans = x;
  }
  cout << min(90, ans + 15) << endl;
  return 0;
}
