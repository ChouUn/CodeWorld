//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5373.cpp
 *  Date : 2015年8月11日 下午12:33:28
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 3000010
int f1[maxn], f2[maxn], f3[10];

//@ Main Function
int main() {
  f1[0] = f2[0] = 0; f3[0] = 1;
  rep(i, 1, maxn) f1[i] = f1[i/10] + 1, f2[i] = f2[i/10] + i%10;
  rep(i, 1, 10) f3[i] = f3[i-1] * 10;

  int __ = 0;
  for (int n, t; scanf("%d%d", &n, &t) != EOF && (~n) && (~t); ) {
//  for (scanf("%d", &_); _; _--) {
    printf("Case #%d: ", ++__);
	ll s = f2[n], m = n % 11;
	while (t--) {
	  m = (m * f3[f1[s]] + s) % 11;
	  s = s + f2[s];
	}
    printf(m == 0 ? "Yes\n" : "No\n");
  }
  return 0;
}
