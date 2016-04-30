//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5183.cpp
 *  Date : 2015年11月23日 下午7:13:35
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxN 1000010

ll s[maxN];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ <<": ";
    int n; ll k; cin >> n >> k;
    rep(i, 1, n+1) {
      ll in; cin >> in;
      s[i] = s[i-1] + (i&1 ? in : -in);
    }

    set<ll> ht;
    bool ans = false;
    rrep(i, 0, n+1) {
      ll x = s[i] + (i&1 ? -k : k);
      if(ht.count(x)) { ans = true; break; }
      ht.insert(s[i]);
    }
    cout << (ans ? "Yes." : "No.") << '\n';
  }
  return 0;
}
