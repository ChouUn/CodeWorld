//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1010.cpp
 *  Date : 2015年11月26日 下午9:03:35
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 1010
char s[maxn], t[maxn];
int m;

int cmp(char a, char b) {
  return a == b ? 0 : a < b ? -1 : 1;
}

//@ Main Function
int main(){
  int _, __ = 1;
  for(; ~scanf("%s%d", s, &m) && m != -1; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int n = strlen(s), tn, p, r;
    if (s[0] == '-')
      p = 1, r = 1, m = n - m - 1, t[0] = '-', tn = 1;
    else
      p = 0, r = -1, m = n - m, tn = 0;
    for(int q = n - m + 1; m; --m) {
      int k = p;
      rep(i, p+1, q) if (cmp(s[i], s[k]) == r) k = i;
      t[tn++] = s[k], p = k + 1, q = q + 1;
    }
    for(t[tn] = 0, tn = 0; t[tn] && t[tn] == '0'; ++tn);
    puts(t[tn] ? t + tn : "0");
  }
  return 0;
}
