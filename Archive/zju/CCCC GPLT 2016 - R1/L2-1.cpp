//@ Including Header
#include <csl_std.h>

/**
 *  Name : L2-1.cpp
 *  Date : 2016年6月4日 下午1:12:57
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

struct node {
  int a, b, c;
};
const int N = 10010;
node p[N];
//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; cin >> n;
  rep(u, 1, n + 1) p[u].c = u;
  rep(u, 1, n + 1) {
    int k; cin >> k;
    rep(i, 0, k) {
      int v, w; cin >> v >> w;
      p[u].a -= w;
      p[v].a += w;
      p[v].b += 1;
    }
  }
  sort(p + 1, p + n + 1, [](const node& a, const node& b) -> bool {
    if (a.a != b.a) return a.a > b.a;
    else if (a.b != b.b) return a.b > b.b;
    else return a.c < b.c;
  });
  rep(u, 1, n + 1) cout << p[u].c << " " << fixed << setprecision(2) << p[u].a / 100. << endl;
  return 0;
}
