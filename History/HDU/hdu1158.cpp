//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1158.cpp
 *  Date : 2016年5月13日 上午2:53:24
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

int a[12];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n && n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int c, d, e; cin >> c >> d >> e;
    rep(i, 0, n) cin >> a[i];

    int m = *max_element(a, a + n);
    vector<int> dp(m + 1);
    dp[0] = 0, fill_n(&dp[1], m, INT_MAX / 2);
    rep(i, 0, n) {
      rep(j, 0, m) dp[j + 1] = min(dp[j + 1], dp[j] + c);
      per(j, 0, m) dp[j] = min(dp[j], dp[j + 1] + e);
      rep(j, 0, m + 1) dp[j] += j * d;
      fill_n(&dp[0], a[i], INT_MAX / 2);
    }
    cout << *min_element(dp.begin(), dp.end()) << endl;
  }
  return 0;
}
