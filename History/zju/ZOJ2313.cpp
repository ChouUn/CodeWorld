/*
 *	Name : zju2313.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��5��3�� ����7:07:39
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <csl_std.h>
#include <bigint.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

typedef csl::BigInt<300> bint;
//@ Main Function
int main() {
  int _; cin >> _;
  while (_--) {
    bint n; cin >> n;
    if (n % bint(2) == bint(1))
      cout << (n / 2) << endl;
    else if (n % bint(4) > bint(0))
      cout << (n / 2 - bint(2)) << endl;
    else
      cout << (n / 2 - bint(1)) << endl;
    if (_) cout << endl;
  }
  return 0;
}
