//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju3938.cpp
 *  Date : 2016年4月24日 下午3:19:37
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int ans[6][2];
    rep(k, 1, 6) {
      int op, a[5], b[5]; cin >> op;
      rep(i, 1, 5) cin >> a[i], b[a[i]] = i;
      if (k == 1) {
        switch(op) {
          case 1: ans[k][0] = 2; break;
          case 2: ans[k][0] = 2; break;
          case 3: ans[k][0] = 3; break;
          case 4: ans[k][0] = 4; break;
        }
      }
      if (k == 2) {
        switch(op) {
          case 1: ans[k][0] = b[4]; break;
          case 2: ans[k][0] = ans[1][0]; break;
          case 3: ans[k][0] = 1; break;
          case 4: ans[k][0] = ans[1][0]; break;
        }
      }
      if (k == 3) {
        switch(op) {
          case 1: ans[k][0] = b[ans[2][1]]; break;
          case 2: ans[k][0] = b[ans[1][1]]; break;
          case 3: ans[k][0] = 3; break;
          case 4: ans[k][0] = b[4]; break;
        }
      }
      if (k == 4) {
        switch(op) {
          case 1: ans[k][0] = ans[1][0]; break;
          case 2: ans[k][0] = 1; break;
          case 3: ans[k][0] = ans[2][0]; break;
          case 4: ans[k][0] = ans[2][0]; break;
        }
      }
      if (k == 5) {
        switch(op) {
          case 1: ans[k][0] = b[ans[1][1]]; break;
          case 2: ans[k][0] = b[ans[2][1]]; break;
          case 3: ans[k][0] = b[ans[4][1]]; break;
          case 4: ans[k][0] = b[ans[3][1]]; break;
        }
      }
      ans[k][1] = a[ans[k][0]];
    }
    rep(k, 1, 6) cout << ans[k][0] << " " << ans[k][1] << '\n';
  }
  return 0;
}
