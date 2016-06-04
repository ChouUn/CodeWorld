//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : hdu5698.cpp
 *  Date : 2016年5月24日 上午10:38:27
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 200010;
const ll P = 1000000007;

ll fac[N], inv[N];

inline ll com(int n, int m)
{ return fac[n] * inv[m] % P * inv[n - m] % P; }

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, N) fac[i] = fac[i - 1] * i % P;
  inv[N - 1] = csl::inv(fac[N - 1], P);
  per(i, 1, N) inv[i - 1] = inv[i] * i % P;

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m; cin >> n >> m; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cout << com(n + m - 4, n - 2) << endl;
  }
  return 0;
}
