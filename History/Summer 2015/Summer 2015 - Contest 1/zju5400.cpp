//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju5400.cpp
 *  Date : 2015年12月29日 下午3:06:26
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 110
#define maxm 60
double f[2][maxm*2][maxm];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int n, x, y; cin >> n >> x >> y;
    memset(f, 0x00, sizeof(f));
    f[0][x][y] = 1.;
    double ans = 0;
    rep(i, 0, n) {
      rep(j, max(0,x-i), min(x+i,x+y)+1) {
        rep(k, max(0,y-i), y+1) {
          int m = j + k + 1;
          double t = f[i&1][j][k] / m;
          f[i&1][j][k] = 0;
          f[(i&1)^1][j][k] += t * 1;
          ans += t * 1;
          if (j)
            f[(i&1)^1][j-1][k] += t * j;
          if (k)
            f[(i&1)^1][j][k-1] += t * k * 0.5,
            f[(i&1)^1][j+1][k-1] += t * k * 0.5;
        }
      }
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << ans * 1.5 << '\n';
  }
  return 0;
}
