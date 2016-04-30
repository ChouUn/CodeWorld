//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>

/*
 *  Name : hdu5442.cpp
 *  Date : 2015年9月17日 上午11:47:07
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 20010
char s[maxn], t1[maxn*2], t2[maxn*2];
//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    int n; scanf("%d", &n);
    scanf("%s", s);

    rep(i, 0, n) t1[i] = t1[n+i] = s[i];
    rep(i, 0, n) t2[i] = t2[n+i] = s[n-1-i];
    t1[2*n] = 0, t2[2*n] = 0;
    int x = csl::isomorph_min(t1, n, std::greater<char>());
    int y = csl::isomorph_max(t2, n, std::greater<char>());
    t1[x+n] = 0, t2[y+n] = 0;

    int ans1 = x + 1, ans2 = n - y;
    int z = strcmp(t1+x, t2+y);
    if (z)
      printf("%d %d\n", z > 0 ? ans1 : ans2, z <= 0);
    else
      printf("%d %d\n", min(ans1,ans2), ans1 > ans2);
  }
  return 0;
}
