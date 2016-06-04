//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5495.cpp
 *  Date : 2015年10月5日 下午6:24:11
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 100010
int a[N], b[N];
int c[N], d[N];
bool v[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, n) c[a[i]] = i, d[b[i]] = i, v[i] = true;
    int ans = n;
    rep(i, 0, n) if(v[i]) {
      v[i] = false;
      int e = a[i], f = b[i], g = 1;
      while(f != e) v[c[f]] = false, f = b[c[f]], ++g;
      ans -= (g != 1);
    }
    cout << ans << endl;
  }
  return 0;
}
