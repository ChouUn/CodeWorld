//@ Including Header
#include <csl_std.h>
#include <manacher.h>

/*
 *  Name : hdu5371.cpp
 *  Date : 2015年8月14日 下午1:15:37
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 100010
int a[maxn];

//@ Main Function
int main() {
  int _, __ = 0;
  for (scanf("%d", &_); _; _--) {
    printf("Case #%d: ", ++__);

    int n; scanf("%d", &n);
    rep(i, 0, n) scanf("%d", &a[i]); a[n] = -3;

    csl::manacher<int,-1,-2,-3> m;
    m.build(a);

    priority_queue<pii> p;
    rep(i, 1, n) p.push(pii(m[i*2-1]>>1, i));

    int ans = 0;
    set<int> q;
    set<int>::iterator it;
    while (!p.empty()) {
      int u = p.top().first; if (!u) break;
      int i = p.top().second; p.pop();
      q.insert(i);
      it = --q.upper_bound(i + u);
      ans = max(ans, *it - i);
      it = q.lower_bound(i - u);
      ans = max(ans, i - *it);
    }
    printf("%d\n", ans * 3);
  }
  return 0;
}
