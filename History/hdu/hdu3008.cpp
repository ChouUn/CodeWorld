//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu3008.cpp
 *  Date : 2016年5月16日 下午9:03:16
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 110;
const int M = 100;
int a[N], b[N];
int dp[2][N], *f = dp[0], *g = dp[1];

void update(int& a, int b, int c = 0) {
  if (b == -1) return;
  b += c;
  if (a == -1 || a < b) a = b;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, p, q; cin >> n >> p >> q && n && p && q; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, n) cin >> a[i] >> b[i];
    a[n] = 0, b[n] = 1, ++n;

    int ans = -1;
    fill_n(f, N, -1); f[M] = 0;
    for (int m = M, cnt = 1; m > 0 && !~ans; m -= q, ++cnt) {
      fill_n(g, N, -1);
      rep(k, 0, n) rep(i, a[k], M + 1) update(g[min(i - a[k] + p, M)], f[i], b[k]);
      swap(f, g);
      rep(i, 0, M + 1) if (f[i] >= M) { ans = cnt; break; }
    }
    if (~ans) cout << ans << endl;
    else cout << "My god" << endl;
  }
  return 0;
}
