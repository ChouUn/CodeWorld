//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1647.cpp
 *  Date : 2016年5月20日 上午1:55:28
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 110;
const int M = 100010;
int a[N], b[N], f[M];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    rep(i, 0, n) cin >> a[i] >> b[i];
    m = accumulate(a, a + n, 0) - m;

    memset(f, 0x00, sizeof f);
    rep(i, 0, n) per(j, a[i], m + 1) f[j] = max(f[j], f[j - a[i]] + b[i]);
    cout << f[m] << endl;
  }
  return 0;
}
