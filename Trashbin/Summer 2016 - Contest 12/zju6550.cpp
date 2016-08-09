//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6550.cpp
 *  Date : 2016年7月19日 上午8:42:27
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int f[N], g[N], h[N], hn = 0;

//@ Main Function
int main() {
  while (true) {
    int t = (hn + 1) * (hn + 2) / 2;
    if (t < N) h[hn++] = t; else break;
  }
  f[0] = 0, g[0] = 0;
  fill(f + 1, f + N, N);
  rep(i, 1, N) {
    rep(j, 0, hn) {
      int d = h[j];
      if (d > i) break;
      int k = i - d;
      if (f[k] + 1 < f[i]) {
        f[i] = f[k] + 1;
        g[i] = max(g[k], d);
      }
      else if (f[k] + 1 == f[i]) {
        g[i] = max(g[i], max(g[k], d));
      }
    }
  }

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    cout << f[n] << " " << g[n] << endl;
  }
  return 0;
}
