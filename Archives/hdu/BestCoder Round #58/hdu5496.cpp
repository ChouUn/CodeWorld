//@ Including Header
#include <csl_std.h>
#include <discrete.h>

/*
 *  Name : hdu5496.cpp
 *  Date : 2015年11月11日 下午11:41:19
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 100010
#define mod 1000000007
ll pow2[maxn];
int a[maxn], d[maxn];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    csl::discrete<int> b;
    b.insert(a, a+n);
    b.build();

    int m = b.size();
    memset(d, 0x00, sizeof(d[0]) * m);
    ll ans = 0, cnt = 1;
    rep(i, 0, n) {
      int p = b.query(a[i]);
      ll tmp = (cnt - d[p] + mod) % mod;
      cnt = (cnt + pow2[i]) % mod;
      d[p] = (d[p] + pow2[i]) % mod;
      ans = (ans + tmp * a[i] % mod * pow2[n-1-i] % mod) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}
