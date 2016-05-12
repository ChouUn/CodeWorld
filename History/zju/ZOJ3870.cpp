/*
 *	Name : ZOJ3870.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月25日 下午10:43:14
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 100010
int num[maxN];
int cnt[maxN];

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", num + i);
    sort(num, num + n);
    memset(cnt, 0x00, sizeof(cnt));
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int p = 0;
      for (int k = 1; k <= num[i]; k <<= 1) {
        if (k & ~num[i]) ans += cnt[p];
        p++;
      }
      cnt[p-1]++;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
