//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf675a.cpp
 *  Date : 2016年5月17日 上午12:36:43
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll a, b, c; cin >> a >> b >> c;
  if (!c) {
    cout << (a == b ? "YES\n" : "NO\n");
    return 0;
  }
  ll d = b - a;
  if (d / c < 0 || d % c) cout << "NO\n";
  else cout << "YES\n";
  return 0;
}
