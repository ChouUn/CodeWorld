//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5185.cpp
 *  Date : 2015年11月24日 上午12:41:54
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 50010
ll dp[2][maxn];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ <<": ";
    int n; ll mod; cin >> n >> mod;

    ll ans = 0;
    memset(dp[0], 0x00, sizeof(dp[0]));
    dp[0][0] = 1;
    rep(i, 1, (int)sqrt(n << 1) + 1) {
      memset(dp[i & 1], 0x00, sizeof(dp[i & 1]));
      rep(j, i, n + 1)
        dp[i & 1][j] = (dp[i & 1][j - i] + dp[(i & 1) ^ 1][j - i]) % mod;
      ans = (ans + dp[i & 1][n]) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}
