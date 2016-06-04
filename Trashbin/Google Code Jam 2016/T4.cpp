//@ Including Header
#include <csl_std.h>

/**
 *  Name : T4.cpp
 *  Date : 2016年5月28日 下午11:38:08
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 30;
int n, g[N][N], h[N], f[N];
int ans;

bool check(int x) {
  if (x == n) return true;
  int cnt = 0;
  rep(i, 0, n) if (!h[i] && g[f[x]][i]) {
    ++cnt;
    h[i] = 1;
    if (!check(x + 1)) return false;
    h[i] = 0;
  }
  return cnt;
}

void dfs(int x, int y, int z) {
  if (z >= ans) return;
  if (y == n) ++x, y = 0;
  if (x == n) {
    memset(h, 0x00, sizeof h);
    bool flag = 1;
    rep(i, 0, n) f[i] = i;
    do {
      if (!check(0)) {
        flag = 0;
        break;
      }
    } while (next_permutation(f, f + n));
    if (flag) {
      ans = z;
//      rep(i, 0, n) {
//        rep(j, 0, n) cout << g[i][j]; cout << endl;
//      }
    }
    return;
  }
  dfs(x, y + 1, z);
  if (!g[x][y]) {
    g[x][y] = 1;
    dfs(x, y + 1, z + 1);
    g[x][y] = 0;
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    cin >> n;
    rep(i, 0, n) rep(j, 0, n) {
      char ch; cin >> ch;
      g[i][j] = (ch == '1');
    }

    ans = n * n;
    dfs(0, 0, 0);
    std::cout << "Case #" << __ << ": ";
    cout << ans << endl;
  }
  return 0;
}
