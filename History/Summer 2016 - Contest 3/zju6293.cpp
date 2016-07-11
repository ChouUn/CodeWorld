//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6293.cpp
 *  Date : 2016年7月7日 上午8:42:41
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 1010;
int n, k, a[N], b[N];

bool check(int m) {
  int cnt = 0;
  rep(i, 0, n) cnt += max(a[i] * m - b[i], 0);
  return cnt <= k;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> n >> k;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    int l = 0, r = 2010;
    while (l < r) {
      int m = (l + r) / 2 + 1;
      if (check(m)) l = m;
      else r = m - 1;
    }
    cout << l << endl;
  }
  return 0;
}
