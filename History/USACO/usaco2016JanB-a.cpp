//@ Including Header
#include <csl_std.h>

/**
 *  Name : usaco2016JanB-a.cpp
 *  Date : 2016年1月18日 下午8:05:55
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ifstream in("promote.in");
  ofstream out("promote.out");

  int a[8]; rep(i, 0, 8) in >> a[i];
  int z = a[7] - a[6];
  int y = a[5] - (a[4] - z);
  int x = a[3] - (a[2] - y);
  out << x << endl;
  out << y << endl;
  out << z << endl;
  return 0;
}
