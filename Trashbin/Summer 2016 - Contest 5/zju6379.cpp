//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6379.cpp
 *  Date : 2016年7月10日 上午8:33:03
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef unsigned long long ull;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    ull n, m; cin >> n >> m;
    ull p = 0;
    per(i, 0, 64) {
      ull q = p | (1ll << i);
      if (q > m) continue;
      if ((q ^ n) > (p ^ n)) p = q;
    }
    cout << p << endl;
  }
  return 0;
}
