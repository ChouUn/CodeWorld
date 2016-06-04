//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5700.cpp
 *  Date : 2016年5月24日 下午12:34:39
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int a[N], l[N], r[N];
vi g[N];
ll s[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, k, m; cin >> n >> k >> m; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, m + 1) cin >> l[i] >> r[i];

    rep(i, 1, n + 1) g[i].clear();
    rep(i, 1, m + 1) g[l[i]].push_back(r[i]);
    rep(i, 1, n + 1) s[i] = s[i - 1] + a[i];

    multiset<int> ms;
    ll ans = 0;
    rep(i, 1, n + 1) {
      for (auto &gi : g[i]) ms.insert(gi);
      while ((int)ms.size() > k) ms.erase(ms.begin());
      if ((int)ms.size() == k && *ms.begin() >= i) ans = max(ans, s[*ms.begin()] - s[i - 1]);
    }
    cout << ans << endl;
  }
  return 0;
}
