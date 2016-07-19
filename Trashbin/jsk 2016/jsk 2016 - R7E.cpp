//@ Including Header
#include <csl_std.h>
#include <BigDec.h>

/**
 *  Name : jsk 2016 - R7E.cpp
 *  Date : 2016年7月3日 下午1:32:14
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  csl::BigDec<csl::array< std::uint32_t, 10000> > n;
  cin >> n;

  if (n % 3 != 0) {
    cout << -1 << endl;
    return 0;
  }

  auto m = n / 3;
  cout << m << " " << m << " " << m << endl;

  return 0;
}
