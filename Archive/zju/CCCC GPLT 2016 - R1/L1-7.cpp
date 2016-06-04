//@ Including Header
#include <csl_std.h>

/**
 *  Name : L1-7.cpp
 *  Date : 2016年6月4日 下午2:20:54
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  string s; cin >> s;
  vi a(32);
  for (auto c : s) ++a[c & 0x1f];
  char b[5] = "GPLT";
  while (true) {
    int flag = 0;
    for (auto bi : b) {
      auto c = bi & 0x1f;
      if (a[c]) cout << bi, --a[c], flag = 1;
    }
    if (!flag) break;
  }
  cout << endl;
  return 0;
}
