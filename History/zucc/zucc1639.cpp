//@ Including Header
// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#ifndef CSL_STD_H_
#define CSL_STD_H_ 20151122L
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
 *  Name : zucc1639.cpp
 *  Date : 2016年4月14日 上午10:31:03
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 100010
int a[N], s[N][6];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 1, n+1) {
      char ch; cin >> ch;
      switch (ch) {
        case 'r': a[i] = 0; break;
        case 'g': a[i] = 1; break;
        case 'b': a[i] = 2; break;
      }
    }

    memset(s, 0x00, sizeof s);
    rep(i, 1, n+1) {
      s[i][0] = s[i-1][0];
      s[i][1] = s[i-1][1];
      s[i][2] = s[i-1][2];
      ++s[i][a[i]];
      s[i][3] = s[i][1] - s[i][0];
      s[i][4] = s[i][2] - s[i][1];
      s[i][5] = s[i][0] - s[i][2];
    }

    int ans = 0;
    rep(k, 3, 6) {
      int mi = s[0][k], ma = s[0][k];
      rep(i, 1, n+1) {
        mi = min(mi, s[i][k]);
        ma = max(ma, s[i][k]);
      }
      ans = max(ans, ma - mi);
    }
    cout << ans * 2 << endl;
  }
  return 0;
}

