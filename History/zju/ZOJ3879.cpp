/*
 *	Name : zju3879.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��25�� ����11:32:44
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 110
typedef pair< int, pair<int,int> > piii;

int n, q, s, t;
double score[maxN];

int cnt[maxN][11];
void sa() {
  set<piii> p; memset(cnt, 0x00, sizeof(cnt));
  int m; scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x, y, z; scanf("%d%d%d", &x, &y, &z);
    piii t = make_pair(x, make_pair(y, z));
    if (p.find(t) != p.end()) continue;
    p.insert(t); cnt[y][z]++;
  }
  for (set<piii>::iterator i = p.begin(); i != p.end(); i++) {
    int x = i->first;
    int y = i->second.first;
    int z = i->second.second;
    score[x] += (n - 1.) / cnt[y][z];
    score[y] -= (n - 1.) / cnt[y][z];
  }
}

int vis[maxN];
void sb() {
  int p = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", vis + i);
    p += vis[i];
  }
  double delta = (n == p) ? (0) : ((n - p) * (n - 1.) / p);
  for (int i = 1; i <= n; i++)
    if (vis[i]) score[i] += delta;
    else score[i] -= (n - 1.);
}

int pnt[maxN], rank[maxN];
bool cmp(const int &a, const int &b) {
  return score[a] > score[b];
}
void sc() {
  for (int i = 1; i <= n; i++) pnt[i] = i;
  sort(pnt + 1, pnt + n + 1, cmp);
  double flag = -1; int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (fabs(flag - score[pnt[i]]) > 1e-5) flag = score[pnt[i]], sum = i;
    rank[pnt[i]] = sum;
  }
  int m; scanf("%d", &m);
  while (m--) {
    int x; scanf("%d", &x);
    printf("%.8f %d\n", score[x], rank[x]);
  }
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    scanf("%d%d%d%d", &n, &q, &s, &t);
    for (int i = 1; i <= n; i++) score[i] = s;
    while (t--) {
      sa();
      for (int j = 0; j < q; j++) sb();
      sc();
    }
  }
  return 0;
}
