//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1640.cpp
 *  Date : 2016年5月4日 上午12:21:30
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 50010;
int l, n, m, a[N];

bool solve(int r) {
  int res = 0, l = 0;
  rep(i, 1, n+1)
    if (a[i] - a[l] < r) ++res;
    else l = i;
  return res <= m;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> l >> n >> m;
    rep(i, 1, n+1) cin >> a[i]; a[0] = 0, a[n+1] = l;

    int p = 0, q = l;
    while (p < q) {
      int r = (p + q + 1) / 2;
      if (solve(r)) p = r;
      else q = r - 1;
    }
    cout << p << endl;
  }
  return 0;
}
