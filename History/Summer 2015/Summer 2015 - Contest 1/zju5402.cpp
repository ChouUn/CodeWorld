//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju5402.cpp
 *  Date : 2015年12月29日 下午6:08:09
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  string s1 = "valar morghulis";
  string s2 = "valar dohaeris";
  for(string s; getline(cin, s); --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    cout << (s == s1 ? s2 : (s == s2) ? s1 : s) << endl;
  }
  return 0;
}
