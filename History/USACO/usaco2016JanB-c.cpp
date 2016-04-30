//@ Including Header
#include <csl_std.h>

/**
 *  Name : usaco2016JanB-c.cpp
 *  Date : 2016年1月18日 下午8:43:11
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ifstream in("mowing.in");
  ofstream out("mowing.out");

  int n; in >> n;
  map<pii,int> s;
  int ans = ~0U >> 1, t = 0;
  pii p; s[p] = t;
  while(n--) {
    char ch; int m; in >> ch >> m;
    while(m--) {
      ++t;
      switch(ch) {
        case 'N': --p.first; break;
        case 'S': ++p.first; break;
        case 'W': --p.second; break;
        case 'E': ++p.second; break;
      }
      auto q = s.find(p);
      if(q != s.end()) ans = min(ans, t - q->second);
      s[p] = t;
    }
  }
  out << (ans == (~0U >> 1) ? -1 : ans) << endl;
  return 0;
}
