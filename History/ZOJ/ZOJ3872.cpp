/*
 *	Name : ZOJ3872.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月25日 下午10:47:34
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
    map<int,int> pos;
    long long ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
      int x; scanf("%d", &x);
      sum += ((long long)i - pos[x]) * x;
      ans += sum;
      pos[x] = i;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
