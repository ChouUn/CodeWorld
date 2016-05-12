//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1114.cpp
 *  Date : 2016年5月13日 上午2:36:24
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 510;
const int M = 10010;
pii a[N];
int dp[M];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int x, y, m; cin >> x >> y, m = y - x;
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i].second >> a[i].first;

    dp[0] = 0, fill_n(dp + 1, m, INT_MAX / 2);
    rep(i, 0, n)
      rep(j, a[i].first, m + 1)
        dp[j] = min(dp[j], dp[j - a[i].first] + a[i].second);
    if (dp[m] == INT_MAX / 2) cout << "This is impossible.\n";
    else cout << "The minimum amount of money in the piggy-bank is " << dp[m] << ".\n";
  }
  return 0;
}
