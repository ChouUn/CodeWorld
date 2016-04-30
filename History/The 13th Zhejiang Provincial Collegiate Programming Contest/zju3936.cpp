//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju3936.cpp
 *  Date : 2016年4月24日 上午10:00:08
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
    int a, b, c, d; cin >> a >> b >> c >> d;
    swap(a, c), b = d = b + d;
    cout << a << ' ' << b << '\n';
    cout << c << ' ' << d << '\n';
  }
  return 0;
}
