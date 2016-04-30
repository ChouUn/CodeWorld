//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu4190.cpp
 *  Date : 2016年4月30日 下午1:11:16
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 500010
#define M 5000000
int n, k;
ll a[N];

ll solve(ll m) {
  ll res = 0;
  rep(i, 0, n) res += (a[i] + m - 1) / m;
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(; cin >> n >> k && ~n && ~k; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, n) cin >> a[i];

    ll l = 1, r = M;
    while (l < r) {
      ll m = (l + r) / 2;
      if (solve(m) > k) l = m + 1;
      else r = m;
    }
    cout << l << '\n';
  }
  return 0;
}
