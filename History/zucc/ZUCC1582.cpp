/*
 *	Name : ZUCC1582.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月27日 下午8:23:50
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <stdio.h>
//@ Using Namespace
//using namespace std;
//@ Program Begin

int n, a[4], p[4], q[4];

bool calc(int k) {
  for (int i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      if (a[i] % n) return true;
      p[i] = a[i] / n - 1;
      q[i] = n;
    }
    else {
      p[i] = a[i] / n;
      q[i] = a[i] % n;
    }
  }
  return false;
}

bool check() {
  for (int k = 0; k < 16; k++) {
    if (calc(k)) continue;
    int ps = p[0] + p[1] + p[2] + p[3];
    int qs = q[0] + q[1] + q[2] + q[3];
    if (4 * n - qs != ps) continue;
    if (3 * n - qs + q[0] < p[0]) continue;
    if (3 * n - qs + q[1] < p[1]) continue;
    if (3 * n - qs + q[2] < p[2]) continue;
    if (3 * n - qs + q[3] < p[3]) continue;
    return true;
  }
  return false;
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    scanf("%d", &n);
    for (int i = 0; i < 4; i++)
      scanf("%d", a + i);

    bool ans;
    if (n == 1) {
      for (int i = 0; i < 4; i++)
        if (a[i] != 1) ans = false;
    }
    else
      ans = check();
    printf(ans ? "Y\n" : "N\n");
  }
  return 0;
}
