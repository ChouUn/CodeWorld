//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6560.cpp
 *  Date : 2016年7月19日 上午8:38:06
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    vi v(n);
    for (auto &vi : v) cin >> vi;
    sort(v.begin(), v.end());
    ll cnt = 0; int ans = 0;
    for (auto &vi : v) {
      if (cnt > vi) ++ans;
      else cnt += vi;
    }
    cout << ans << endl;
  }
  return 0;
}
