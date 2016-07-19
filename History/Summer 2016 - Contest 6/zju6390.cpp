//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6390.cpp
 *  Date : 2016年7月11日 上午8:38:02
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int f[N];
int getf(int x) {
  return x == f[x] ? x : f[x] = getf(f[x]);
}
void merge(int x, int y) {
  x = getf(x), y = getf(y);
  if (x != y) f[y] = x;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    rep(i, 1, n + 1) f[i] = i;
    while (m--) {
      int x, y; cin >> x >> y;
      merge(x, y);
    }
    int ans = -1;
    rep(i, 1, n + 1) ans += f[i] == i;
    cout << ans << endl;
  }
  return 0;
}
