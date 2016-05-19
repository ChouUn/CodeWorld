//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>
#include <fenwick.h>

/**
 *  Name : hdu1025.cpp
 *  Date : 2016年5月9日 下午11:49:25
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 500010;
pii a[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    std::cout << "Case " << __ << ":\n";
    rep(i, 0, n) {
      int x, y; cin >> x >> y;
      a[i] = make_pair(x, y);
    }
    sort(a, a + n);

    int ans = 0;
    csl::fenwick_tree<int,csl::max<int>> ft;
    ft.build(n);
    rep(i, 0, n) {
      int y = a[i].second;
      int z = ft.query(y) + 1;
      ans = max(ans, z);
      ft.update(y, z);
    }
    cout << "My king, at most " << ans << (ans > 1 ? " roads" : " road") << " can be built.\n\n";
  }
  return 0;
}
