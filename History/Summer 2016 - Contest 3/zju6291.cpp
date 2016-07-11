//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : zju6291.cpp
 *  Date : 2016年7月7日 上午10:50:01
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
const ll P = 1000000007;
ll cnt[N], dis[N];

ll solve(int l, int r) {
  ll x = (l) ? cnt[l - 1] : 0;
  ll y = (r) ? cnt[r - 1] : 0;
  return (y - x + P) % P;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    map<int,int> m;
    rep(i, 1, n) {
      int x; cin >> x;
      ++m[x];
    }
    int q; cin >> q;
    while (q--) {
      int a, b; cin >> a >> b;
      int r = 1; ll mul = 1;
      dis[0] = 0, cnt[0] = 1;
      for (auto it : m) {
        int x = it.first;
        int y = it.second;
        auto p = lower_bound(dis, dis + r, x - b) - dis;
        auto q = upper_bound(dis, dis + r, x - a) - dis;
        ll t = solve(p, q);
        mul = mul * csl::pow(ll(1), t, y, P) % P;
        dis[r] = x, cnt[r] = cnt[r - 1] + y, ++r;
      }
      cout << mul << endl;
    }
  }
  return 0;
}
