/*
 *	Name : BC41A.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月18日 下午6:48:01
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <csl_std.h>
//@ Program Begin
using namespace std;

bool f[4][15];

//@ Main Function
int main() {
  int _; cin >> _;
  while (_--) {
    memset(f, 0x00, sizeof(f));
    for (int i = 0; i < 5; i++) {
      char c; int x; cin >> c >> x;
      f[c-'A'][x] = true;
      if (x == 1) f[c-'A'][14] = true;
    }
    int ans = 4;
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j < 11; j++) {
        int sum = 5;
        for (int k = 0; k < 5; k++)
          sum -= f[i][j+k];
        ans = min(ans, sum);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
