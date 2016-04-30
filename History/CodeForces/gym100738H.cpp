//@ Including Header
#include <csl_std.h>
#include <discrete.h>

/*
 *  Name : gym100738H.cpp
 *  Date : 2015年10月11日 下午9:20:03
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxm 100000000
#define maxn 256
#define fail 0
#define succ 1

int a[maxn], an, base;
csl::discrete<int> s;

int judge1() {
  for (int i = 1; i < an; ++i) a[an + i] = a[an - i];
  long long x = 0;
  for (int i = an * 2 - 1; i > 0; --i) {
    x = x * base + a[i];
    if (x > maxm) return fail;
  }
  s.insert(x);
  return succ;
}

int judge2() {
  for (int i = 1; i <= an; ++i) a[an + i] = a[an - i + 1];
  long long x = 0;
  for (int i = an * 2; i > 0; --i) {
    x = x * base + a[i];
    if (x > maxm) return fail;
  }
  s.insert(x);
  return succ;
}

int dfs() {
  if (judge1() == fail) return fail;
  if (judge2() == fail) return succ;
  for (int i = 0; i < base; ++i) {
    a[++an] = i;
    int x = dfs();
    --an;
    if (x == fail) break;
  }
  return succ;
}

//@ Main Function
int main() {
  int n; scanf("%d", &n);
  while (n--) {
    scanf("%d", &base);
    for (int i = 1; i < base; ++i) {
      a[an = 1] = i;
      dfs();
    }
  };

  s.insert(0);
  s.build();

  int q; scanf("%d", &q);
  while (q--) {
    int x, y; scanf("%d%d", &x, &y);
    int p = lower_bound(s.m_data.begin(), s.m_data.end(), x) - s.m_data.begin();
    int q = upper_bound(s.m_data.begin(), s.m_data.end(), y) - s.m_data.begin();
    printf("%d\n", q - p);
  }

  return 0;
}
