//@ Including Header
#include <csl_std.h>

/**
 *  Name : test.cpp
 *  Date : 2016年7月11日 上午8:59:52
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

double ans;
void dfs(int x, int y, int p, int q, double s) {
  if (x == 0 && y == 0) {
    if (p != -1 && q != -1 && p == q) ans += s;
  }
  else if (x != 0 && y != 0) {
    dfs(x - 1, y, q, 0, s / 2);
    dfs(x, y - 1, q, 1, s / 2);
  }
  else if (x != 0) dfs(x - 1, y, q, 0, s);
  else if (y != 0) dfs(x, y - 1, q, 1, s);
  else assert(false);
}

const int N = 50010;
double f[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  rep(j, 1, N)
  rep(i, 2, N) {

  }

  rep(i, 1, 10) {
    rep(j, 1, 10) {
      ans = 0, dfs(i, j, -1, -1, 1.);
      cout << fixed << setprecision(9) << ans << " ";
    }
    cout << endl;
  }
  return 0;
}
