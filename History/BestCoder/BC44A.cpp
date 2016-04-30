/*
 *	Name : BC44A.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年6月14日 上午9:58:45
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <csl_std.h>
//@ Using Namespace
//using namespace std;
//@ The magic ends here.

//@ Main Function
int main() {
  int _, __ = 0;
  for (scanf("%d", &_); _; _--) {
    printf("Case #%d: ", ++__);
    int sum = 0;
    for (int i = 0; i < 4; i++) {
      int x, y; scanf("%d%d", &x, &y);
      sum += std::max((4+2*i) * (250-x) - y*50, (4+2*i) * 100);
    }
    printf("%d\n", sum);
  }
  return 0;
}
