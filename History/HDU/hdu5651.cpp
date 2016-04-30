//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : hdu5651.cpp
 *  Date : 2016年3月31日 下午11:00:36
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 1010
#define P 1000000007
ll fac[N], inv[N];

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, N) fac[i] = fac[i-1] * i % P;
  inv[N-1] = csl::pow(ll(1), fac[N-1], P - 2, ll(P));
  rrep(i, 1, N) inv[i-1] = inv[i] * i % P;

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    string s; cin >> s;

    map<char, int> m;
    for (auto &si : s) ++m[si];

    int n = s.size(), cnt = 0;
    ll ans = fac[n/2];
    for (auto &mi : m) {
      cnt += mi.second & 1;
      ans = ans * inv[mi.second/2] % P;
    }
    cout << (cnt > 1 ? 0ll : ans) << endl;
  }
  return 0;
}
