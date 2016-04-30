//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju3940.cpp
 *  Date : 2016年4月24日 下午4:04:28
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define P 1000000007

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    map<int,ll> p; p[m] = 1;

    int mi = INT_MAX;
    rep(l, 0, n) {
      int ai; cin >> ai;
      if (ai >= mi) continue; mi = ai;
      while (p.rbegin()->first >= ai) {
        int x = p.rbegin()->first;
        ll y = p.rbegin()->second;
        p.erase(--p.end());

        int s = x / ai;
        int t = x % ai;
        p[ai-1] = (p[ai-1] + s * y) % P;
        p[t] = (p[t] + y) % P;
      }
    }

    ll cnt = 0, ans = 0;
    for (auto pi = p.rbegin(); pi != p.rend(); ++pi)
      cnt = pi->second = (pi->second + cnt) % P;
    int q; cin >> q;
    rep(i, 1, q + 1) {
      int y; cin >> y;
      auto it = p.lower_bound(y);
      ll z = (it != p.end()) ? it->second : 0;
      ans = (ans + z * i) % P;
    }
    cout << ans << endl;
  }
  return 0;
}
