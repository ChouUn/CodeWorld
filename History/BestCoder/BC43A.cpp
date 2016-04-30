/*
 *	Name : BC43A.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年6月8日 下午12:46:34
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <csl_std.h>
//@ Using Namespace
//using namespace std;
//@ The magic ends here.

//@ Main Function
#define maxn 110
char s[maxn];
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n/2; i++) putchar(s[i*2]); puts("");
    for (int i = 0; i < n/2; i++) putchar(s[n-1-i*2]); puts("");
  }
  return 0;
}
