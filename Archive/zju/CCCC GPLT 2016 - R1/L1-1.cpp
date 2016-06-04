//@ Including Header
#include <csl_std.h>

/**
 *  Name : L1-1.cpp
 *  Date : 2016年6月4日 下午1:44:18
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  string s; cin >> s;
  int a = 0, b = 0, c = 0;
  for (auto ch : s) {
    if (ch == '-') a = 1;
    if (ch == '2') ++b;
    c = (ch ^ 1) & 1;
  }
  cout << fixed << setprecision(2) << b * 1. / (s.size() - a) * (a ? 1.5 : 1) * (c ? 2 : 1) * 100 << "%" << endl;
  return 0;
}
