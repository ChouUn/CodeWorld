//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf675c.cpp
 *  Date : 2016年5月17日 上午2:06:07
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int a[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; cin >> n;
  rep(i, 1, n + 1) cin >> a[i];

  ll cnt = 0;
  map<ll,int> m;
  rep(i, 1, n + 1) {
    cnt += a[i];
    m[cnt]++;
  }
  int ans = n - 1;
  for (auto &mi : m) ans = min(ans, n - mi.second);
  cout << ans << endl;
  return 0;
}
