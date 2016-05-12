//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : xdoj1149.cpp
 *  Date : 2016年4月18日 下午5:36:45
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 1000010
#define M 2000010
#define P 1000000007
ll fac[M], inv[M];

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, M) fac[i] = fac[i - 1] * i % P;
  inv[M - 1] = csl::inv(fac[M - 1], (ll)P);
  per(i, 1, M) inv[i - 1] = inv[i] * i % P;
  assert(inv[1] == 1);

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m, k; cin >> n >> m >> k; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    ll ans = 0;
    rep(i, 0, n + 1) {
      int x = n - 1, y = n + m - 1 - (k + 1) * i;
      if (x > y) break;
      ll p = fac[n] * inv[i] % P * inv[n-i] % P;
      ll q = fac[y] * inv[x] % P * inv[y-x] % P;
      ll sg = i & 1 ? P - 1 : 1;
      ans = (ans + sg * p % P * q % P) % P, sg = -sg;
    }
    cout << ans << endl;
  }
  return 0;
}
