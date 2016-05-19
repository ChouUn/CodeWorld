//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1631.cpp
 *  Date : 2016年3月28日 上午8:45:36
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 10010
bool b[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;

    memset(b, 0x00, sizeof b);
    bool flag = false;
    rep(i, 0, n) {
      int m; cin >> m;
      if (flag) continue;
      for (int i = 2; i * i <= m; ++i) {
        if (m % i) continue;
        if (b[i]) { flag = true; break; }
        b[i] = 1;
        while (m % i == 0) m /= i;
      }
      if (m != 1) {
        if (b[m]) { flag = true; break; }
        b[m] = 1;
      }
    }
    cout << (flag ? "An unpleasant set." : "Anjone like it.") << endl;
  }
  return 0;
}
