//@ Including Header
#include <csl_std.h>
#include <csl_math.h>
#include <ntt.h>

/**
 *  Name : zju5399.cpp
 *  Date : 2015年12月29日 下午2:25:58
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define mod 786433

//@ Main Function
int main() {
  csl::ntt<ll> func(mod, 10);
  vector<ll> bas(1, 1), mul(4, 1);

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int n, m; cin >> n >> m;
    vector<ll> res = csl::dnc(bas, mul, n, func);
    ll ans = 0;
//    rep(i, 0u, res.size()) cout << i << " " << res[i] << endl; cout << endl;
    rep(i, (unsigned)max(m - 3 * n, 0), res.size()) ans = (ans + res[i]) % mod;
    cout << ans << '\n';
  }
  return 0;
}
