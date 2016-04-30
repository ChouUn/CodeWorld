//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu4768.cpp
 *  Date : 2016年4月26日 下午6:00:17
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 20010
int n;
ll a[N], b[N], c[N];

inline ll solve(ll m) {
  ll res = 0;
  rep(i, 0, n) {
    if (m < a[i]) continue;
    res += (min(b[i], m) - a[i]) / c[i] + 1;
  }
  return res;
}

inline ll calc(ll l, ll r) {
  return solve(r) - (l ? solve(l - 1) : 0);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, n) cin >> a[i] >> b[i] >> c[i];

    ll l = 0, r = 1ll << 31;
    if (calc(l, r) % 2 == 0) { cout << "DC Qiang is unhappy.\n"; continue; }
    while (l < r) {
      ll m = (l + r) / 2;
      if (solve(m) & 1) r = m;
      else l = m + 1;
    }
    cout << l << ' ' << calc(l, l) << '\n';
  }
  return 0;
}
