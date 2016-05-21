//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : hdu5685.cpp
 *  Date : 2016年5月21日 下午11:34:39
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const ll P = 9973;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int m; cin >> m; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    string s; cin >> s;
    int n = s.size();
    vector<ll> v(n + 1, 1);
    rep(i, 0, n) v[i + 1] = v[i] * (s[i] - 28 + P) % P;
    while (m--) {
      int l, r; cin >> l >> r;
      cout << v[r] * csl::inv(v[l - 1], P) % P << endl;
    }
  }
  return 0;
}
