//@ Including Header
#include <csl_std.h>
#include <manacher.h>

/**
 *  Name : hdu3068.cpp
 *  Date : 2015年11月28日 下午5:52:43
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 110000
char s[maxn];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(; ~scanf("%s", s); --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    csl::manacher<char> m;
    m.build(s);
    printf("%d\n", m.query());
  }
  return 0;
}
