/*
 *	Name : BC43B.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年6月8日 下午12:58:56
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#define USING_CONTAINER
#include <csl_std.h>;
//@ Using Namespace
//using namespace std;
//@ The magic ends here.

//@ Main Function
int main() {
  for (int n; scanf("%d", &n) != EOF; ) {
    int64 m; scanf(i64, &m);
    std::set<int64> s;
    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      int64 x; scanf(i64, &x); x %= m;
      std::set<int64>::iterator p = s.lower_bound(m - x); if (p != s.end()) p--;
      if (i) ans = std::max(ans, ((p == s.end() ? *s.rbegin() : *p) + x) % m);
      s.insert(x);
    }
    printf(i64 "\n", ans);
  }
  return 0;
}
