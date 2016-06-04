//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5248.cpp
 *  Date : 2015年8月5日 下午10:07:15
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 100010
int n, a[N];

bool judge(int k) {
  int now = a[0] - k;
  rep(i, 1, n) {
    now = max(now + 1, a[i] - k);
    if(now > a[i] + k) return false;
  }
  return true;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ <<":\n";
    cin >> n;
    rep(i, 0, n) cin >> a[i];

    int l = 0, r = 2000000;
    while (l < r) {
      int m = (l + r) >> 1;
      judge(m) ? r = m : l = m + 1;
    }
    cout << l << '\n';
  }
  return 0;
}
