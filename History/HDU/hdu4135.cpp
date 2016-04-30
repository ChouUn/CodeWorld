//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu4135.cpp
 *  Date : 2016年4月1日 上午1:05:29
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

vi split(int n) {
  vi v;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i) continue;
    while (n % i == 0) n /= i;
    v.push_back(i);
  }
  if (n != 1) v.push_back(n);
  return v;
}

ll solve(ll x, const vi& v) {
  if (!x) return 0;
  ll res = 0;
  int n = v.size(), m = 1 << n;
  rep(i, 0, m) {
    ll p = 1; int q = 0;
    rep(k, 0, n) if (i & (1 << k)) p *= v[k], ++q;
    res += (q & 1 ? -1 : 1) * (x / p);
  }
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ": ";
    ll a, b; int n; cin >> a >> b >> n;
    vi v = split(n);
    cout << solve(b, v) - solve(a - 1, v) << endl;
  }
  return 0;
}
