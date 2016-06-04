//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf676b.cpp
 *  Date : 2016年5月25日 下午11:12:26
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 20;
int a[N][N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, t; cin >> n >> t;

  a[1][1] = 1;
  rep(i, 2, n + 1) rep(j, 1, i + 1) a[i][j] = a[i - 1][j - 1] + a[i - 1][j];

  int ans = 0;
  rep(i, 1, n + 1) {
    int cnt = accumulate(a[i] + 1, a[i] + i + 1, 0);
    if (t >= cnt) { ans += i, t -= cnt; continue; }
    rep(j, 1, i + 1) ans += (t * a[i][j] >= cnt);
  }
  cout << ans << endl;

  return 0;
}
