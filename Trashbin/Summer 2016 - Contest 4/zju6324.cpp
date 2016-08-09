//@ Including Header
#include <csl_std.h>
#include <csl_math.h>
#include <BigInt.h>

/**
 *  Name : zju6324.cpp
 *  Date : 2016年7月8日 上午9:07:58
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef csl::BigInt bint;
const int N = 100010;
const bint P = 1000000000000000007LL;
bint fac[N], inv[N];

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, N) fac[i] = fac[i - 1] * i % P;
  inv[N - 1] = csl::inv(fac[N - 1], P);
  per(i, 1, N) inv[i - 1] = inv[i] * i % P;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m; cin >> n >> m && n && m; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    if (m > n) cout << "How lonely night~" << endl;
    else cout << fac[n] * inv[m] * inv[n - m] % P << endl;
  }
  return 0;
}
