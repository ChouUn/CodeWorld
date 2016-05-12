//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu3530.cpp
 *  Date : 2016年5月10日 下午12:49:32
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int a[N];

inline int check(multiset<int>& s) {
  return *s.rbegin() - *s.begin();
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, p, q; cin >> n >> p >> q; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, n) cin >> a[i];

    multiset<int> s;
    int l = 0, r = 0, ans = 0;
    while (l < n) {
      if (r < l) s.erase(s.find(a[r++]));
      while (l < n && (s.empty() || check(s) < p)) s.insert(a[l++]);
      do {
        if (p <= check(s) && check(s) <= q) ans = max(ans, (int)s.size());
        if (l < n) s.insert(a[l++]); else break;
      } while (check(s) <= q);
    }
    cout << ans << endl;
  }
  return 0;
}
