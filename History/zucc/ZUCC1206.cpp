/*
 *	Name : ZUCC1206.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月30日 上午11:06:09
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <stdio.h>
#include <bitset>
#include <iostream>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxb (6)
#define maxL (1<<maxb)
#define maxl (maxL-1)
#define maxK 1600
#define maxN 100010
struct node {
  bitset<maxL> data;
  int size;
  int count;
  bool flip;
  void update() {
    flip ^= 1;
    count = size - count;
  }
  void update(int u, int v) {
//    printf("u = %d, v = %d\n", u, v);
    if (flip) data.flip();
    flip = 0;
    for (int i = u; i <= v; i++) data.flip(i);
    count = 0;
    for (int i = 0; i < size; i++) count += data[i];
  }
};

int n, m, k;
node f[maxK];

char s[maxN];
void Input() {
  scanf("%s", s);
  k = -1;
  for (int i = 0; i < n; i++) {
    if (!(i&maxl)) {
//      printf("i = %d, init\n", i);
      k++;
      f[k].data.reset();
      f[k].size = 0;
      f[k].flip = 0;
      f[k].count = 0;
    }
    f[k].size++;
    if (s[i] == '7') {
      f[k].data[i&maxl] = 1;
      f[k].count++;
    }
  }
}

void update(int u, int v) {
  for (int i = 0; i <= k; i++) {
    int l = (i << maxb);
    int r = (i << maxb) + f[i].size - 1;
    if (r < u) continue;
    if (v < l) break;
    if (u <= l && r <= v)
      f[i].update();
    else
      f[i].update(max(l, u) & maxl, min(v, r) & maxl);
  }
}

int count() {
  int res = 0;
  for (int i = 0; i <= k; i++) res += f[i].count;
  return res;
}

//@ Main Function
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    Input();
    while (m--) {
      scanf("%s", s);
      if (s[0] == 'r') {
        int u, v; scanf("%d%d", &u, &v);
        update(u - 1, v - 1);
      }
      else
        printf("%d\n", count());
    }
//    printf("f[0], size = %d, count = %d, flip = %d\n", f[0].size, f[0].count, f[0].flip);
//    cout << f[0].data << endl;
  }
  return 0;
}
