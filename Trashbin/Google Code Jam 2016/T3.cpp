//@ Including Header
#include <csl_std.h>

/**
 *  Name : T3.cpp
 *  Date : 2016年5月29日 上午12:03:13
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 20;
const int p[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1 };
const int q[2][4] = { 3, 2, 1, 0, 1, 0, 3, 2 };
int n, m, g[N][N], f[N];
bool ans;

bool check() {
  rep(i, 0, n + 2) {
    rep(j, 0, m + 2) {
      if (g[i][j] <= 0) continue;
      int x = i, y = j, z;

      if (i == 0) z = 2;
      else if (i == n + 1) z = 0;
      else if (j == 0) z = 1;
      else z = 3;

      do {
        x = x + p[z][0];
        y = y + p[z][1];
        z = q[g[x][y] + 1][z];
      } while (g[x][y] <= 0);
//      cout << i << " " << j << " " << x << " " << y << endl;
      if (f[g[i][j]] != g[x][y]) return false;
    }
  }
  return true;
}

void dfs(int x, int y) {
  if (y > m) ++x, y = 1;
  if (x > n) {
    if (check()) ans = true;
    return;
  }

  g[x][y] = -1;
  dfs(x, y + 1);
  if (ans) return;
  g[x][y] = 0;
  dfs(x, y + 1);
  if (ans) return;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ":\n";
    cin >> n >> m;
    rep(i, 0, n + m) {
      int u, v; cin >> u >> v;
      f[u] = v; f[v] = u;
    }
    memset(g, 0x00, sizeof g);
    int cnt = 0;
    rep(i, 1, m + 1) g[0][i] = ++cnt;
    rep(j, 1, n + 1) g[j][m + 1] = ++cnt;
    per(i, 1, m + 1) g[n + 1][i] = ++cnt;
    per(j, 1, n + 1) g[j][0] = ++cnt;
//    rep(i, 0, n + 2) {
//      rep(j, 0, m + 2) cout << g[i][j];
//      cout << endl;
//    }
    ans = false;
    dfs(1, 1);
    if (!ans) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    rep(i, 1, n + 1) {
      rep(j, 1, m + 1) cout << (g[i][j] == 0 ? '/' : '\\');
      cout << endl;
    }
  }
  return 0;
}
