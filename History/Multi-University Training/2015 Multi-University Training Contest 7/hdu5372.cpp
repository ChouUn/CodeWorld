//@ Including Header
#include <csl_std.h>
#include <fastio.h>
#include <fenwick.h>
#include <discrete.h>

/*
 *  Name : hdu5372.cpp
 *  Date : 2015年8月14日 下午9:08:18
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 200010
typedef csl::fenwick_tree<int> ft;
int in[maxn][2];

//@ Main Function
int main() {
  int __ = 0;
  csl::fastio::build();
  for (int n; !csl::fastio::empty(); ) {
    csl::fastio::nextInt(n);
    printf("Case #%d:\n", ++__);

    csl::discrete<int> u;
    std::vector<pii> v;
    rep(i, 0, n) {
      int x, y;
      csl::fastio::nextInt(x);
      csl::fastio::nextInt(y);
      if (x) {
        in[i][0] = x;
        in[i][1] = y - 1;
        continue;
      }
      in[i][0] = x;
      in[i][1] = v.size();
      int p = y;
      int q = y + v.size() + 1;
      u.insert(p);
      u.insert(q);
      v.push_back(make_pair(p, q));
    }

    u.build(); int m = u.size();
    ft l, r; l.build(m); r.build(m);

    rep(i, 0, n) {
      int x = in[i][0], y = in[i][1];
      int p = u.query(v[y].first) + 1;
      int q = u.query(v[y].second) + 1;
      if (x) {
        l.update(p, -1);
        r.update(q, -1);
      }
      else {
        int ans = r.query(q) - l.query(p - 1);
        l.update(p, 1);
        r.update(q, 1);
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
