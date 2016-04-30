/*
 *	Name : ZUCC1510.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月30日 上午8:59:18
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <stdio.h>
#include <algorithm>
//@ Using Namespace
using namespace std;
//@ Program Begin

char str[110];
struct node {
  long long h;
  long long l;
  node() : h(), l() { }
  node(long long p_h, long long p_l) : h(p_h), l(p_l) { }
  void init(int m) {
    char* p = str;
    scanf("%s", p);
    h = l = 0;
    if (m > 50) {
      for (int i = 0; i < m - 50; i++)
        h = (h << 1) | (p[i] ^ '0');
      p += m - 50;
    }
    for (int i = 0; p[i]; i++)
      l = (l << 1) | (p[i] ^ '0');
  }
  bool operator != (const node& b) const {
    return h != b.h || l != b.l;
  }
  bool operator < (const node& b) const {
    return (h == b.h) ? (l < b.l) : (h < b.h);
  }
  node operator ^ (const node& b) const {
    return node(h ^ b.h, l ^ b.l);
  }
};

#define maxN 210
int n, m;
node f[maxN], g[maxN], h[maxN];

int popcount(long long n) {
  int res = 0;
  while (n) {
    res += n & 1;
    n >>= 1;
  }
  return res;
}

void Solve() {
  sort(g, g + n);
  int ans = m + 1;
  for (int i = 0; i < n; i++) {
    node t = f[i] ^ g[0];
    for (int j = 0; j < n; j++)
      h[j] = f[j] ^ t;
    sort(h, h + n);

    bool flag = false;
    for (int j = 0; j < n; j++)
      if (h[j] != g[j]) {
        flag = true;
        break;
      }
    if (flag) continue;
    int tmp = popcount(t.h) + popcount(t.l);
    ans = min(ans, tmp);
  }
  if (ans > m)
    printf("NOT POSSIBLE\n");
  else
    printf("%d\n", ans);
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  for (int T = 1; T <= _; T++) {
    printf("Case #%d: ", T);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) f[i].init(m);
    for (int i = 0; i < n; i++) g[i].init(m);
    Solve();
  }
  return 0;
}
