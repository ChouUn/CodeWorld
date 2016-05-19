//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju5404.cpp
 *  Date : 2016年3月12日 下午2:16:50
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 210
int f[N][N][2];
int ans[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;

    memset(f, 0x00, sizeof f);
    rep(i, 0, n) {
      char ch; cin >> ch;
      f[i][i][0] = (ch == 'B');
      f[i][i][1] = (ch == 'W');
    }
    for (int k = 2; k < n; k += 2) {
      rep(l, 0, n - k) {
        int r = l + k;
        for (int i = l; i < r; i += 2) {
          for (int j = i + 1; j < r; j += 2) {
            if ((f[l][i][0] && f[j+1][r][0]) || (f[l][i][1] && f[j+1][r][1])) {
              f[l][r][0] = max(f[l][r][0], f[i+1][j][0]);
              f[l][r][1] = max(f[l][r][1], f[i+1][j][1]);
            }
          }
        }
      }
    }

    rep(i, 0, n) {
      ans[i] = f[0][i][0] || f[0][i][1] ? i : 0;
      if (i) ans[i] = max(ans[i], ans[i-1]);
      rep(j, 0, i)
        if (f[j+1][i][0] || f[j+1][i][1])
          ans[i] = max(ans[i], ans[j] + (i - j - 1));
    }
    cout << ans[n-1] << endl;
  }
  return 0;
}
