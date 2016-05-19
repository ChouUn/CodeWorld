//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : hdu3908.cpp
 *  Date : 2016年3月31日 下午11:52:36
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 810
int a[N], b[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i], b[i] = 0;

    rep(i, 0, n) rep(j, i+1, n)
      if (csl::gcd(a[i], a[j]) == 1) ++b[i], ++b[j];

    int ans = n * (n-1) / 2 * (n-2) / 3, cnt = 0;
    rep(i, 0, n) cnt += b[i] * (n - 1 - b[i]);
    cout << ans - cnt / 2 << endl;
  }
  return 0;
}
