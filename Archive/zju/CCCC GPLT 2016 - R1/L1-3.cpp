//@ Including Header
#include <csl_std.h>

/**
 *  Name : L1-3.cpp
 *  Date : 2016年6月4日 下午1:57:47
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int x, y; cin >> x >> y;
  int s = x, t = y;
  int n; cin >> n;
  while (n--) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int p = (a + c == b), q = (a + c == d);
    if (p ^ q) {
      if (p) --x; else --y;
      if (x < 0) {
        cout << 'A' << endl << t - y << endl;
        return 0;
      }
      if (y < 0) {
        cout << 'B' << endl << s - x << endl;
        return 0;
      }
    }
  }
  return 0;
}
