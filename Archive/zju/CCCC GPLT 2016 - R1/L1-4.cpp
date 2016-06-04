//@ Including Header
#include <csl_std.h>

/**
 *  Name : L1-4.cpp
 *  Date : 2016年6月4日 下午2:06:05
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100000;
bool g[N], h[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; cin >> n;
  while (n--) {
    int k, x; cin >> k;
    if (k == 1) { cin >> x; continue; }
    rep(i, 0, k) cin >> x, g[x] = true;
  }

  int flag = 0;
  int m; cin >> m;
  rep(i, 0, m) {
    int x; cin >> x;
    if (!g[x] && !h[x]) {
      if (flag) cout << " "; flag = 1; h[x] = 1;
      cout.fill('0'), cout.width(5); cout << x;
    }
  }
  if (!flag) cout << "No one is handsome";
  cout << endl;

  return 0;
}
