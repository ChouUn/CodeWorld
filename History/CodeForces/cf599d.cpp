//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf599d.cpp
 *  Date : 2015年12月25日 下午5:10:48
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef pair<ll,ll> pll;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll x; cin >> x;
  vector<pll> ans;
  for(ll n = 1; n; ++n) {
    ll r = x - n * (n + 1) * (2 * n + 1) / 6;
    ll l = n * (n + 1) / 2;
    ll y = r / l + n;
    if(n > y) break;
    if(r % l) continue;
    ans.push_back(make_pair(n, y));
    if(n == y) break;
    ans.push_back(make_pair(y, n));
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  rep(i, ans.begin(), ans.end()) cout << i->first << " " << i->second << endl;
  return 0;
}
