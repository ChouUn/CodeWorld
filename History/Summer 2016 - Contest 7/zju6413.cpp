//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6413.cpp
 *  Date : 2016年7月12日 上午8:57:55
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

char g[1024][2049];

void dfs(int x, int y, int z) {
  if (z == 0) return;
  int p = x + (1 << z), q = y - 1;
  rep(i, 0, 1 << z) p -= 1, q += 1, g[p][q] = '/';
  p -= 1;
  rep(i, 0, 1 << z) p += 1, q += 1, g[p][q] = '\\';
  rep(i, 2, 1 << (z + 1)) q -= 1, g[p][q] = '_';
  dfs(x, y + (1 << (z - 1)), z - 1);
  dfs(x + (1 << (z - 1)), y, z - 1);
  dfs(x + (1 << (z - 1)), y + (1 << z), z - 1);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int x; cin >> x;
    rep(i, 0, 1 << x) memset(g[i], 0x20, sizeof g[i]);
    dfs(0, 0, x);
    rep(i, 0, 1 << x) g[i][1 << (x + 1)] = 0, cout << g[i] << endl;
  }
  return 0;
}
