//@ Including Header
#include <csl_std.h>
#include <discrete.h>
#include <fenwick.h>

/**
 *  Name : hdu4911.cpp
 *  Date : 2016年4月26日 下午2:09:57
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 100010
int a[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, k; cin >> n >> k; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, n) cin >> a[i];

    csl::discrete<int> d; d.reserve(n);
    d.insert(a, a + n);
    d.build();
    rep(i, 0, n) a[i] = d.query(a[i]) + 1;

    csl::fenwick_tree<int> ft;
    ft.build(n);
    ll ans = 0;
    rep(i, 0, n) {
      ans += ft.query(n) - ft.query(a[i]);
      ft.update(a[i], +1);
    }
    cout << max(ans - k, 0ll) << endl;
  }
  return 0;
}
