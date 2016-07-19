//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6420.cpp
 *  Date : 2016年7月12日 上午8:36:05
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int a[N];

//@ Main Function
int main() {
  a[0] = 0;
  rep(i, 1, N) {
    bool flag = 1;
    int b[10];
    rep(i, 0, 10) b[i] = 0;
    int k = i;
    while (k) {
      if (b[k % 10]) flag = 0;
      b[k % 10] = 1;
      k /= 10;
    }
    a[i] = a[i - 1] + flag;
  }
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int x, y; cin >> x >> y && x && y; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cout << a[y] - a[x - 1] << endl;
  }
  return 0;
}
