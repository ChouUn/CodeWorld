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
 *  Name : hd9-7.cpp
 *  Date : 2015年8月18日 下午3:34:10
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 110
int n, m;
int a[maxn][maxn];
//@ Main Function
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    rep(i, 0, n) rep(j, 0, m) scanf("%d", &a[i][j]);
    int cnt = 0;
    rep(i, 0, n) rep(j, 0, m) cnt += a[i][j];
    if (n & 1) {
      printf("%d\n", cnt);
      rep(i, 0, n) {
        if (i) printf("D");
        rep(j, 1, m) printf(i & 1 ? "L" : "R");
      }
      printf("\n");
    }
    else if (m & 1) {
      printf("%d\n", cnt);
      rep(i, 0, m) {
        if (i) printf("R");
        rep(j, 1, n) printf(i & 1 ? "U" : "D");
      }
      printf("\n");
    }
    else {
      int tmp = 0x7fffffff, x, y;
      rep(i, 0, n) rep(j, 0, m)
        if (((i + j) & 1) && a[i][j] < tmp) tmp = a[i][j], x = i, y = j;
      cnt -= tmp;
      printf("%d\n", cnt);
      bool flag = true;
      for (int i = 0; i < n; i += 2) {
        if (i) printf("D");
        if (i == x || i + 1 == x) {
          for (int j = 0; j < m; j += 2) {
            if (j) printf("R");
            if (j == y || j + 1 == y) {
              if (i == x && j + 1 == y) printf("DR");
              else printf("RD");
              flag = false;
            }
            else {
              printf(flag ? "DRU" : "URD");
            }
          }
        }
        else {
          rep(j, 1, m) printf(flag ? "R" : "L");
          printf("D");
          rep(j, 1, m) printf(flag ? "L" : "R");
        }
      }
      printf("\n");
    }
  }
  return 0;
}
