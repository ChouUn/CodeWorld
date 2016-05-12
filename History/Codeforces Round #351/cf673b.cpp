//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf673b.cpp
 *  Date : 2016年5月8日 上午9:18:04
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; cin >> n >> m;
  int a = n, b = 1;
  rep(i, 0, m) {
    int x, y; cin >> x >> y;
    if (x < y) swap(x, y);
    a = min(a, x), b = max(b, y);
  }
  cout << max(0, a - b) << endl;
  return 0;
}
