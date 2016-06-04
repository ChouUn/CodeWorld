//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5701.cpp
 *  Date : 2016年5月24日 下午1:09:03
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 10010;
int a[N], h[2][N * 2], *f = h[0] + N, *g = h[1] + N, l, r;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) {
      fill(f - n, f + n, 0), f[l = 0] = 1;
      fill(g - n, g + n, 0), g[r = 0] = 1;
      rep(j, i + 1, n) l += (a[j] == a[i] ? 0 : a[j] < a[i] ? 1 : -1), ++f[l];
      per(j, 0, i) r += (a[j] == a[i] ? 0 : a[j] < a[i] ? 1 : -1), ++g[r];

      int cnt = 0;
      rep(i, -n, n) cnt += f[i] * g[-i];
      cout << cnt << (i == n - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
