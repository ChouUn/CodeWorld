//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1278.cpp
 *  Date : 2016年3月9日 下午8:21:10
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 110
int f[N];

void build(const char* s, int n) {
  f[0] = -1;
  rep(i, 1, n) {
    int j = f[i-1];
    while (~j && s[j+1] != s[i]) j = f[j];
    f[i] = (s[j+1] == s[i]) ? j + 1 : j;
  }
}

int solve(const char* s, int n, const char *t, int m) {
  int res = 0, j = -1;
  rep(i, 0, m) {
    while (~j && s[j+1] != t[i]) j = f[j];
    j += (s[j+1] == t[i]), res += (j == n-1);
  }
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(string a, b; cin >> a >> b; --_, ++__) {
    build(b.data(), b.size());
    int ans = solve(b.data(), b.size(), a.data(), a.size());
    cout << ans << endl;
  }
  return 0;
}
