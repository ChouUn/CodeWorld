//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5234.cpp
 *  Date : 2015年11月24日 上午1:07:57
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 110
int g[maxn][maxn];
bool dp[maxn][maxn][maxn];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m, p; cin >> n >> m >> p; --_, ++__) {
    rep(i, 1, n+1) rep(j, 1, m+1) cin >> g[i][j];

    memset(dp, 0x00, sizeof(dp));
    dp[1][1][0] = 1;
    dp[1][1][g[1][1]] = 1;
    rep(i, 1, n+1) rep(j, 1, m+1) rep(k, 0, p+1) {
      dp[i][j][k] |= dp[i-1][j][k];
      dp[i][j][k] |= dp[i][j-1][k];
      if (k >= g[i][j]) {
        dp[i][j][k] |= dp[i-1][j][k-g[i][j]];
        dp[i][j][k] |= dp[i][j-1][k-g[i][j]];
      }
    }

    int ans = 0;
    rep(k, 0, p+1) if (dp[n][m][k]) ans = k;
    cout << ans << '\n';
  }
  return 0;
}
