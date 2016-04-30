//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>
#include <geometry.h>

/*
 *  Name : hdu5251.cpp
 *  Date : 2015年9月24日 下午3:19:01
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

using csl::point;
using csl::line;
using csl::sgn;
#define maxn 1010
point p[maxn*4], q[maxn*4];

//@ Main Function
int main() {
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ <<":\n";
    int n; scanf("%d", &n);
    rep(i, 0, n << 2) scanf("%lf%lf", &p[i].x, &p[i].y);
    vector<point> g = csl::graham(p, n << 2);
    int m = g.size(); g.push_back(g[0]);
    double ans = csl::bound_rect(g.data(), m);
    printf("%.0f\n", ans);
  }
  return 0;
}
