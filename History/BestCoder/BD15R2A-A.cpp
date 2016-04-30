/*
 *	Name : BD15R2A-A.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月30日 下午5:08:26
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <csl_std.h>
//@ Program Begin

#define maxN 10010
int64 a[maxN];

bool solve() {
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%I64d", a + i);
  std::sort(a, a + n);
  int p = -1;
  while (p + 1 < n && a[p + 1] <= m) p++;
  if (p == -1) return false;
  while (p + 1 < n) {
    int q = p;
    while (q + 1 < n && a[q + 1] <= a[p] + k) q++;
    if (p == q) break;
    p = q; k = std::max(k - 1, 0);
  }
  return p == n - 1;
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  for (int T = 1; T <= _; T++) {
    printf("Case #%d:\n", T);
    printf(solve() ? "why am I so diao?\n" : "madan!\n");
  }
  return 0;
}
