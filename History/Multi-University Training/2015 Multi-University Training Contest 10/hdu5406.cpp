//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>
#include <fenwick.h>
#include <discrete.h>

/*
 *  Name : hdu5406.cpp
 *  Date : 2015年8月20日 下午7:10:15
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 1010
int n, a[maxn], b[maxn], c[maxn], d[maxn];
bool cmp(const int& x, const int& y) {
  return a[x] == a[y] ? b[x] < b[y] : a[x] > a[y];
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d%d", a+i, b+i);

    csl::discrete<int> s;
    s.insert(b, b + n);
    s.build();
    rep(i, 0, n) b[i] = s.query(b[i]) + 1;

    rep(i, 0, n) c[i] = i;
    sort(c, c + n, cmp);

    int m = s.size();
    csl::fenwick_tree< int, csl::greater<int> > f[maxn];
    rep(i, 1, m+1) f[i].build(m);
    rep(i, 0, n) {
      int x = b[c[i]];
      rep(j, 1, m+1) d[j] = f[j].query(x) + 1;
      rep(j, 1, m+1) f[j].update(x, d[j]), f[x].update(j, d[j]);
    }

    int ans = 0;
    rep(i, 1, m+1) ans = max(ans, f[i].query(m));
    printf("%d\n", ans);
  }
  return 0;
}
