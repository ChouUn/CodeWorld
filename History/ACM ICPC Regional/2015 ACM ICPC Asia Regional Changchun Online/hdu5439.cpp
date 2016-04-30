//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/*
 *  Name : hdu5439.cpp
 *  Date : 2015年9月13日 下午8:34:38
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxm 1000000000
#define maxn 500010
#define mod 1000000007
ll f[maxn];

//@ Main Function
int main() {
  vector<int> v;
  v.push_back(0), v.push_back(1), v.push_back(3);
  for(int i = 3, s = 3, cur = 2; s < maxm; ++i) {
    if(i > v[cur]) ++cur;
    v.push_back(s += cur);
  }
  ll half = csl::pow(1ll, 2ll, mod-2, (ll)mod);
  rep(i, 1, (int)v.size()) {
    ll tmp = ll(v[i] - v[i-1]) * (v[i] + v[i-1] + 1) % mod * half % mod;
    f[i] = (f[i-1] + tmp * i) % mod;
  }

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int n; cin >> n;
    int p = lower_bound(v.begin(), v.end(), n) - v.begin();
    ll tmp = ll(n - v[p-1]) * (n + v[p-1] + 1) % mod * half % mod;
    ll ans = (f[p-1] + tmp * p) % mod;
    cout << ans << endl;
  }
  return 0;
}
