//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf674b.cpp
 *  Date : 2016年5月7日 下午11:31:55
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k; cin >> n >> k;
  int a, b, c, d; cin >> a >> b >> c >> d;

  if (n == 4 || k < n + 1) {
    cout << -1 << endl;
    return 0;
  }

  set<int> s;
  rep(i, 0, n) s.insert(i + 1);
  s.erase(a), s.erase(b);
  s.erase(c), s.erase(d);

  cout << a << " " << c << " ";
  for (auto si : s) cout << si << " ";
  cout << d << " " << b << endl;
  cout << c << " " << a << " ";
  for (auto si : s) cout << si << " ";
  cout << b << " " << d << endl;
  return 0;
}
