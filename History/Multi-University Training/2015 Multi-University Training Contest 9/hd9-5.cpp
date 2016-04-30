//@ Including Header
// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#ifndef CSL_STD_H_
#define CSL_STD_H_
#define CSL_STD_H_VERSION 20150814L
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int,int>  pii;
typedef long long           ll;
typedef unsigned long long  ull;
#ifdef _WIN32
#define i64         "%I64d"
#else
#define i64         "%lld"
#endif /* _WIN32 */
#define rep(i,a,n)  for (int i=a;i<n;++i)
#define rrep(i,a,n) for (int i=n-1;i>=a;--i)
#endif /* CSL_STD_H_ */

/*
 *  Name : hd9-5.cpp
 *  Date : 2015年8月18日 下午12:17:24
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 100010
int n, d1, d2;
int a[maxn], b[maxn], c[maxn];
//@ Main Function
int main() {
  while (scanf("%d%d%d", &n, &d1, &d2) != EOF) {
    rep(i, 0, n) scanf("%d", a+i);

    memset(b, 0xff, sizeof(b));
    memset(c, 0xff, sizeof(c));
    rep(i, 1, n) b[i] = a[i] - a[i-1]; b[n] = maxn;
    c[n-1] = n-1;
    rrep(i, 1, n-1) c[i] = (b[i] == b[i+1]) ? c[i+1] : i;

    ll ans = 0;
    rep(i, 0, n) {
      int d = i + 1;
      if (b[d] == d1) d = c[d] + 1;
      if (b[d] == d2) d = c[d] + 1;
      ans += d - i;
    }
    printf(i64 "\n", ans);
  }
  return 0;
}
