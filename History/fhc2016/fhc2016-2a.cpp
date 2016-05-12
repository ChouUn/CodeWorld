//@ Including Header
#include <csl_std.h>

/**
 *  Name : fhc2016-2a.cpp
 *  Date : 2016年1月17日 上午8:51:31
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

int solve(deque<int>& d) {
  int res = 0;
  int x = d.front(); d.pop_front();
  rep(i, 0, 3) {
    if(d.empty()) ++res;
    else if(x >= d.front()) ++res;
    else {
      x = min(x + 10, d.front());
      if(x == d.front()) d.pop_front();
      else ++res;
    }
  }
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    int n; cin >> n;
    deque<int> d;
    rep(i, 0, n) {
      int x; cin >> x;
      d.push_back(x);
    }
    int ans = 0;
    while(!d.empty()) ans += solve(d);
    std::cout << "Case #" << __ << ": " << ans << endl;
  }
  return 0;
}
