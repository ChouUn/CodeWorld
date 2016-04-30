//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/*
 *  Name : hdu5446.cpp
 *  Date : 2015年9月18日 下午4:37:28
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxk 20
#define maxn 100010
ll a[maxk], fac[maxn];

ll com(ll n, ll m, ll mod) {
  if (m > n) return 0;
  return fac[n] * csl::inv(fac[m] * fac[n-m], mod) % mod;
}

ll lucas(ll n, ll m, ll mod) {
  fac[0] = 1, fac[mod] = 0;
  rep(i, 1, mod) fac[i] = fac[i-1] * i % mod;

  ll res = 1;
  while (m) {
    res = res * com(n % mod, m % mod, mod) % mod;
    n /= mod, m /= mod;
  }
  return res;
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    ll n, m; scanf(i64 i64, &n, &m);
    int k; scanf("%d", &k);
    rep(i, 0, k) scanf(i64, a+i);

    ll M = 1; rep(i, 0, k) M *= a[i];
    ll ans = 0;
    rep(i, 0, k) {
      ll p = lucas(n, m, a[i]);
      ll q = M / a[i];
      ans += csl::mul(p, csl::mul(q, csl::inv(q, a[i]), M), M);
      ans %= M;
    }
    printf(i64 "\n", ans);
  }
  return 0;
}
