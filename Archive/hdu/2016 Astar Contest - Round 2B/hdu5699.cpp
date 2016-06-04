//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5699.cpp
 *  Date : 2016年5月24日 上午10:41:50
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 1000000;
int p, n, x[N], y[N];

bool check(int m) {
  int ma1 = -1e9, mi1 = 1e9, ma2 = -1e9, mi2 = 1e9;
  rep(i, 0, n) {
    if (y[i] - x[i] <= m) continue;
    ma1 = max(ma1, x[i] + y[i] - m);
    mi1 = min(mi1, x[i] + y[i] + m);
    ma2 = max(ma2, x[i] - y[i] - m);
    mi2 = min(mi2, x[i] - y[i] + m);
  }
  return ma1 <= mi1 && ma2 <= mi2;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(; cin >> p >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, n) cin >> x[i] >> y[i];
    rep(i, 0, n) if (x[i] > y[i]) swap(x[i], y[i]);

    int l = 0, r = p;
    while (l < r) {
      int m = (l + r) / 2;
      if (check(m)) r = m; else l = m + 1;
    }
    cout << l << endl;
  }
  return 0;
}
