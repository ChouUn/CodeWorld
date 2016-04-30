//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5491.cpp
 *  Date : 2015年9月27日 下午12:06:11
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  int _, __ = 0; scanf("%d", &_);
  while (_--) {
    printf("Case #%d: ", ++__);
    ll n; int s1, s2; scanf(i64 "%d%d", &n, &s1, &s2);

    int m = __builtin_popcount(++n);
    while (m > s2) n += n & -n, m = __builtin_popcount(n);
    if (m < s1) {
      ll t = 1;
      for (int i = s1 - m; i > 0; --i) {
        while (n & t) t <<= 1;
        n |= t;
      }
    }
    printf(i64 "\n", n);
  }
  return 0;
}
