//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1079.cpp
 *  Date : 2015年12月7日 下午9:50:44
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int a, b, c; cin >> a >> b >> c;
    cout << ((b + c) % 2 == 0 || (c == 30 && (b == 9 || 11))
        ? "YES" : "NO") << '\n';
  }
  return 0;
}
