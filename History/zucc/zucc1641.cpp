//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1641.cpp
 *  Date : 2016年5月4日 上午12:43:12
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
ll a[N], b[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    rep(i, 1, n) b[i] = a[i] - a[i-1];
    sort(b + 1, b + n, greater<int>());
    rep(i, 1, n) a[i] = a[i-1] + b[i];
    cout << accumulate(a, a + n, 0ll) << endl;
  }
  return 0;
}
