//@ Including Header
#include <csl_std.h>

/**
 *  Name : jsk 2016 - R2B.cpp
 *  Date : 2016年6月5日 下午1:24:01
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    ll n, m; cin >> n >> m;
//    int ans = (n * m) * (n * m - 1) / 2;
//    if (n >= 3) ans -= n * (n - 1) * (n - 2) / 6 * m;
//    if (m >= 3) ans -= m * (m - 1) * (m - 2) / 6 * n;
//    rep(i, 1, n) rep(j, 1, m) ans -= 2 * (n - i) * (m - j) * (__gcd(i, j) - 1);

    ll ans = n + m;
    rep(i, 1ll, n) rep(j, 1ll, m) if (__gcd(i, j) == 1) {
      ll tmp = (max(n - i * 2, 0ll) * min(m - j, j) + (m - j) * min(i, n - i)) * 2;
//      cout << i << " " << j << " " << tmp << " ";
//      cout << n - i * 2 << " " << min(m - j, j) << " ";
//      cout << m - j << " " << i << endl;
      ans += tmp;
    }
    cout << ans % (1ll << 30) << endl;
  }
  return 0;
}
