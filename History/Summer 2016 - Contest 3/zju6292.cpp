//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6292.cpp
 *  Date : 2016年7月7日 上午10:25:44
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 200010;
double a[N], s[N], u[N], v[N], dp[2][N], *f, *g;
int q[N], qh, qt;

inline double getv(int j, int k) {
  double Aj = f[j] - u[j] + s[j] * v[j], Bj = -s[j];
  double Ak = f[k] - u[k] + s[k] * v[k], Bk = -s[k];
  return (-Aj + Ak) / (Bj - Bk);
}

inline double solve(int i, int k) {
  return f[i] + u[k] - u[i] - s[i] * (v[k] - v[i]);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    memset(s, 0x00, sizeof s);
    memset(u, 0x00, sizeof u);
    memset(v, 0x00, sizeof v);
    memset(dp, 0x00, sizeof dp);

    int n, k; cin >> n >> k; k = min(n, k);
    rep(i, 1, n + 1) cin >> a[i];

    s[0] = 0, u[0] = 0, v[0] = 0, f = dp[0], g = dp[1], f[0] = 0;
    rep(i, 1, n + 1) {
      s[i] = s[i - 1] + a[i];
      u[i] = u[i - 1] + s[i] / a[i];
      v[i] = v[i - 1] + 1. / a[i];
      f[i] = 1e100;
    }

    rep(p, 1, k + 1) {
      qh = 0, qt = 0;
      rep(i, 0, n + 1) {
        while (qh + 1 < qt && solve(q[qh], i) >= solve(q[qh + 1], i)) ++qh;
        g[i] = (qh < qt) ? solve(q[qh], i) : 1e100;
        while (qh + 1 < qt && getv(q[qt - 2], q[qt - 1]) >= getv(q[qt - 1], i)) --qt;
        q[qt++] = i;
      }
      swap(f, g);
    }
    cout << setprecision(10) << fixed << f[n] << endl;
  }
  return 0;
}
