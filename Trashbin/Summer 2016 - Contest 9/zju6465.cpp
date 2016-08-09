//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6465.cpp
 *  Date : 2016年7月15日 上午1:15:27
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 2510 * 2;
int k, n, a[N];

bool g[N];

bool check1(int q, int l) {
  int r = 2 * n - 1;
  memset(g, 0x00, sizeof g);
  while (true) {
    while (r >= 0 && g[r]) --r;
    if (r >= 0) g[r] = true; else break;
    while (l >= 0 && (g[l] || a[r] % a[l] || a[r] / a[l] != q)) --l;
    if (l >= 0) g[l] = true; else break;
//    cout << l << " " << r << endl;
  }
  rep(i, 0, 2 * n) if (!g[i]) return false;
  return true;
}

bool check2(int q, int l) {
  int r = 2 * n - 1;
  memset(g, 0x00, sizeof g);
  while (true) {
    while (r >= 0 && g[r]) --r;
    if (r >= 0) g[r] = true; else break;
    while (l >= 0 && (g[l] || a[r] - a[l] != q)) --l;
    if (l >= 0) g[l] = true; else break;
//    cout << l << " " << r << endl;
  }
  rep(i, 0, 2 * n) if (!g[i]) return false;
  return true;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> k >> n;
    rep(i, 0, 2 * n) cin >> a[i];
    sort(a, a + 2 * n);
    if (k == 1) {
      int ans = 1e9;
      per(i, 0, 2 * n - 1) {
        int r = a[2 * n - 1];
        int l = a[i];
        if (r % l) continue;
        if (!check1(r / l, i)) continue;
//        cout << l << " " << r << " " << i << endl;
        ans = r / l; break;
      }
      cout << ans << endl;
    }
    else {
      int ans = 1e9;
      per(i, 0, 2 * n - 1) {
        int r = a[2 * n - 1];
        int l = a[i];
//        cout << l << " " << r << " " << i << endl;
        if (!check2(r - l, i)) continue;
        ans = r - l; break;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
