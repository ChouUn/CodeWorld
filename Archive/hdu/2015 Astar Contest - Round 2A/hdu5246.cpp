//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5246.cpp
 *  Date : 2015年8月4日 下午8:29:04
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 10010
ll a[maxn];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ <<": ";

    int n; ll m, k; cin >> n >> m >> k;
    rep(i, 0, n) cin >> a[i];
    sort(a, a+n);

    int idx = -1;
    rep(i, 0, n) if(a[i] > m) break; else idx = i;
    if (~idx) {
      for(int tmp = idx; k && idx != n-1; k--, idx = tmp) {
        rep(i, idx+1, n)
          if(a[i] > a[idx] + max(k, 0ll)) break;
          else tmp = i;
        if(tmp == idx) break;
      }
    }
    cout << (idx != n-1 ? "madan!" : "why am I so diao?") << '\n';
  }
  return 0;
}
