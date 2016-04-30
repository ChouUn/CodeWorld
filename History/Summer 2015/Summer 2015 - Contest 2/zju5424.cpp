//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju5424.cpp
 *  Date : 2016年3月20日 下午3:42:53
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 21, M = 21;
int n, p;
char s[N][M], t[M];
int l[N];

bool judge(int L) {
  rep(i, 0, n) {
    rep(j, 0, l[i] - L + 1) {
      strncpy(t, s[i] + j, L), t[L] = 0;
      int cnt = 0;
      rep(k, 0, n) cnt += strstr(s[k], t) != NULL;
      if (cnt >= p) return true;
    }
  }
  return false;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> n >> p;
    rep(i, 0, n) cin >> s[i], l[i] = strlen(s[i]);

    int L = 0;
    rep(i, 0, n) L = max(L, l[i]);
    while (L && !judge(L)) --L;
    cout << L << endl;
  }
  return 0;
}
