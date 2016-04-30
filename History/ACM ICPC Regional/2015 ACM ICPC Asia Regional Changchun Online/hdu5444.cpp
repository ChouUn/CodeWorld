//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5444.cpp
 *  Date : 2015年9月18日 下午4:20:29
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 1010
int a[maxn], b[maxn], c[maxn];

int dfs(int l, int r) {
  if (l > r) return -1;
  int x = l;
  for (int i = l + 1; i <= r; ++i)
    if (a[i] < a[x]) x = i;
  b[x] = dfs(l, x - 1);
  c[x] = dfs(x + 1, r);
  return x;
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    int n; scanf("%d", &n);
    rep(i, 0, n) {
      int x; scanf("%d", &x);
      a[x] = i + 1;
    }
    int r = dfs(1, n);

    int q; scanf("%d", &q);
    while (q--) {
      int x; scanf("%d", &x);
      int t = r;
      while (t != x) {
        printf("%c", t > x ? 'E' : 'W');
        t = (t > x) ? b[t] : c[t];
      }
      printf("\n");
    }
  }
  return 0;
}
