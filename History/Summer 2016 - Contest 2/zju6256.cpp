//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6256.cpp
 *  Date : 2016年7月6日 上午9:04:48
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

ll mulm(ull x, ull y, ull p) {
  ull xl = (x >> 32) & 0x000000000000ffff;
  ull xr = x & 0x00000000ffffffff;
  ull yl = (y >> 32) & 0x000000000000ffff;
  ull yr = y & 0x00000000ffffffff;

  ull a = xr * yl, b = xl * yr, c = xr * yr, d = xl * yl;
  ull e = a + b;
  ull res = ((((e % p) << 16) % p) << 16) % p;
  res += c % p;
  res += ((((((((d % p) << 16) % p) << 16) % p) << 16) % p) << 16) % p;
  return res % p;
}

ll powm(ll x, ll n, ll p) {
  ll res = 1;
  for (ll t = x; n; n >>= 1, t = mulm(t, t, p))
    if (n & 1) res = mulm(res, t, p);
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    ll x0, y0, A, B; cin >> x0 >> y0 >> A >> B;
    ll a = 1, b = (2 * A - (x0 + y0)) % A, c = (mulm(x0, y0, A) - B % A + A) % A;

    ll r = (mulm(b, b, A) - a * mulm(4ll, c, A) + A) % A;
    // r ^ ((A - 1) / 2) = 1 (mod A)
    ll ans = powm(r, (A - 1) / 2, A);
    cout << (ans == 1 ? "true" : "false") << endl;
  }
  return 0;
}
