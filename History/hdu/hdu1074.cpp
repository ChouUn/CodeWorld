//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1074.cpp
 *  Date : 2016年5月13日 上午2:02:35
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 16;
string s[N];
int d[N], c[N];
pair<int,string> f[1<<N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n, m = 1 << n;
    rep(i, 0, n) cin >> s[i] >> d[i] >> c[i];

    f[0] = make_pair(0, "");
    rep(u, 1, m) {
      int cnt = 0;
      rep(k, 0, n) if (u & (1 << k)) cnt += c[k];
      f[u].first = INT_MAX / 2;
      rep(k, 0, n) {
        int v = u ^ (1 << k);
        if (v > u) continue;
        pair<int,string> t = make_pair(f[v].first + max(cnt - d[k], 0),
          f[v].second + s[k] + '\n');
        f[u] = min(f[u], t);
      }
    }
    cout << f[m - 1].first << '\n' << f[m - 1].second;
  }
  return 0;
}
