//@ Including Header
#include <csl_std.h>

/**
 *  Name : 1002.cpp
 *  Date : 2016年7月26日 下午12:23:10
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    vector<int> v(n); for (auto &x : v) cin >> x;

    if (n == 1) {
      cout << v[0] << endl;
      continue;
    }

    int p = 0, q = 0;
    rep(i, 2, n + 1) p += i - 1;
    rep(i, 3, n + 1) q += (i - 1) * (i - 2);

    double x = p * 1. / (n * (n - 1)), y = q * 1. / (n * (n - 1) * (n - 2));
    double ans = (v[0] + v[n - 1]) * x;
    rep(i, 1, n - 1) ans += v[i] * y;
    cout << fixed << setprecision(6) << ans << endl;
  }
  return 0;
}
