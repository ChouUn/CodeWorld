//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6393.cpp
 *  Date : 2016年7月11日 上午8:50:55
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int b[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    set<int> s;
    rep(i, 0, n) { int x; cin >> x; s.insert(x); }
    ll ans = 0;
    rep(i, 0, m) {
      int x; cin >> x;
      auto it = s.lower_bound(x);
      if (it == s.end()) ans = 1;
      else s.erase(it);
    }
    if (ans) {
      cout << "You Lost Xiao Hua~" << endl;
      continue;
    }
    for (auto si : s) ans += si;
    cout << ans % 100000003 << endl;
  }
  return 0;
}
