//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : hdu3037.cpp
 *  Date : 2016年3月31日 下午8:53:53
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 100010
ll fac[N], inv[N];

inline ll com(int n, int m, int p) {
  if (m > n) return 0;
  return fac[n] * inv[m] % p * inv[n-m] % p;
}

inline ll lucas(int n, int m, int p) {
  if (m == 0) return 1;
  return com(n%p, m%p, p) * lucas(n/p, m/p, p) % p;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m, p; cin >> n >> m >> p;

    fac[0] = 1;
    rep(i, 1, p) fac[i] = fac[i-1] * i % p;
    inv[p-1] = csl::pow(ll(1), fac[p-1], p-2, ll(p));
    rrep(i, 1, p) inv[i-1] = inv[i] * i % p;

    cout << lucas(n + m, m, p) << endl;
  }
  return 0;
}
