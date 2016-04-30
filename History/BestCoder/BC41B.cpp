/*
 *	Name : BC41B.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月18日 下午7:54:20
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <iostream>
#include <set>
//@ Using Namespace
using namespace std;
//@ Program Begin

template <typename _Tp> inline _Tp gcd(_Tp a, _Tp b)
{ while (b) { _Tp t = a % b; a = b; b = t; } return a; }

//@ Main Function
int main() {
  int _; cin >> _;
  while (_--) {
    int n; cin >> n;
    multiset<string> m[2];
    int sum = 0;
    int ans = n * (n - 1) / 2;
    while (n--) {
      string s; cin >> s;
      int v = s.size() % 2;
      int u = v ^ 1;
      sum += m[u].size();
      sum += m[v].count(s);
      m[v].insert(s);
    }
    int tmp = gcd(sum, ans);
    cout << sum / tmp << '/' << ans / tmp << endl;
  }
  return 0;
}
