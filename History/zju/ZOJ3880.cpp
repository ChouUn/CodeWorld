/*
 *	Name : zju3880.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��26�� ����12:12:31
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    int n; scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x; scanf("%d", &x);
      if (x > 6000) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
