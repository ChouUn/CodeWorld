//@ Including Header
#include <csl_std.h>
#include <matrix.h>

/*
 *  Name : hdu5411.cpp
 *  Date : 2015年9月11日 下午9:19:44
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define mod 2015
typedef csl::matrix<int> mat;

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    int n, k; scanf("%d%d", &n, &k);
    int N = n + 1;

    mat p(N, N);
    rep(i, 0, n) {
      int m;
      for (scanf("%d", &m); m; --m) {
        int x; scanf("%d", &x);
        p[i][x-1] = 1;
      }
    }
    rep(i, 0, N) p[i][n] = 1;

    mat q = mat::identity(N);
    for (int m = k - 1; m; m >>= 1) {
      if (m & 1) {
        q *= p; rep(i, 0, N) rep(j, 0, N) q[i][j] %= mod;
      }
      p *= p; rep(i, 0, N) rep(j, 0, N) p[i][j] %= mod;
    }

    mat c(1, N);
    rep(i, 0, N) c[0][i] = 1;
    q = c * q;

    int ans = 0;
    rep(i, 0, n+1) ans = (ans + q[0][i]) % mod;
    printf("%d\n", ans);
  }
  return 0;
}
