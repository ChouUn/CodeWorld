//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu2602.cpp
 *  Date : 2016年5月13日 上午1:43:23
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 1010;
const int M = 1010;

pii a[N];
int b[N], dp[M];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    rep(i, 0, n) cin >> a[i].second;
    rep(i, 0, n) cin >> a[i].first;

    sort(a, a + n);
    rep(i, 0, n) b[i] = (i ? b[i - 1] : 0) + a[i].first;

    dp[0] = 0, fill_n(dp + 1, m, -INT_MAX);
    rep(i, 0, n)
      per(j, a[i].first, min(m, b[i]) + 1)
        dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
    cout << *max_element(dp, dp + m + 1) << endl;
  }
  return 0;
}
