//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1024.cpp
 *  Date : 2016年5月20日 下午3:37:38
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 1000010;
const ll oo = -LLONG_MAX / 2;
ll a[N], s[N], dp[2][N], *f = dp[0], *g = dp[1];

void update(ll& a, ll b) {
  if (a == -1 || a < b) a = b;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m; cin >> m >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 1, n + 1) cin >> a[i], s[i] = s[i - 1] + a[i];

    fill_n(f, n + 1, oo); f[0] = 0;
    rep(k, 1, m + 1) {
      fill_n(g, n + 1, oo);
      ll tmp = f[k - 1];
      rep(i, k, n + 1) {
        if (g[i - 1] != oo) update(g[i], g[i - 1] + a[i]);
        if (tmp != oo) update(g[i], tmp + a[i]);
        if (f[i] != oo) update(tmp, f[i]);
      }
      swap(f, g);
    }
    cout << *max_element(f, f + n + 1) << endl;
  }
  return 0;
}
