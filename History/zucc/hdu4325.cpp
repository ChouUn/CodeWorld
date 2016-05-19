//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu4325.cpp
 *  Date : 2016年5月6日 下午2:22:42
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
int a[N], b[N], c[N];

typedef multimap<int,pii> node;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ":\n";
    int n, m; cin >> n >> m;
    rep(i, 0, n) cin >> a[i] >> b[i];
    rep(i, 0, m) cin >> c[i];

    node s;
    rep(i, 0, n) s.insert(make_pair(b[i] + 1, make_pair(1, i)));
    rep(i, 0, n) s.insert(make_pair(a[i], make_pair(2, i)));
    rep(i, 0, m) s.insert(make_pair(c[i], make_pair(3, i)));

    int ans = 0;
    while (!s.empty()) {
      int stamp = s.begin()->first;
      while (!s.empty() && s.begin()->first == stamp) {
        pii t = s.begin()->second;
        switch (t.first) {
          case 1: --ans; break;
          case 2: ++ans; break;
          case 3: c[t.second] = ans; break;
        }
        s.erase(s.begin());
      }
    }
    rep(i, 0, m) cout << c[i] << "\n";
  }
  return 0;
}
