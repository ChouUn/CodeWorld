//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>

/**
 *  Name : cf671b.cpp
 *  Date : 2016年5月12日 上午11:23:45
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 500010;
ll c[N], d[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; ll k; cin >> n >> k;
  rep(i, 0, n) cin >> c[i];
  ll sum = accumulate(c + 1, c + n, c[0], std::plus<ll>());
  ll cma = accumulate(c + 1, c + n, c[0], csl::max<ll>());
  ll cmi = accumulate(c + 1, c + n, c[0], csl::min<ll>());

  int mil = cmi, mir = sum / n;
  while (mil < mir) {
    int mim = (mil + mir + 1) / 2;
    ll cnt = accumulate(c, c + n, 0ll, [mim](ll a, ll b) -> ll {
      return a + max(mim - b, 0ll);
    });
    if (cnt > k) mir = mim - 1; else mil = mim;
  }

  int mal = sum / n + !!(sum % n), mar = cma;
  while (mal < mar) {
    int mam = (mal + mar) / 2;
    ll cnt = accumulate(c, c + n, 0ll, [mam](ll a, ll b) -> ll {
      return a + max(b - mam, 0ll);
    });
    if (cnt > k) mal = mam + 1; else mar = mam;
  }

  cout << mal - mil << endl;
  return 0;
}
