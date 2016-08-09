//@ Including Header
#include <csl_std.h>

/**
 *  Name : 1010.cpp
 *  Date : 2016年7月28日 下午12:32:08
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
const int oo = 0xDEADBEEF;
int a[N], b[N], bn;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    b[bn = 1] = (a[0] == 0 ? oo : a[0]);
    rep(i, 1, n) {
      if (a[i] == 0) {
        b[bn + 1] = b[bn] + 1, ++bn;
        per(j, 1, bn) b[j + 1] = min(b[j + 1], b[j] + 1);
        b[1] = oo;
      }
      else if (a[i] > b[bn]) b[++bn] = a[i];
      else {
        auto it = lower_bound(b + 1, b + bn + 1, a[i]);
        if (it != b + bn + 1) *it = min(*it, a[i]);
      }
    }
    cout << bn << endl;
  }
  return 0;
}
