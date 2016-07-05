//@ Including Header
#include <csl_std.h>

/**
 *  Name : jsk 2016 - R7B.cpp
 *  Date : 2016年7月3日 下午1:06:30
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

int a, b, c;
bool check(int p) {
  if (a < p) return false;
  if (b < p) return false;
  int x = a - p, y = b - p, z = c;
  if (x + y + z < p) return false;
  if (x > z) swap(x, z);
  if (y > z) swap(y, z);
  z = min(z, p - x - y);
  return x + y + 1 >= z;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> a >> b >> c;
    int l = 0, r = 10000010;
    while (l < r) {
      int m = (l + r) / 2 + 1;
      if (check(m)) l = m; else r = m - 1;
    }
    cout << l << endl;
  }
  return 0;
}
