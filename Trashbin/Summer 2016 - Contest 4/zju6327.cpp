//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6327.cpp
 *  Date : 2016年7月8日 上午11:11:19
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int M = 40;
const int N = 100010;
int f[M], h[M], g[N];

//@ Main Function
int main() {
  f[0] = 1, f[1] = 2;
  rep(i, 2, M) f[i] = f[i - 1] + f[i - 2];
  g[0] = 0;
  rep(i, 1, N) {
    memset(h, 0x00, sizeof h);
    rep(j, 0, M) {
      int k = i - f[j];
      if (k >= 0) h[g[k]] = 1;
    }
    rep(j, 0, M) if (!h[j]) {
      g[i] = j; break;
    }
  }

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int a, b, c; cin >> a >> b >> c;
    cout << (g[a] ^ g[b] ^ g[c] ? "Alice" : "Bob") << endl;
  }
  return 0;
}
