//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>
#include <geometry.h>

/**
 *  Name : zucc1633.cpp
 *  Date : 2016年3月31日 上午10:33:39
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 100010
typedef csl::point point;
point p[N], q;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> p[i].x >> p[i].y;

    int ans = 0;
    int k; cin >> k;
    while (k--) {
      cin >> q.x >> q.y;
      int l = 1, r = n - 1;
      while (l < r) {
        int m = (l + r + 1) >> 1;
        if (csl::sgn((q - p[0]) ^ (p[m] - p[0])) >= 0) l = m;
        else r = m - 1;
      }
      if (csl::sgn((q - p[0]) ^ (p[1] - p[0])) <= 0) ++ans;
      else if (csl::sgn((q - p[0]) ^ (p[n-1] - p[0])) >= 0) ++ans;
      else if (csl::sgn((q - p[l]) ^ (p[l+1] - p[l])) <= 0) ++ ans;
    }
    if (ans) cout << ans << endl;
    else cout << "YES" << endl;
  }
  return 0;
}
