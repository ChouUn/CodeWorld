//@ Including Header
#include <csl_std.h>

/**
 *  Name : L2-2.cpp
 *  Date : 2016年6月4日 下午1:21:57
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 110;
int n, m, k;
int g[N][N], vis[N];

void dfs(int u, int c) {
  vis[u] = c;
  rep(v, 1, n + 1) if (!vis[v] && g[u][v] == 1) dfs(v, c);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n >> m >> k;
  rep(i, 0, m) {
    int u, v, w; cin >> u >> v >> w;
    g[u][v] = g[v][u] = w;
  }
  int cnt = 0;
  rep(i, 1, n + 1) if (!vis[i]) dfs(i, ++cnt);
  while (k--) {
/*
 * 对每个查询输出一行结果：如果两位宾客之间是朋友，且没有敌对关系，则输出“No problem”；
 * 如果他们之间并不是朋友，但也不敌对，则输出“OK”；
 * 如果他们之间有敌对，然而也有共同的朋友，则输出“OK but...”；
 * 如果他们之间只有敌对关系，则输出“No way”。
 */
    int u, v; cin >> u >> v;
    if (vis[u] == vis[v] && g[u][v] != -1) cout << "No problem" << endl;
    if (vis[u] != vis[v] && g[u][v] != -1) cout << "OK" << endl;
    if (vis[u] == vis[v] && g[u][v] == -1) cout << "OK but..." << endl;
    if (vis[u] != vis[v] && g[u][v] == -1) cout << "No way" << endl;
  }
  return 0;
}
