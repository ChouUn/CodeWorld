//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1627.cpp
 *  Date : 2016年3月28日 上午8:52:37
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 20
double a[N], dp[1<<N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    dp[(1 << n) - 1] = 0;
    per(i, 0, (1 << n) - 1) {
      double m = 0;
      dp[i] = 1;
      rep(k, 0, n) {
        if (i & (1 << k)) continue;
        dp[i] += dp[i | (1 << k)] * a[k];
        m += a[k];
      }
      dp[i] /= m;
    }
    cout << setprecision(3) << setiosflags(ios::fixed) << dp[0] << endl;
  }
  return 0;
}
