//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6259.cpp
 *  Date : 2016年7月6日 上午11:13:01
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

ll a[1010], b[60];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];
    int m; cin >> m;
    rep(i, 0, m) cin >> b[i];

    ll ans = 0;
    rep(i, 0, n) {
      ll cnt = a[i];
      rep(j, 0, m) cnt *= b[j];
      rep(k, 0, n) if (k != i) cnt |= a[k];
      ans = max(ans, cnt);
    }
    cout << ans << endl;
  }
  return 0;
}
