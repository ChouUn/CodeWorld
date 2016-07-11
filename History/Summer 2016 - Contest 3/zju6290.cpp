//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : zju6290.cpp
 *  Date : 2016年7月7日 上午11:06:14
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 110;
const int M = 11;
const ll P = 1000000007;
int n, a[M];
ll dp[M][N], fac[N], inv[N];

ll com(ll n, ll k) {
  return fac[n] * inv[k] % P * inv[n - k] % P;
}

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, N) fac[i] = fac[i - 1] * i % P;
  inv[N - 1] = csl::pow(ll(1), fac[N - 1], P - 2, P);
  per(i, 1, N) inv[i - 1] = inv[i] * i % P;

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 1, 11) cin >> a[i];
    ll ans = 0;
    rep(l, 2, 11) {
      --a[l];
      memset(dp, 0x00, sizeof dp);
      dp[0][0] = 1;
      rep(i, 1, 11) rep(j, 0, n) rep(k, max(a[i], 0), j + 1)
        dp[i][j] = (dp[i][j] + com(j, k) * dp[i - 1][j - k]) % P;
      rep(j, 0, n) ans = (ans + dp[10][j]) % P;
      ++a[l];
    }
    cout << ans << endl;
  }
  return 0;
}
