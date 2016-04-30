/*
 *	Name : BC44C.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年6月14日 下午12:42:25
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <csl_std.h>
//@ Using Namespace
using namespace std;
//@ The magic ends here.

#define maxn 100010
#define maxl 61
int64 a[maxn], b[maxn];

void msort(int64 a[], int n, int k) {
  static int64 data[2][maxn];
  static int size[2];
  size[0] = size[1] = 0;
  for (int i = 0; i < n; i++) {
    int d = (a[i] >> k) & 1;
    data[d][size[d]++] = a[i];
  }
  for (int i = 0; i < size[0]; i++) a[i] = data[0][i];
  for (int i = 0; i < size[1]; i++) a[i+size[0]] = data[1][i];
}

//@ Main Function
int main() {
  int _, __ = 0;
  for (scanf("%d", &_); _; _--) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf(i64, a + i);
    for (int i = 0; i < n; i++) scanf(i64, b + i);

    int64 ans = 0;
    for (int k = 0; k <= maxl; k++) {
      msort(a, n, k); msort(b, n, k);
      int64 lim1 = 1LL << k, lim2 = lim1 << 1, cut = lim2 - 1;
      int x = 0, y = 0, z = 0; int64 sum = 0;
      for (int i = n - 1; i >= 0; i--) {
        while (x < n && (a[i]&cut) + (b[x]&cut) < lim1) x++;
        while (y < n && (a[i]&cut) + (b[y]&cut) < lim2) y++;
        while (z < n && (a[i]&cut) + (b[z]&cut) < lim1 + lim2) z++;
        sum += n - x + y - z;
      }
      if (sum & 1) ans += 1LL << k;
    }
    printf("Case #%d: ", ++__);
    printf(i64 "\n", ans);
  }
  return 0;
}
