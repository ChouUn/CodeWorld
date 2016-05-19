/*
 *	Name : ZUCC1583.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月27日 下午8:09:45
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <iostream>
//@ Using Namespace
using namespace std;
//@ Program Begin

//@ Main Function
int main() {
  int _; cin >> _;
  while (_--) {
    int n; cin >> n;
    cout << (((n * n + 3) * n + 12) * n + 8) * n * n / 24 << endl;
  }
  return 0;
}
