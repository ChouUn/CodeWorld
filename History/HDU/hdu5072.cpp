//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>

/**
 *  Name : hdu5072.cpp
 *  Date : 2016年4月1日 上午7:45:50
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 100010
const vector<std::size_t> &v = csl::prime::div;
int a[N], b[N], p[N];

int split(int q) {
  int res = 0;
  while (q != 1) {
    int qi = v[q];
    while (q % qi == 0) q /= qi;
    p[res++] = qi;
  }
  return res;
}

//@ Main Function
int main() {
  csl::prime::build(N+1);

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    memset(b, 0x00, sizeof b);
    rep(i, 0, n) {
      int m = split(a[i]);
      rep(j, 0, 1 << m) {
        int fac = 1;
        rep(k, 0, m) if (j & (1 << k)) fac *= p[k];
        ++b[fac];
      }
    }

    ll ans = (ll)n * (n-1) / 2 * (n-2) / 3, cnt = 0;
    rep(i, 0, n) {
      int m = split(a[i]); ll tmp = 0;
      rep(j, 0, 1 << m) {
        int fac = 1, cnt = 0;
        rep(k, 0, m) if (j & (1 << k)) fac *= p[k], ++cnt;
        tmp += (cnt & 1 ? -1 : 1) * b[fac];
      }
      cnt += a[i] == 1 ? 0 : tmp * (n - 1 - tmp);
    }
    cout << ans - cnt / 2 << endl;
  }
  return 0;
}
