//@ Including Header
#include <csl_std.h>
#include <csl_math.h>
#include <matrix.h>
#include <BigInt.h>

/**
 *  Name : zju6564.cpp
 *  Date : 2016年7月19日 上午9:04:35
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef csl::matrix<ull> mat;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m, k; cin >> n >> m >> k; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    if (!n && !m && !k) return 0;
    vector<ull> v(n); rep(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());

    ull ans1 = 0;
    rep(i, 0, n) ans1 += v[i];

    if (k == 1) {
      cout << ans1 << " " << ans1 << endl;
      continue;
    }
    if (n == 2 && k == 2 && v[0] == 0) {
      cout << ans1 << " " << ans1 << endl;
      continue;
    }

    mat tran(k + 1, k + 1);
    rep(i, 0, k - 1) tran[i + 1][i] = 1;
    rep(i, 0, k) tran[i][k - 1] = tran[i][k] = 1;
    tran[k][k] = 1;
//    cout << tran << endl;

    mat base(1, k + 1);
    rep(i, 0, k) base[0][i] = v[n - k + i];
    base[0][k] = ans1;
//    cout << base << endl;

    mat ans = csl::pow(base, tran, m);
//    cout << ans << endl;
    cout << ans1 << " " << ans[0][k] << endl;
  }
  return 0;
}
