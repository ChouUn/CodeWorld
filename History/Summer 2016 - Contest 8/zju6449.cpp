//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>

/**
 *  Name : zju6449.cpp
 *  Date : 2016年7月13日 上午1:02:13
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 1010;
int g[5][N], a[N], f[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m; cin >> n >> m && n && m; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, m) rep(j, 0, n) cin >> a[j], g[i][a[j]] = j;
    rep(i, 0, n) {
      f[i] = 1;
      rep(j, 0, i) {
        bool flag = true;
        rep(k, 0, m) if (g[k][a[j]] > g[k][a[i]]) flag = false;
        if (flag) f[i] = max(f[i], f[j] + 1);
      }
    }
//    rep(i, 0, n) cout << f[i] << endl;
    cout << *max_element(f, f + n) << endl;
  }
  return 0;
}
