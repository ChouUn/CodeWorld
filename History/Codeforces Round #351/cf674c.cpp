//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf674c.cpp
 *  Date : 2016年5月8日 上午10:20:09
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 200010;
double a[N], s[N], u[N], v[N], dp[2][N], *f, *g;
int q[N], qh, qt;

inline double getv(int j, int k) {
  double Ak = f[k] - u[k] + s[k] * v[k];
  double Aj = f[j] - u[j] + s[j] * v[j];
  return (Ak - Aj) / (s[k] - s[j]);
}

inline double solve(int k, int i) {
  return f[k] + u[i] - u[k] - s[k] * (v[i] - v[k]);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k; cin >> n >> k; k = min(n, k);
  rep(i, 1, n + 1) cin >> a[i];

  s[0] = 0, u[0] = 0, v[0] = 0, f = dp[0], g = dp[1], g[0] = 0;
  rep(i, 1, n + 1) {
    s[i] = s[i - 1] + a[i];
    u[i] = u[i - 1] + s[i] / a[i];
    v[i] = v[i - 1] + 1. / a[i];
    g[i] = INFINITY;
  }

  rep(p, 1, k + 1) {
    qh = 0, qt = 0, swap(f, g);
    rep(i, 0, n + 1) {
      while (qh + 1 < qt && solve(q[qh], i) >= solve(q[qh + 1], i)) ++qh;
      g[i] = (qh < qt) ? solve(q[qh], i) : INFINITY;
      while (qh + 1 < qt && getv(q[qt - 2], q[qt - 1]) >= getv(q[qt - 1], i)) --qt;
      q[qt++] = i;
    }
  }
  cout << setprecision(10) << fixed << g[n] << endl;
  return 0;
}
