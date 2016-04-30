//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5375.cpp
 *  Date : 2015年8月15日 上午12:07:20
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 200010
int a[maxn];
char s[maxn];
ll f[maxn][2];
//@ Main Function
int main() {
  int _, __ = 0;
//  for (int n; scanf("%d", &n) != EOF; ) {
  for (scanf("%d", &_); _; _--) {
    printf("Case #%d: ", ++__);

    scanf("%s", s+1); int n = strlen(s+1);
    rep(i, 1, n+1) scanf("%d", a+i);

    memset(f, 0xff, sizeof(f));
    f[0][0] = 0;
    rep(i, 1, n+1) {
      ll f00 = ~f[i-1][0] ? f[i-1][0] : -1;
      ll f01 = ~f[i-1][0] ? f[i-1][0] + a[i] : -1;
      ll f10 = ~f[i-1][1] ? f[i-1][1] + a[i] : -1;
      ll f11 = ~f[i-1][1] ? f[i-1][1] : -1;
      f[i][0] = s[i] != '1' ? max(f00, f10) : -1;
      f[i][1] = s[i] != '0' ? max(f01, f11) : -1;
    }
    printf(i64 "\n", max(f[n][0], f[n][1]));
  }
  return 0;
}
