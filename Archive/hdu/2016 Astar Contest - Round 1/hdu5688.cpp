//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5688.cpp
 *  Date : 2016年5月22日 上午12:31:24
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    map<string, int> m;
    while (n--) {
      string s; cin >> s;
      sort(s.begin(), s.end());
      cout << m[s]++ << endl;
    }
  }
  return 0;
}
