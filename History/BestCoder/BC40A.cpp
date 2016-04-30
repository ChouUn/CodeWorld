/*
 *	Name : BC40A.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月15日 上午10:26:15
 *	Copyright : www.fateud.com
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
    for (int i = sqrt(n); i > 0; i--) {
      if (n % i == 0) {
        printf("%d\n", (i + n / i) << 1);
        break;
      }
    }
  }
  return 0;
}
