//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/*
 *  Name : hdu5376.cpp
 *  Date : 2015年8月15日 上午12:22:24
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define mod 1000000007LL
#define maxn 50010
ll fac[maxn], inv[maxn];

ll com(ll n, ll k) {
  if (n < k) return 0;
  return fac[n] * inv[k] % mod * inv[n-k] % mod;
}
ll solve(ll n, ll m, ll k) {
  ll l = n / 2;
  if (m == 3) {
    ll a =  l * (l+1) % mod * n % mod * inv[3] % mod;
    ll b = ((com(n, 3) - a) % mod + mod) % mod;
    switch (k) {
      case 3 : return a;
      case 2 : return b;
      default : return 0;
    }
  }
  else if (m > 3) {
    ll c = n * (com(l + 1, m - 1) + com(l, m - 1)) % mod;
    ll d = n * (m - 4) % mod * com(l + 1, m - 1) % mod;
    ll e = ((com(n, m) - c - d) % mod + mod) % mod;
    switch (k) {
      case 2 : return c;
      case 1 : return d;
      case 0 : return e;
      default : return 0;
    }
  }
  return 0;
}

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, maxn) fac[i] = fac[i-1] * i % mod;
  inv[maxn-1] = csl::pow(1LL, fac[maxn-1], mod-2, mod);
  rrep(i, 1, maxn) inv[i-1] = inv[i] * i % mod;

  int _, __ = 0;
  for (scanf("%d", &_); _; _--) {
    printf("Case #%d: ", ++__);
    ll n, m, k;
    scanf(i64 i64 i64, &n, &m, &k);
    printf(i64 "\n", solve(n, m, k));
  }
  return 0;
}
