//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf675d.cpp
 *  Date : 2016年5月17日 上午1:48:51
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; cin >> n;
  int x; cin >> x;

  map<int, int> m;
  m[x] = 1;

  rep(i, 1, n) {
    cin >> x;
    auto l = m.lower_bound(x);
    if (l == m.end()) {
      --l;
      cout << l->first;
      m[x] = l->second + 1;
    }
    else if (l == m.begin()) {
      cout << l->first;
      m[x] = l->second + 1;
    }
    else {
      auto r = l--;
      if (l->second < r->second) l = r;
      cout << l->first;
      m[x] = l->second + 1;
    }
    cout << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
