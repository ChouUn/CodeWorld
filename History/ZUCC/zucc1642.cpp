//@ Including Header
#include <csl_std.h>
#include <csl_math.h>
#include <ModInt.h>
#include <matrix.h>

/**
 *  Name : zucc1642.cpp
 *  Date : 2016年5月4日 上午12:49:58
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef csl::ModInt<> mint;
typedef csl::matrix<mint> mat;

//@ Main Function
int main() {
  mint::M = 1000000007;
  const mint one = 1, two = 2;

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, k; cin >> n >> k;
    if (k == 1) { cout << 2 << endl; continue; }
    mint m = csl::pow(one, two, k);

    mat base(1, 3);
    base[0][0] = m, base[0][1] = 0, base[0][2] = 0;

    mat tran(3, 3);
    tran[0][0] = 1, tran[0][1] = m - 2, tran[0][2] = 0;
    tran[1][0] = 1, tran[1][1] = m - 3, tran[1][2] = 1;
    tran[2][0] = 0, tran[2][1] = m - 2, tran[2][2] = 1;

    mat ans = csl::pow(base, tran, n - 1);
    cout << ans[0][0] + ans[0][1] << endl;
  }
  return 0;
}
