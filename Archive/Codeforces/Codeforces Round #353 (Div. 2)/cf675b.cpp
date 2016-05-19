//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf675b.cpp
 *  Date : 2016年5月17日 上午12:43:49
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
  vi v;
  v.push_back(a + b);
  v.push_back(a + c);
  v.push_back(d + b);
  v.push_back(d + c);
  sort(v.begin(), v.end());
  ll p = n - (v.back() - v.front());
  cout << max(p, 0ll) * n << endl;
  return 0;
}
