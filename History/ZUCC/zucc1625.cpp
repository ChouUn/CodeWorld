//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1625.cpp
 *  Date : 2016年3月31日 下午4:53:57
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 155
#define M 55
#define P 1000000007
char s[N];
int p[N][3], f[N][M][M][M];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n >> s;

    memset(p, 0x00, sizeof p);
    rep(k, 0, 3) p[n][k] = n;
    per(i, 0, n) {
      rep(k, 0, 3) p[i][k] = p[i+1][k];
      p[i][s[i]-'a'] = i;
    }

    memset(f, 0x00, sizeof f);
    f[0][0][0][0] = 1;
    int m = n / 3 + 3, ans = 0;
    rep(i, 0, n) rep(a, 0, m) rep(b, 0, m) rep(c, 0, m) {
//      if (a + b + c > n) break;
      if (a + b + c == n && abs(a - b) <= 1 && abs(b - c) <= 1 && abs(c - a) <= 1) {
        (ans += f[i][a][b][c]) %= P;
        continue;
      }
      if (p[i][0] < n) (f[p[i][0]][a+1][b][c] += f[i][a][b][c]) %= P;
      if (p[i][1] < n) (f[p[i][1]][a][b+1][c] += f[i][a][b][c]) %= P;
      if (p[i][2] < n) (f[p[i][2]][a][b][c+1] += f[i][a][b][c]) %= P;
    }
    cout << ans << endl;
  }
  return 0;
}
