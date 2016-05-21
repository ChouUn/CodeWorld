//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5691.cpp
 *  Date : 2016年5月21日 下午5:42:36
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 16;
int a[N], b[N], c[N];
ll f[1<<N][N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ":\n";
    int n; cin >> n;
    int m = 1 << n;
    rep(i, 0, n) cin >> a[i] >> b[i];
    rep(i, 0, n) c[i] = -1;
    rep(i, 0, n) if (~b[i]) c[b[i]] = i;

    rep(u, 1, m) {
      int b = __builtin_popcount(u) - 1;
      rep(j, 0, n) {
        f[u][j] = -1e12;
        int v = u ^ (1 << j);
        if (v > u) continue;
        if (~c[b] && c[b] != j) continue;
        if (!v) { f[u][j] = 0; continue; }
        rep(k, 0, n) if (f[v][k] != -1e12) f[u][j] = max(f[u][j], f[v][k] + a[k] * a[j]);
      }
    }
    cout << *max_element(f[m - 1], f[m - 1] + n) << endl;
  }
  return 0;
}
