//@ Including Header
#include <csl_std.h>
#include <fenwick.h>

/*
 *  Name : hdu5493.cpp
 *  Date : 2015年9月27日 下午8:16:39
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

using csl::fenwick_tree;
#define maxn 100010
int n, ans[maxn];
struct node {
  int h, w;
} a[maxn];

bool cmp(const node& a, const node& b) {
  return a.h < b.h;
}

//@ Main Function
int main() {
  fenwick_tree<int> f;
  f.m_data.reserve(maxn);
  int _, __ = 0; scanf("%d", &_);
  while (_--) {
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d%d", &a[i].h, &a[i].w);
    sort(a, a + n, cmp);

    f.build(n);
    rep(i, 1, n+1) f.update(i, +1);
    bool imp = false;
    rep(i, 0, n) {
      int m = min(a[i].w, n - 1 - i - a[i].w);
      if (m < 0) { imp = true; break; }
      int p = search(f, m + 1);
      if (~p) f.update(p, -1), ans[p] = a[i].h;
      else { imp = true; break; }
    }

    printf("Case #%d: ", ++__);
    if (imp) printf("impossible\n");
    else rep(i, 1, n+1) printf("%d%c", ans[i], i < n ? ' ' : '\n');
  }
  return 0;
}
