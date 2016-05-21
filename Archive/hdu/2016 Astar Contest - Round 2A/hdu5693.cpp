//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5693.cpp
 *  Date : 2016年5月21日 下午7:02:56
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 310;
int a[N], b[N];
bool g[N][N];
int f[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    set<int> s(b, b + m);
    rep(j, 1, n + 1) {
      g[j][j - 1] = true, g[j][j] = false;
      per(i, 1, j) {
        g[i][j] = false;
        rep(k, i, j) g[i][j] |= g[i][k] & g[k + 1][j];
        if (s.count(a[j] - a[i])) g[i][j] |= g[i + 1][j - 1];
        if (s.count((a[j] - a[i]) / 2) && (a[j] - a[i]) % 2 == 0)
          rep(k, i + 1, j) if (a[k] * 2 == a[i] + a[j]) g[i][j] |= g[i + 1][k - 1] & g[k + 1][j - 1];
      }
    }

    f[0] = 0;
    rep(i, 1, n + 1) {
      f[i] = f[i - 1];
      rep(j, 0, i) if (g[j + 1][i]) f[i] = max(f[i], f[j] + i - j);
    }
    cout << f[n] << endl;
  }
  return 0;
}
