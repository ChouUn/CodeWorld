//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6391.cpp
 *  Date : 2016年7月11日 上午11:57:08
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 510;
double a[N];

double solve(int i, int j, int k, int l) {
  double p = (a[k] - a[i]) / 2;
  double q = (a[l] - a[j]) / 2;
  double r = (a[j] - a[i] + a[l] - a[k]) / 2;
  double s = (p * p - q * q + r * r) / (2 * p * r);
  return p * sqrt(1 - s * s) / (a[k] - a[j]);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    double ans = 0;
    rep(i, 1, n) rep(j, i + 1, n)
      ans = max(ans, solve(0, i, j, n - 1));
    cout << int(ans) % 10 << endl;
  }
  return 0;
}
