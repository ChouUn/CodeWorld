//@ Including Header
#include <csl_std.h>
#include <fenwick.h>

/*
 *  Name : hdu5497.cpp
 *  Date : 2015年11月12日 下午12:01:56
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 100010
int a[maxn];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int n, m; cin >> n >> m;
    rep(i, 0, n) cin >> a[i];

    csl::fenwick_tree<int> f; f.build(n);
    csl::fenwick_tree<int> g; g.build(n);

    ll cnt = 0;
    per(i, m, n) {
      cnt += g.query(a[i] - 1);
      g.update(a[i], +1);
    }

    ll ans = cnt;
    rep(i, 0, n-m) {
      cnt += f.query(n) - f.query(a[i]) + g.query(a[i] - 1);
      f.update(a[i], +1);
      cnt -= f.query(n) - f.query(a[i+m]) + g.query(a[i+m] - 1);
      g.update(a[i+m], -1);
      ans = min(ans, cnt);
    }
    cout << ans << endl;
  }
  return 0;
}
