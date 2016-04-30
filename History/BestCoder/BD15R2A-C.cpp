/*
 *	Name : BD15R2A-C.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月30日 下午1:55:41
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <csl_std.h>
//@ Using Namespace
//using namespace std;
//@ Program Begin

#define maxN 100010
#define maxM 1000010

int n;
int a[maxN];

bool check(int x) {
  int p = -maxM;
  for (int i = 0; i < n; i++) {
    int q = std::max(p + 1, a[i] - x);
    if (q > a[i] + x) return false;
    p = q;
  }
  return true;
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  for (int T = 1; T <= _; T++) {
    printf("Case #%d:\n", T);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", a + i);

    int left = 0, right = maxM;
    while (left < right) {
      int mid = (left + right) >> 1;
      if (check(mid))
        right = mid;
      else
        left = mid + 1;
    }
    printf("%d\n", left);
  }
  return 0;
}
