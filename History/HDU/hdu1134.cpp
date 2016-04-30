//@ Including Header
#include <csl_std.h>
#include <bigint.h>
using csl::BigInt;

/**
 *  Name : hdu1134.cpp
 *  Date : 2016年3月8日 下午4:06:26
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  BigInt f[200];
  f[0] = 1;
  rep(i, 1, 101) f[i] = f[i-1] * (4 * i - 2) / (i + 1);
  int _, __ = 1;
  for(int n; std::cin >> n && n != -1; --_, ++__) {
    cout << f[n] << endl;
  }
  return 0;
}
