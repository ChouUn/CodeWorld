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
 *  Name : zucc1634.cpp
 *  Date : 2016年4月6日 下午7:23:50
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 1010
#define P 790660457
ll f[N*2][N];

//@ Main Function
int main() {
  f[0][0] = 1;
  rep(i, 1, 2*N) {
    rep(j, 0, N) f[i][j] = f[i-1][j];
    per(j, 1, N) f[i][j] = (f[i][j] + f[i][j-1]) % P;
  }

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    assert(1 <= n && n <= 1000);
    assert(0 <= m && m <= 1000);

    cout << f[m+n-1][n-1] << endl;
  }
  return 0;
}
