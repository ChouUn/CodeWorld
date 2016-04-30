//@ Including Header
#include <csl_std.h>
#include <csl_math.h>
#include <modint.h>
#include <matrix.h>

/**
 *  Name : zucc1605.cpp
 *  Date : 2015年12月3日 下午7:23:15
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

ll n, k; int l; ll mod;
typedef csl::modint<ll,mod> mint;
typedef csl::matrix<mint> mat;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(; cin >> n >> k >> l >> mod; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    if(k>>(l>>1)>>(l-(l>>1))) { cout << 0 << endl; continue; }
    if(mod == 1) { cout << 0 << endl; continue; }

    mat base(1,2), tran(2,2);
    base[0][0] = base[0][1] = 1;
    tran[0][0] = tran[0][1] = tran[1][0] = 1, tran[1][1] = 0;
    mat temp = csl::pow(base, tran, n - 1);
    mint p = temp[0][0] + temp[0][1], q = pow(mint(1), mint(2), n) - p;
    mint ans = mint(1);
    rep(i, 0, l) ans *= (k >> i & 1) ? q : p;
    cout << ans << endl;
  }
  return 0;
}
