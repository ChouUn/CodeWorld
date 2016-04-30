/*
 *	Name : ZUCC1575.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月26日 下午7:38:10
 *	Copyright : www.fateud.com
 *	Description :
 *	  http://oeis.org/A039907
 */

//@ Including Header
#include <iostream>
//@ Using Namespace
using namespace std;
//@ Program Begin

int f[] = {1, 0, 0, 2, 6, 0, 0, 2196, 37004, 0, 0};

//@ Main Function
int main() {
  int _; cin >> _;
  while (_--) {
    int n; cin >> n;
    cout << f[n] << endl;
  }
  return 0;
}
