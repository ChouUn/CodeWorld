//@ Including Header
#include <csl_std.h>

/**
 *  Name : 1001.cpp
 *  Date : 2016年7月26日 下午12:09:46
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(string s; cin >> s; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    if (s.size() > 10) { cout << "TAT" << endl; continue; }

    stringstream ss(s); ll x; ss >> x;
    if (x == 0) cout << "TAT" << endl;
    else if (x < 2) cout << 0 << endl;
    else if (x < 4) cout << 1 << endl;
    else if (x < 16) cout << 2 << endl;
    else if (x < 256) cout << 3 << endl;
    else if (x < 65536) cout << 4 << endl;
    else if (x < 4294967296) cout << 5 << endl;
    else cout << "TAT" << endl;
  }
  return 0;
}
