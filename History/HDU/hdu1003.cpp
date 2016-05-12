//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1003.cpp
 *  Date : 2016年5月9日 下午9:06:26
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int s[N] = {0};

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    if (__ != 1) cout << "\n";
    std::cout << "Case " << __ << ":\n";
    int n; cin >> n;
    rep(i, 1, n + 1) {
      int x; cin >> x;
      s[i] = s[i - 1] + x;
    }
    int m = n; pii ans(n - 1, n);
    per(i, 0, n) {
      if (s[ans.second] - s[ans.first] <= s[m] - s[i]) ans = make_pair(i, m);
      if (s[i] > s[m]) m = i;
    }
    cout << s[ans.second] - s[ans.first] << " " << ans.first + 1 << " " << ans.second << endl;
  }
  return 0;
}
