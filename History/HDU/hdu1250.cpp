//@ Including Header
#include <csl_std.h>
#include <BigInt.h>

/**
 *  Name : hdu1250.cpp
 *  Date : 2016年3月13日 下午2:19:49
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef csl::BigInt bint;
#define N 7500
bint f[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  f[1] = f[2] = f[3] = f[4] = 1;
  rep(i, 5, N) f[i] = f[i-1] + f[i-2] + f[i-3] + f[i-4];

//  rep(i, 5, N) {
//    string s = f[i].to_string();
//    if (s.size() <= 2005) continue;
//    cout << "length > 2005 until i = " << i << endl;
//    break;
//  }

  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cout << f[n] << endl;
  }
  return 0;
}
