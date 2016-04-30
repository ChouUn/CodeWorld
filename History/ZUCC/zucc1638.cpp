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
#define rrep(i,a,b) for(auto i=b,i##_n=a;i-->i##_n;)

#endif /* CSL_STD_H_ */


/**
 *  Name : zucc1638.cpp
 *  Date : 2016年4月15日 上午10:17:44
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 100
#define M 100001
#define P 790660457
ll f[M];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    memset(f, 0x00, sizeof f);
    f[0] = 1;
    rep(j, 0, n) {
      int k = n - j;
      rep(i, k, m+1) f[i] = (f[i] + f[i-k]) % P;
    }
    cout << f[m] << endl;
  }
  return 0;
}
