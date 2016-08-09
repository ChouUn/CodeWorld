//@ Including Header
#include <csl_std.h>
#include <fenwick.h>

/**
 *  Name : 1012.cpp
 *  Date : 2016年7月28日 下午12:11:33
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int a[N], b[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ":";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    csl::fenwick_tree<int> ft;
    ft.build(n + 1);
    rep(i, 0, n) ft.update(a[i], +1);
    rep(i, 0, n) {
      ft.update(a[i], -1);
      int x = i + ft.query(a[i]), y = i, z = a[i] - 1;
      b[z] = max(x, z) - min(y, z);
    }
    rep(i, 0, n) cout << " " << b[i]; cout << endl;
  }
  return 0;
}
