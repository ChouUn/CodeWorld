//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6416.cpp
 *  Date : 2016年7月12日 上午11:10:34
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 1010;
const int M = 110;
const int K = 1010;

int g[M][M];
bool f[K];

bool check(int x, int y) {
  if (x && y) return x != y;
  if (!x && !y) return true;
  if (!x || !y) return false;
  assert(false);
  return true;
}

int solve(int x, int y) {
  if (!x || !y || x == y) return 0;

  memset(f, 0x00, sizeof f);
  rep(i, 1, max(x, y) + 1) {
    if (x >= i && check(x - i, y)) f[g[x - i][y]] = true;
    if (y >= i && check(x, y - i)) f[g[x][y - i]] = true;
    if (x >= i && y >= i && check(x - i, y - i)) f[g[x - i][y - i]] = true;
  }

  rep(i, 0, K) if (!f[i]) return i;
  return -1;
}

pii p[N];

//@ Main Function
int main() {
  rep(i, 0, M) rep(j, 0, M) g[i][j] = solve(i, j);
  rep(i, 0, M) rep(j, 0, M) if (g[i][j] == -1) assert(false);
//  for (int i = 1; i <= 99; ++i) printf("%d%c", g[99][i], i%20?' ':'\n');

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> p[i].first >> p[i].second;

    bool flag = false;
    rep(i, 0, n) if (!check(p[i].first, p[i].second)) flag = true;
    if (flag) { cout << "HuaJi" << endl; continue; }

    int ans = 0;
    rep(i, 0, n) ans ^= g[p[i].first][p[i].second];
    cout << (ans ? "HuaJi" : "NaoTou") << endl;
  }
  return 0;
}
