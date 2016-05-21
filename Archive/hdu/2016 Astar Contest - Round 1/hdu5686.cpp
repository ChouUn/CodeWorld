//@ Including Header
#include <csl_std.h>
#include <BigDec.h>

/**
 *  Name : hdu5686.cpp
 *  Date : 2016年5月21日 下午11:44:26
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef csl::BigDec<> bint;
const int N = 210;
bint f[N];

//@ Main Function
int main() {
  f[1] = 1, f[2] = 2;
  rep(i, 3, N)  f[i] = f[i - 2] + f[i - 1];

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cout << f[n] << endl;
  }
  return 0;
}
