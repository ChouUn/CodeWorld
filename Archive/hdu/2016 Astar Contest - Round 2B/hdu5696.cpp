//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5696.cpp
 *  Date : 2016年5月24日 上午10:30:36
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int a[N];
ll ans[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    a[0] = a[n + 1] = 1e9 + 10;
    rep(i, 1, n + 1) cin >> a[i];
    memset(ans, 0x00, sizeof ans);
    rep(i, 1, n + 1) {
      int l = i - 1, r = i + 1; ll mi = a[i];
      ans[1] = max(ans[1], mi * mi);
      while (a[l] <= a[i] || a[r] <= a[i]) {
        if (a[l] <= a[i] && a[r] <= a[i]) mi = max(a[l], a[r]);
        else if (a[l] <= a[i]) mi = a[l];
        else if (a[r] <= a[i]) mi = a[r];
        else assert(false);
        while (mi <= a[l] && a[l] <= a[i]) --l;
        while (mi <= a[r] && a[r] <= a[i]) ++r;
        ans[r - l - 1] = max(ans[r - l - 1], mi * a[i]);
      }
    }
    per(i, 1, n + 1) ans[i] = max(ans[i], ans[i + 1]);
    rep(i, 1, n + 1) cout << ans[i] << endl;
  }
  return 0;
}
