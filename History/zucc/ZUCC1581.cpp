/*
 *	Name : ZUCC1581.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月26日 下午7:59:32
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <stdio.h>
#include <vector>
#include <algorithm>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 200010
struct node {
  int l, r;
  bool operator < (const node& b) const {
    return r < b.r;
  }
};
node u[maxN];

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int x, w; scanf("%d%d", &x, &w);
      u[i].l = x - w;
      u[i].r = x + w;
    }
    sort(u, u + n);
    int ans = 1;
    for (int i = 1, k = 0; i < n; i++)
      if (u[i].l >= u[k].r) k = i, ans++;
    printf("%d\n", ans);
  }
  return 0;
}
