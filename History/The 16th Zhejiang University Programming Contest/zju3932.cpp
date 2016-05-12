//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju3932.cpp
 *  Date : 2016年4月12日 下午11:09:49
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
	  int n; cin >> n;
	  vi a(n); rep(i, 0, n) cin >> a[i];

	  int sum = 0, ans = 0;
	  per(i, 0, n) {
	    ans = max(ans, sum + a[i]);
	    sum += a[i] > 0;
	  }
	  cout << ans << endl;
  }
  return 0;
}
