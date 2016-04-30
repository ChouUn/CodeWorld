//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5492.cpp
 *  Date : 2015年9月28日 下午8:46:12
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 31
#define maxm 1810
int a[maxn][maxn];
int f[maxn][maxn][maxm];
inline void update(int& a, int b)
{ a = ~a ? min(a, b) : b; }

//@ Main Function
int main() {
  int _, __ = 0; scanf("%d", &_);
  while (_--) {
    int n, m; scanf("%d%d", &n, &m);
    rep(i, 1, n+1) rep(j, 1, m+1) scanf("%d", &a[i][j]);

    memset(f, 0xff, sizeof(f));
    f[0][1][0] = f[1][0][0] = 0;
    rep(i, 1, n+1) rep(j, 1, m+1) rep(k, a[i][j], maxm) {
      if (~f[i-1][j][k-a[i][j]]) update(f[i][j][k], f[i-1][j][k-a[i][j]] + a[i][j] * a[i][j]);
      if (~f[i][j-1][k-a[i][j]]) update(f[i][j][k], f[i][j-1][k-a[i][j]] + a[i][j] * a[i][j]);
    }
    int ans = -1;
    rep(k, 0, maxm) {
      if (~f[n][m][k]) update(ans, f[n][m][k] * (n + m - 1) - k * k);
    }
    printf("Case #%d: %d\n", ++__, ans);
  }
  return 0;
}
