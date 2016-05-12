//@ Including Header
#include <csl_std.h>
#include <discrete.h>
#include <fenwick.h>

typedef csl::discrete<int> dis;
typedef csl::fenwick_tree<int> ft;

/**
 *  Name : zucc1623.cpp
 *  Date : 2016年3月28日 上午9:27:40
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 1010
int a[N], b[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    dis d;
    d.insert(a, a + n);
    d.build();
    rep(i, 0, n) a[i] = d.query(a[i]) + 1;

    ft f;
    f.build(n);
    rep(i, 0, n) b[i] = f.query(a[i]), f.update(a[i], +1);

    int x = 0, y = 0;
    rep(i, 0, n) {
      x += min(b[i], a[i] - 1 - b[i]);
      y += min(i - b[i], n - 1 - i - a[i] + 1 + b[i]);
    }
    cout << min(x, y) << endl;
  }
  return 0;
}
