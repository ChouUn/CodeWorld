//@ Including Header
#include <csl_std.h>

/*
 *  Name : zoj2006.cpp
 *  Date : 2015年9月17日 上午11:47:07
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

template <typename _Tp, typename _Comp >
std::size_t isomorph_min(_Tp* data, std::size_t size, _Comp comp)
{
  std::size_t i = 0, j = 1;
  for (std::size_t k; i < size && j < size;)
  {
    for (k = 0; data[i+k] == data[j+k] && k < size; ++k);
    if (k == size) return i;
    if (!comp(data[i+k], data[j+k])) std::swap(i, j);
    j = std::max(j + k + 1, i + 1);
  }
  return i;
}

#define maxn 10010
char s[maxn], t[maxn*2];
//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    scanf("%s", s);
    int n = strlen(s);
    rep(i, 0, n) t[i] = t[n+i] = s[i]; t[2*n] = 0;
    int x = isomorph_min(t, n, std::less<char>());
    printf("%d\n", x + 1);
  }
  return 0;
}
