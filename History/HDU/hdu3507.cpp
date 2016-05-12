//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu3507.cpp
 *  Date : 2016年5月8日 上午10:06:12
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 500010;
int a[N], s[N], q[N], qh, qt, dp[N];

inline int up(int j, int k) {
  return (dp[k] + s[k] * s[k]) - (dp[j] + s[j] * s[j]);
}

inline int down(int j, int k) {
  return (s[k] - s[j]) * 2;
}

inline int solve(int k, int i) {
  return dp[k] + (s[i] - s[k]) * (s[i] - s[k]);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m; cin >> n >> m; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 1, n + 1) cin >> a[i];

    dp[0] = 0, s[0] = 0, qh = qt = 0, q[qt++] = 0;
    rep(i, 1, n + 1) s[i] = s[i - 1] + a[i];
    rep(i, 1, n + 1) {
      while (qh + 1 < qt && up(q[qh], q[qh + 1])
          <= s[i] * down(q[qh], q[qh + 1])) ++qh;
      dp[i] = solve(q[qh], i) + m;
      while (qh + 1 < qt && up(q[qt - 2], q[qt - 1]) * down(q[qt - 2], i)
          >= up(q[qt - 2], i) * down(q[qt - 2], q[qt - 1])) --qt;
      q[qt++] = i;
    }
    cout << dp[n] << endl;
  }
  return 0;
}
