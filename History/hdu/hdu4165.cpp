//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1023.cpp
 *  Date : 2016年3月31日 下午8:31:06
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 31
ll f[N];

//@ Main Function
int main() {
  f[0] = f[1] = 1;
  rep(i, 2, N) rep(k, 0, i) f[i] += f[k] * f[i-1-k];

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n, n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cout << f[n] << endl;
  }
  return 0;
}
