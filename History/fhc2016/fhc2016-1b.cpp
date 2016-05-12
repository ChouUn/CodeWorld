//@ Including Header
#include <csl_std.h>

/**
 *  Name : fhc2016-1b.cpp
 *  Date : 2016年1月9日 上午11:38:46
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    int n, p; cin >> n >> p;
    vi v(n); rep(i, 0, n) cin >> v[i];
    ll cnt = 0, ans = 0;
    for(int i = 0, j = 0; i < n; ++i) {
      if(j == i) cnt += v[j++];
      while(j < n && cnt <= p) cnt += v[j++];
      ans += j - i - (cnt > p);
      cnt -= v[i];
    }
    std::cout << "Case #" << __ << ": " << ans << '\n';
  }
  return 0;
}
