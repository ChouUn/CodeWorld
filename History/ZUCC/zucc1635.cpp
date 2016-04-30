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
 *  Name : zucc1635.cpp
 *  Date : 2016年4月7日 上午12:28:30
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 100000
#define M 1000

ll b[M+1], c[M+M+1], s[M+1];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    assert(1 <= n);
    assert(n <= N);

    memset(b, 0x00, sizeof b);
    rep(i, 0, n) {
      int x; cin >> x;
      assert(1 <= x);
      assert(x <= M);
      ++b[x];
    }

    rep(i, 0, M+1) s[i] = i ? s[i-1] + b[i] : 0;
    rep(i, 0, M+1) assert(0 <= s[i] && s[i] <= n);

    memset(c, 0x00, sizeof c);
    rep(i, 1, M+1) rep(j, 1, M+1) c[i+j] += b[i] * b[j];
    rep(i, 0, M+M+1) c[i] = (c[i] - (i & 1 ? 0 : b[i/2])) / 2;

    ll ans = ll(n) * (n-1) / 2 * (n-2) / 3;
    rep(i, 2, M+1) ans -= c[i] * (n - s[i-1]);
    cout << ans << endl;
    assert(0 <= ans);
  }
  return 0;
}
