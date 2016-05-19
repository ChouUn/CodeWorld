//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1401.cpp
 *  Date : 2015年12月7日 下午6:25:25
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 10010
int a[maxn];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; std::cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    rep(i, 0, n) {
      int x, y;
      cin >> x >> y;
      a[i] = x - y;
    }

    bool flag = false;
    rep(i, 0, n) {
      if(a[i] < 0) {
        flag = true;
        break;
      }
    }
    if(flag) {
      cout << "NO" << endl;
      continue;
    }

    int sum = 0;
    rep(i, 0, n) sum += a[i];
    if(sum & 1) {
      cout << "NO" << endl;
      continue;
    }
    sum /= 2;
    flag = true;
    rep(i, 0, n) if(a[i] > sum) flag = false;
    cout << (flag ? "YES" : "NO") << '\n';
  }
  return 0;
}
