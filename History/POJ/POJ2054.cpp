/*
 *    Name : POJ2054.cpp
 *    Author : CHN.ChouUn
 *    Date : 2015年5月28日 下午3:22:35
 *    Copyright : www.fateud.com
 *    Description : None
 */

//@ Including Header
#include <stdio.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 1010
struct node {
  int cost;
  int time;
  int w;
  int v;
  bool operator >= (const node& b) const {
    return cost * b.time >= time * b.cost;
  }
};

int n, r;
node a[maxN];
int p[maxN];

inline void
Input() {
  for (int i = 1; i <= n; i++) {
    int t; scanf("%d", &t);
    a[i].cost = t;
    a[i].time = 1;
    a[i].w = t;
  }
  a[r].v = 0;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[v].v = u;
  }
}

inline void
Init() {
  for (int i = 1; i <= n; i++) p[i] = i;
}

inline int
find(int u) {
  return (u == p[u]) ? (u) : (p[u] = find(p[u]));
}

inline int
Solve() {
  for (int k = 1; k < n; k++) {
    int u = 0;
    for (int i = 1; i <= n; i++) {
      if (i == r) continue;
      if (p[i] != i) continue;
      if (u && a[u] >= a[i]) continue;
      u = i;
    }
    int v = find(a[u].v);
    a[v].w += a[u].w + a[u].cost * a[v].time;
    a[v].cost += a[u].cost;
    a[v].time += a[u].time;
    p[u] = v;
  }
  return a[r].w;
}

//@ Main Function
int main() {
  while (scanf("%d%d", &n, &r) != EOF && n && r) {
    Input();
    Init();
    int ans = Solve();
    printf("%d\n", ans);
  }
  return 0;
}
