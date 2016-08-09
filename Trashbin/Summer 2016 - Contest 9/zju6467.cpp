//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6467.cpp
 *  Date : 2016年7月15日 上午12:43:51
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
    int ans1 = 0;
    rep(i, 0, n) {
      int x; cin >> x;
      ans1 += x;
    }
    int ans2 = 0;
    rep(i, 0, n) {
      int x; cin >> x;
      ans2 += x;
    }
    cout << (ans1 > ans2 ? "Bulbasaur" : "Totodile") << endl;
  }
  return 0;
}
