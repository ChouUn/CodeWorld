//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu2204.cpp
 *  Date : 2016年4月1日 上午12:19:19
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int z[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
const int x[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 30, 31, 37, 41, 42, 43, 47, 53, 59};
const int y[] = {6, 10, 14, 15, 21, 22, 26, 33, 34, 35, 38, 39, 46, 51, 55, 57, 58};
const double eps = 1e-6;

inline int solve(ll n, int k) {
  int p = pow(n, 1. / k) + eps;
  if (pow(p, k) > n) --p;
  return p > 1 ? p - 1 : 0;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(ll n; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    ll ans = 0;
    for (auto &xi : x) ans += solve(n, xi);
    for (auto &yi : y) ans -= solve(n, yi);
    cout << ans + 1 << endl;
  }
  return 0;
}
