//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1300.cpp
 *  Date : 2016年5月20日 下午4:51:40
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 110;
int a[N], b[N], f[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i] >> b[i];
    rep(i, 1, n) a[i] += a[i - 1];

    rep(i, 0, n) {
      f[i] = (a[i] + 10) * b[i];
      rep(j, 0, i) f[i] = min(f[i], f[j] + (a[i] - a[j] + 10) * b[i]);
    }
    cout << f[n - 1] << endl;
  }
  return 0;
}
