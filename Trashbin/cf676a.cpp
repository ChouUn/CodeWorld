//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf676a.cpp
 *  Date : 2016年5月25日 下午11:02:29
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 110;
int a[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; cin >> n;
  rep(i, 0, n) cin >> a[i];

  int ans = 1;
  rep(i, 0, n) rep(j, 0, n) {
    if (i == j) continue;
    swap(a[i], a[j]);
    ans = max(ans, abs(max_element(a, a + n) - min_element(a, a + n)));
    swap(a[i], a[j]);
  }
  cout << ans << endl;
  return 0;
}
