/*
 *	Name : ZOJ3876.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月25日 下午11:11:03
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

int whatday(int y, int m, int d) {
  return (d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7 + 1;
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    int n; scanf("%d", &n);
    switch (whatday(n, 5, 1)) {
      case 1 : printf("9\n"); break;
      case 2 :
      case 7 : printf("6\n"); break;
      default: printf("5\n"); break;
    }
  }
  return 0;
}
