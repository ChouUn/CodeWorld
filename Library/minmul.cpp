#include <algorithm>
#include <numeric>
namespace minmul {
  const int N;
  const int M;
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
