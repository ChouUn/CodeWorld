//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6444.cpp
 *  Date : 2016年7月13日 上午12:40:36
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int n; ll m;
ll a[N], s[N];

ll check(ll x) {
  ll y = (x + 1) * x / 2;
  int k = upper_bound(a, a + n, x) - a;
  if (k) y -= s[k - 1];
  return y;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> n >> m;
    rep(i, 0, n) cin >> a[i];

    sort(a, a + n);
    rep(i, 0, n) s[i] = (i ? s[i - 1] + a[i] : a[i]);

    int l = 0, r = 1e9;
    while (l < r) {
      int mid = (l + r) / 2 + 1;
      if (check(mid) <= m) l = mid;
      else r = mid - 1;
    }

    int k = upper_bound(a, a + n, l) - a;
    cout << l - k << endl;
  }
  return 0;
}
