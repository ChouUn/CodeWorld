//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6373.cpp
 *  Date : 2016年7月10日 上午9:28:37
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

int x, y, k, b;
int f[40][40];

int solve(int x) {
  vi v; while (x) v.push_back(x % b), x /= b;
  int k = ::k, ans = 0;
  per(i, 0, (int)v.size()) {
    if (v[i] > 1) return ans += f[i + 1][k];
    else if (v[i] > 0) ans += f[i][k], --k;
    if (k <= 0) break;
  }
  return ans += !k;
}

//@ Main Function
int main() {
  rep(i, 0, 40) f[i][0] = 1;
  rep(i, 0, 40) rep(j, 1, i + 1) f[i][j] = f[i - 1][j - 1] + f[i - 1][j];

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> x >> y >> k >> b;
    cout << solve(y) - solve(x - 1) << endl;
  }
  return 0;
}
