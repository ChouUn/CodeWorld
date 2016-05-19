//@ Including Header
#include <csl_std.h>
#include <csl_math.h>
#include <BigInt.h>
using csl::BigInt;

/**
 *  Name : zju5403.cpp
 *  Date : 2016年3月8日 下午1:06:30
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 50010
int n, a[N], b[N], c[N];
int vis[N], r[N], o[N], idx;

bool cycle(int u) {
  int m = idx++, v = u, w = u;
  r[m] = o[m] = 0;
  // find a cycle
  do { if (vis[v]) return false; vis[v] = true, ++r[m]; } while ((v = c[v]) != u);
  // in this place, v equals u
  while (a[u] != b[v]) { if ((v = c[v]) == u) return false; ++o[m]; }
  // in this place, a[u] equals b[v], w equals u
  do { if (a[w = c[w]] != b[v = c[v]]) return false; } while (w != u);
  return true;
}

void solve() {
  idx = 0;
  rep(i, 1, n+1) vis[i] = false;
  rep(i, 1, n+1)
  if (!vis[i] && !cycle(i)) { cout << "Impossible" << endl; return; }

  BigInt M = r[0], R = o[0];
  rep(i, 1, idx) {
    BigInt mi = r[i], ri = o[i];
    BigInt g = csl::gcd(M, mi);
    if ((R - ri) % g != 0) { cout << "Impossible" << endl; return; }
    if (csl::gcd(M / g, g) == 1) M /= g; else mi /= g;
    R = R * mi * csl::inv(mi, M) + ri * M * csl::inv(M, mi);
    M *= mi, R %= M;
  }
  cout << R << endl;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(; std::cin >> n; --_, ++__) {
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, n+1) cin >> b[i];
    rep(i, 1, n+1) cin >> c[i];
    solve();
  }
  return 0;
}
