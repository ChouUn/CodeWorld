//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju5423.cpp
 *  Date : 2016年3月20日 下午3:23:02
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100000 + 10;
const int L = 10 + 1;
char s[N][L];
int f[L][26];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> s[i];

    int m = strlen(s[0]);
    memset(f, 0x00, sizeof f);
    rep(i, 0, n) rep(j, 0, m) ++f[j][s[i][j] - 'a'];

    int ans = INT_MAX;
    char *ss = s[0];
    rep(i, 0, n) {
      int res = 0;
      rep(j, 0, m) res += n - f[j][s[i][j] - 'a'];
      if (res < ans) ans = res, ss = s[i];
    }
    cout << ss << endl;
  }
  return 0;
}
