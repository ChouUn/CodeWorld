//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju5398.cpp
 *  Date : 2015年12月29日 下午2:24:08
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int n, m; cin >> n >> m;
    vector<int> v(n);
    rep(i, 0, n) cin >> v[i];
    int p = 0, d = 1, ans = -1, cnt = 0;
    for (int k = n + 5; k; k--) {
      ans = p, v[p] -= m;
      if (v[p] <= 0) d = -d, cnt ++;
      if (cnt == n) break;
      do { p = (p + d + n) % n; } while (v[p] <= 0);
    }
    printf("%d\n", ans + 1);
  }
  return 0;
}
