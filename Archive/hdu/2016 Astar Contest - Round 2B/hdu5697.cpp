//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5697.cpp
 *  Date : 2016年5月24日 下午2:08:54
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 410;
const int M = 810;

#include <algorithm>
#include <numeric>
namespace minmul {
  const int N = ::N;
  const int M = ::M;
  typedef long long ll;

  struct point { ll x, y; };
  struct node { ll x, y, v; };

  int n; int w[N], x[N], y[N]; ll v[N];
  int m, s; node f[M]; ll ans;

  point evaluate(ll dx, ll dy) {
    for (int i = 0; i < n; ++i) v[i] = x[i] * dx + y[i] * dy;
    for (int i = 1; i <= s; ++i) f[i].x = 1e7, f[i].y = 1e7, f[i].v = 2e14;
    f[0].x = f[0].y = f[0].v = 0;

    for (int i = 0; i < n; ++i)
      for (int j = std::min(s, m + w[i]); j >= w[i]; --j)
        if (f[j - w[i]].v + v[i] < f[j].v)
          f[j].v = f[j - w[i]].v + v[i],
          f[j].x = f[j - w[i]].x + x[i],
          f[j].y = f[j - w[i]].y + y[i];

    point res = { f[s].x, f[s].y };
    for (int i = m; i < s; ++i)
      if (f[i].x * dx + f[i].y * dy < res.x * dx + res.y * dy)
        res = { f[i].x, f[i].y };
    ans = std::min(ans, res.x * res.y);
    return res;
  }

  void dnc(point a, point b) {
    point c = evaluate(b.y - a.y, a.x - b.x);
    if ((c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x) < 0) dnc(a, c), dnc(c, b);
  }

  ll solve(int _n, int _m) {
    n = _n, m = _m, s = std::accumulate(w, w + n, 0), ans = 1e18;
    point x = evaluate(0, 1), y = evaluate(1, 0);
//    cout << x.x << " " << x.y << ", " << y.x << " " << y.y << endl;
    return dnc(x, y), ans;
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m; cin >> n >> m; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, n) cin >> minmul::w[i] >> minmul::x[i] >> minmul::y[i];
    cout << minmul::solve(n, m) << endl;
  }
  return 0;
}

