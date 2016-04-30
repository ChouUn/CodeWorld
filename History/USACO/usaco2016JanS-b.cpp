//@ Including Header
#include <csl_std.h>

/**
 *  Name : usaco2016JanS-b.cpp
 *  Date : 2016年1月18日 下午9:37:31
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ifstream in("div7.in");
  ofstream out("div7.out");

  int n; in >> n;
  vi v(n); rep(i, 0, n) in >> v[i];
  vector<ll> u(n+1); u[0] = 0;
  rep(i, 0, n) u[i+1] = u[i] + v[i];

  vi p(7, -1), q(7, -1);
  rrep(i, 0, n+1) p[u[i]%7] = i;
  rep(i, 0, n+1) q[u[i]%7] = i;

  int ans = 0;
  rep(i, 0, 7) if(~p[i]) ans = max(ans, q[i] - p[i]);
  out << ans << endl;
  return 0;
}
