//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf611e.cpp
 *  Date : 2015年12月31日 上午10:54:43
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; cin >> n;
  int a, b, c; cin >> a >> b >> c;
  if(a < b) swap(a, b);
  if(a < c) swap(a, c);
  if(b < c) swap(b, c);

  multiset< int, greater<int> > s;
  rep(i, 0, n) { int x; cin >> x; s.insert(x); }

  if(*s.begin() > a + b + c) { cout << -1 << endl; return 0; }
  int ans = 0;
  while(!s.empty()) {
    int x = *s.begin(); s.erase(s.begin());
    if(x > a + b) {} // a, b, c
    else if(x > a + c) { auto y = s.lower_bound(c); if(y != s.end()) s.erase(y); } // a, b
    else if(x > b + c && x > a) { auto y = s.lower_bound(b); if(y != s.end()) s.erase(y); } // a, c
    else if(x > a) { auto y = s.lower_bound(a); if(y != s.end()) s.erase(y); } // b, c
    else {
      auto y = s.lower_bound(b); if(y != s.end()) s.erase(y);
      auto z = s.lower_bound(c); if(z != s.end()) s.erase(z);
      if(y == s.end() && z == s.end()) { y = s.lower_bound(b+c); if(y != s.end()) s.erase(y); }
    } // a
    ++ans;
  }
  cout << ans << endl;
  return 0;
}
