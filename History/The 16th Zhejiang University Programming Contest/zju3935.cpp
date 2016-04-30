//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju3935.cpp
 *  Date : 2016年4月16日 下午8:33:08
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define M 1000000
int f[M];

//@ Main Function
int main() {
  rep(i, 0, M) if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) ++f[i];
  for (int i = 1; i * (i + 1) / 2 < M; ++i) ++f[i * (i + 1) / 2];
  for (int i = 1; i * (2 * i - 1) < M; ++i) ++f[i * (2 * i - 1)];
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  rep(i, 2016, M) if (f[i] == 3) cout << i << '\n';
  return 0;
}
