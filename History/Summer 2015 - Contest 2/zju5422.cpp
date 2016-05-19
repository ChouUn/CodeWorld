//@ Including Header
#include <csl_std.h>
#include <csl_math.h>
#include <ModInt.h>

typedef csl::ModInt<> mint;

/**
 *  Name : zju5422.cpp
 *  Date : 2016年3月13日 下午1:16:26
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  mint::M = 1000000007;
  const mint one = 1, two = 2;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, k; cin >> n >> k; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    mint p = csl::pow(one, two, k);
    mint ans = csl::pow(one, (p - one), n) + (n & 1 ? one : p - one);
    cout << ans << endl;
  }
  return 0;
}
