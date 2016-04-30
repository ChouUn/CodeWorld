//@ Including Header
#include <csl_std.h>
#include <csl_math.h>
#include <modint.h>
#include <fenwick.h>

/**
 *  Name : zju3929.cpp
 *  Date : 2016年4月12日 上午12:49:56
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef csl::ModInt<> mint;
typedef csl::fenwick_tree<mint> bit;
#define N 100010
mint fac[N];

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, N) fac[i] = fac[i-1] * 2;

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    bit f; f.build(N);

    mint ans = 0;
    rep(i, 0, n) {
      int x; cin >> x;
      if (i == 0) { f.update(x, 2); continue; }

      mint y = f.query(x - 1);
      mint z = f.query(N) - f.query(x);
      f.update(x, fac[i]);
      ans += (y + z) * fac[n - i - 1];
    }
    cout << ans << '\n';
  }
  return 0;
}
