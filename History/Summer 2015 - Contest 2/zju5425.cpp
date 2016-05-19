//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju5425.cpp
 *  Date : 2016年3月22日 下午9:12:13
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 100010
vi g[N];
int h[N][2];
int s[N][2][2];
int t[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m; cin >> n >> m; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    if (n <= 2) { cout << 0 << endl; continue; }

    vi a(m), b(m), c(m);
    rep(i, 0, m) cin >> a[i] >> b[i] >> c[i], --a[i], --b[i];

    vi d(n), e(n), f(n);
    rep(i, 0, m) ++d[a[i]], ++d[b[i]];
    rep(i, 0, n) e[i] = i;
    sort(e.data(), e.data() + n, [&d](int x, int y) -> bool { return d[x] < d[y]; });
    rep(i, 0, n) f[e[i]] = i;
    rep(i, 0, m) {
      a[i] = f[a[i]], b[i] = f[b[i]];
      if (a[i] > b[i]) swap(a[i], b[i]);
    }

    d.assign(n, 0);
    rep(i, 0, n) g[i].clear();
    memset(h, 0x00, sizeof h);
    rep(i, 0, m) {
      ++d[a[i]], ++d[b[i]];
      g[a[i]].push_back(i);
      ++h[a[i]][c[i]], ++h[b[i]][c[i]];
    }
    rep(i, 0, n) sort(g[i].begin(), g[i].end(), [&b](int x, int y) -> bool {
      return b[x] < b[y];
    });

    memset(s, 0x00, sizeof s);
    memset(t, 0x00, sizeof t);
    ll ans = (ll)n * (n - 1) * (n - 2) / 3 * 2;
    rep(i, 0, m) {
      auto j = g[a[i]].begin(), k = g[b[i]].begin();
      for (; j != g[a[i]].end() && k != g[b[i]].end(); ) {
        if (b[*j] != b[*k]) b[*j] < b[*k] ? ++j : ++k;
        else {
          int r = c[i], p = c[*j], q = c[*k];
          ans -= (r + p + q < 2) ? 4 : 3;
          ++s[a[i]][min(r, p)][max(r, p)];
          ++s[b[i]][min(r, q)][max(r, q)];
          ++s[b[*j]][min(p, q)][max(p, q)];
          ++t[i], ++t[*j], ++t[*k];
          ++j, ++k;
        }
      }
    }
    rep(i, 0, n) {
      ll d0 = h[i][0], d1 = h[i][1];
      ans -= 4 * (d0 * (d0 - 1) / 2 - s[i][0][0]);
      ans -= 3 * (d0 * d1 - s[i][0][1]);
      ans -= 2 * (d1 * (d1 - 1) / 2 - s[i][1][1]);
    }
    rep(i, 0, m)
      ans -= (n - d[a[i]] - d[b[i]] + t[i]) * (c[i] ? 1 : 3);
    cout << ans % 999983 << endl;
  }
  return 0;
}
