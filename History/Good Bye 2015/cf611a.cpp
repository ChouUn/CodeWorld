//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf611a.cpp
 *  Date : 2015年12月30日 下午11:06:30
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

int f[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int x; cin >> x;
  string s; cin >> s >> s;

  int z = 4, ans = 0;
  rep(i, 1, 13) rep(j, 1, f[i]+1)
    ans += (s == "week") ? ((z = z % 7 + 1) == x) : (j == x);
  cout << ans << endl;

  return 0;
}
