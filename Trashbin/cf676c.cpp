//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf676c.cpp
 *  Date : 2016年5月25日 下午11:23:29
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
char s[N];

int check(int n, int k, char c) {
  int res = 0, l = 0, r = 0, p = 0;
  while (l < n) {
    while (r < n && (p < k || s[r] == c)) p += (s[r++] != c);
    res = max(res, r - l);
//    cout << l << r << endl;
    p -= (s[l++] != c);
  }
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k; cin >> n >> k >> s;
  cout << max(check(n, k, 'a'), check(n, k, 'b')) << endl;

  return 0;
}
