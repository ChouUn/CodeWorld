//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf674a.cpp
 *  Date : 2016年5月7日 下午10:43:55
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 5010
int a[N], b[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; cin >> n;
  rep(i, 0, n) cin >> a[i], ++b[a[i]];

  map<int,int> ans;
  rep(i, 0, n) {
    int ma = i;
    memset(b, 0x00, sizeof b);
    rep(j, i, n) {
      ++b[a[j]];
      if (b[a[j]] > b[ma] || (b[a[j]] == b[ma] && a[j] < ma)) ma = a[j];
      ++ans[ma];
    }
  }
  rep(i, 1, n) cout << ans[i] << " "; cout << ans[n] << endl;
  return 0;
}
