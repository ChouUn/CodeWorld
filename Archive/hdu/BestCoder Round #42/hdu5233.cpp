//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5233.cpp
 *  Date : 2015年11月24日 上午1:02:46
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 100010
int lnk[maxn], tmp[maxn];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m; cin >> n >> m; --_, ++__) {
    map<int,int> p;
    rep(i, 1, n+1) cin >> tmp[i];
    per(i, 1, n+1) {
      int& ref = p[tmp[i]];
      lnk[i] = ref, ref = i;
    }
    while (m--) {
      int t; cin >> t;
      int& ref = p[t];
      if (!ref) { cout << -1 << '\n'; continue; }
      cout << ref << '\n';
      ref = lnk[ref];
    }
  }
  return 0;
}
