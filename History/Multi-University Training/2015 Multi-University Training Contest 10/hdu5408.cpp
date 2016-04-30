//@ Including Header
#include <csl_std.h>
#include <geometry.h>

/*
 *  Name : hdu5408.cpp
 *  Date : 2015年8月20日 下午8:20:04
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef csl::point point;
typedef csl::line  line;
#define maxn 200010
point a[maxn], b[maxn];

bool inter(const line& a, const line& b) {
  if (csl::inter_ls(a, b)) {
    point p = (a & b).second;
    return csl::sgn(p.x - a.s.x) * csl::sgn(a.e.x - a.s.x) > 0;
  }
  else
    return false;
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    int n; scanf("%d", &n);
    rep(i, 0, n) scanf("%lf%lf", &a[i].x, &a[i].y);
    int m; scanf("%d", &m);
    rep(i, 0, m) scanf("%lf%lf", &b[i].x, &b[i].y);

    vector<point> c = csl::graham(b, m);
    point o(0,0);
    rep(i, 0, (int)c.size()) o.x += c[i].x, o.y += c[i].y;
    o.x /= c.size(), o.y /= c.size();

    int k = 0;
    vector<int> ans;
    rep(i, 0, (int)c.size()) {
      line p = line(o, c[i]);
      while (!inter(p, line(a[k], a[(k+1)%n]))) k = (k + 1) % n;
      ans.push_back(k);
      ans.push_back((k+1)%n);
    }

    if (ans.empty()) {
      printf("No\n");
      continue;
    }

    sort(ans.begin(), ans.end());
    int q = unique(ans.begin(), ans.end()) - ans.begin();
    ans.resize(q);
    printf("Yes\n");
    printf("%d\n", q);
    rep(i, 0, q)
      printf("%d%c", ans[i] + 1, i==q-1?'\n':' ');
  }
  return 0;
}
