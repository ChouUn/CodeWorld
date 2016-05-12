//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1643.cpp
 *  Date : 2016年5月5日 下午9:49:29
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

int dis(int a, int b, int c, int d) {
  return (c - a) * (c - a) + (d - b) * (d - b);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    int m = 2 * n + 1;
    rep(i, 0, m) {
      rep(j, 0, m) {
        printf("%c", (dis(i, j, n, n) <= n * n) ? '*' : '.');
      }
      printf("\n");
    }
  }
  return 0;
}
