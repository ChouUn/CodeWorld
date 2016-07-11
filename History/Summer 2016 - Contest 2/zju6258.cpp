//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6258.cpp
 *  Date : 2016年7月6日 上午8:37:51
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int a[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    ll sum = 0;
    rep(i, 0, m) sum += (ll)a[i] * a[2 * m - 1 - i];
    cout << sum << endl;
  }
  return 0;
}
