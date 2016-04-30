//@ Including Header
#include "BigDec.h"
#include <csl_std.h>

typedef csl::BigDec<> bint;

/**
 *  Name : test.cpp
 *  Date : 2016年3月14日 下午10:01:38
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  cout << bint::Bit << " " << bint::Base << endl;
  bint a(0x987654321);
  bint b(0x1234567f);
  cout << a << " " << b << endl;
  cout << a + b << " " << a - b << endl;
  cout << a * b << endl;
  cout << a / b << " " << a % b << endl;
  return 0;
}
