//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6447.cpp
 *  Date : 2016年7月13日 上午9:26:05
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
struct node {
  int x, y, z;
};
node a[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, p, k; cin >> n >> p >> k;
    rep(i, 0, n) cin >> a[i].x >> a[i].y, a[i].z = 0;

    sort(a, a + n, [](const node& x, const node& y) -> bool {
      return x.y != y.y ? x.y > y.y : x.x > y.x;
    });
    sort(a, a + n - (p - k), [](const node& x, const node& y) -> bool {
      return x.x != y.x ? x.x > y.x : x.y > y.y;
    });

    ll ans1 = 0;
    rep(i, 0, k) a[i].z = 1, ans1 += a[i].x;
    sort(a, a + n, [](const node& x, const node& y) -> bool {
      return x.y != y.y ? x.y > y.y : x.x > y.x;
    });

    int m = 0;
    rep(i, 0, n) if (a[i].z) m = i;
    ll ans2 = 0;
    rep(i, 0, p - k) ans2 += a[m + 1 + i].y;
    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
