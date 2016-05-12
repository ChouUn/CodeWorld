//@ Including Header
// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#ifndef CSL_STD_H_
#define CSL_STD_H_ 20151122L
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<pii> vpii;

#define rep(i,a,b) for(auto i=a,i##_n=b;i<i##_n;++i)
#define per(i,a,b) for(auto i=b,i##_n=a;i-->i##_n;)

#endif /* CSL_STD_H_ */


/**
 *  Name : cf611f.cpp
 *  Date : 2016年1月4日 上午11:14:36
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 500010;
const int M = 1000000007;
int n, h, w; char s[N];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> h >> w >> s;

  int x = 0, y = 0, xmin = 0, xmax = 0, ymin = 0, ymax = 0;
  ll ans = 0;
  int l = 0;
  do {
    rep(k, 1, n+1) {
      int z = -1;
      switch(s[k-1]) {
        case 'U': z = 0; break;
        case 'R': z = 1; break;
        case 'D': z = 2; break;
        case 'L': z = 3; break;
        default : assert(false);
      }
      x += dx[z], y += dy[z];
      if(x < xmin) {
        xmin = x;
        if(xmax - xmin <= h && ymax - ymin <= w) ans = (ans + (ll)(w - ymax + ymin) * (l * n + k)) % M;
      }
      if(x > xmax) {
        xmax = x;
        if(xmax - xmin <= h && ymax - ymin <= w) ans = (ans + (ll)(w - ymax + ymin) * (l * n + k)) % M;
      }
      if(y < ymin) {
        ymin = y;
        if(xmax - xmin <= h && ymax - ymin <= w) ans = (ans + (ll)(h - xmax + xmin) * (l * n + k)) % M;
      }
      if(y > ymax) {
        ymax = y;
        if(xmax - xmin <= h && ymax - ymin <= w) ans = (ans + (ll)(h - xmax + xmin) * (l * n + k)) % M;
      }
    }
    if(xmax - xmin >= h || ymax - ymin >= w) break;
    if(x == 0 && y == 0) { ans = -1; break; }
//    cout << xmin << " " << xmax << " " << ymin << " " << ymax << endl;
    ++l;
  } while (true);
  cout << ans << endl;

  return 0;
}
