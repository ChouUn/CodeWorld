//@ Including Header
#include <csl_std.h>

/**
 *  Name : usaco2016JanB-b.cpp
 *  Date : 2016年1月18日 下午8:17:04
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

int solve(vi& v, int m) {
  int l = m, r = m, t, n = v.size();
  for(t = 0; l > 0 && v[l] - v[l-1] <= t; ++t, --l);
  for(t = 0; r < n-1 && v[r+1] - v[r] <= t; ++t, ++r);
  return r - l + 1;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ifstream in("angry.in");
  ofstream out("angry.out");

  int n; in >> n;
  vi v(n); rep(i, 0, n) in >> v[i];
  sort(v.begin(), v.end());
  int ans = 1;
  rep(i, 0, n) ans = max(ans, solve(v, i));
  out << ans << endl;
  return 0;
}
