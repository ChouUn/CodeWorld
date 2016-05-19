/*
 *	Name : ZUCC1559.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月26日 下午7:06:54
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <stdio.h>
#include <queue>
//@ Using Namespace
//using namespace std;
//@ Program Begin

#define maxN 100010
int n, p, q;
int d[maxN], f[maxN];

template <typename _Tp>
inline bool
exmax(_Tp &x, const _Tp& y)
{ return (x < y) ? ((x = y) && 1) : (0); }

bool solve() {
  std::queue<int> s;
  for (int i = 0; i <= n; i++) {
    d[i] = (i >= p) + (i + q <= n);
    f[i] = 0;
    if (!d[i]) s.push(i);
  }

  while (!s.empty()) {
    int u = s.front(); s.pop();
    if (u + p <= n) {
      exmax(f[u + p], f[u] + 1);
      if (--d[u + p] == 0) s.push(u + p);
    }
    if (u >= q) {
      exmax(f[u - q], f[u] + 1);
      if (--d[u - q] == 0) s.push(u - q);
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) ans += !d[i];
  return ans == n + 1;
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    scanf("%d%d%d", &n, &p, &q);
    if (solve()) {
      printf("yes\n");
      for (int i = 1; i <= n; i++)
        printf("%d%c", f[i] - f[i-1], (i == n) ? '\n' : ' ');
    }
    else
      printf("no\n");
  }
  return 0;
}
