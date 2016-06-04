//@ Including Header
#include <csl_std.h>

/**
 *  Name : L1-2.cpp
 *  Date : 2016年6月4日 下午1:49:26
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string s; cin >> s;
  if (s < "12:01") {
    cout << "Only " << s << ".  Too early to Dang.";
    return 0;
  }

  int t = (s[0] - '0') * 10 + (s[1] - '0') - 12;
  if (s[3] != '0' || s[4] != '0') ++t;
  while (t--) cout << "Dang"; cout << endl;
  return 0;
}
