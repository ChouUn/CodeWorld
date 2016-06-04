//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf611b.cpp
 *  Date : 2015年12月30日 下午11:16:06
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  vector<ll> v;
  rep(i, 1, 63) {
    ll x = (1ll << i) - 1;
    rep(j, 0, i - 1) v.push_back(x - (1ll << j));
  }

  ll a, b; cin >> a >> b;
  int ans = 0;
  for(auto &i : v) ans += (i >= a && i <= b);
  cout << ans << endl;
  return 0;
}
