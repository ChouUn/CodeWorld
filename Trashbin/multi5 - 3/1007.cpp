//@ Including Header
#include <csl_std.h>

/**
 *  Name : 1007.cpp
 *  Date : 2016年7月26日 下午1:04:40
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100000;
#define st first
#define nd second

vector<int> g[N];
pii f[N][3], h[3];

void deal10(pii a, pii b) {
  h[1] = min(h[1], pii(b.st + a.st, b.nd + a.nd + 1));
}

void deal11(pii a, pii b) {
  h[0] = min(h[0], pii(b.st + a.st + 1, b.nd + a.nd + 1));
  h[2] = min(h[2], pii(b.st + a.st, b.nd + a.nd + 1));
}

void deal12(pii a, pii b) {
  h[1] = min(h[1], pii(b.st + a.st + 1, b.nd + a.nd + 1));
}

void deal20(pii a, pii b) {
  h[2] = min(h[2], pii(b.st + a.st, b.nd + a.nd + 2));
}

void deal21(pii a, pii b) {
  h[1] = min(h[1], pii(b.st + a.st + 1, b.nd + a.nd + 2));
}

void deal22(pii a, pii b) {
  h[0] = min(h[0], pii(b.st + a.st + 2, b.nd + a.nd + 2));
  h[2] = min(h[2], pii(b.st + a.st + 1, b.nd + a.nd + 2));
}

void dfs(int u, int fa) {
  rep(i, 0, 3) f[u][i] = pii(0, 0);
  for (auto v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    rep(i, 0, 3) h[i] = pii(N, N);
    deal10(f[v][1], f[u][0]);
    deal11(f[v][1], f[u][1]);
    deal12(f[v][1], f[u][2]);
    deal20(f[v][2], f[u][0]);
    deal21(f[v][2], f[u][1]);
    deal22(f[v][2], f[u][2]);
    rep(i, 0, 3) f[u][i] = h[i];
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 1, n + 1) g[i].clear();
    rep(i, 1, n) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    dfs(1, 0);
    cout << f[1][0].nd << endl;
  }
  return 0;
}
