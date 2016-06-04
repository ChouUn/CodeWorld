//@ Including Header
#include <csl_std.h>

/**
 *  Name : L2-3.cpp
 *  Date : 2016年6月4日 下午1:30:33
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100;
queue<int> q;
int n, a[N], b[N];
int x[N], y[N];

int dfs(int l, int r) {
  if (l >= r) return 0;
  int u = q.front(); q.pop();

  auto lam = [](int u) -> int {
    rep(i, 1, n + 1) if (b[i] == u) return i;
    return 0;
  };
  int t = lam(u);
  x[u] = dfs(l, t);
  y[u] = dfs(t + 1, r);
  return u;
}

void bfs(int r) {
  queue<int> q; q.push(r);
  int flag = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (y[u]) q.push(y[u]);
    if (x[u]) q.push(x[u]);
    if (flag) cout << " "; flag = 1; cout << u;
  }
  cout << endl;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  rep(i, 1, n + 1) cin >> b[i];
  rep(i, 1, n + 1) {
    int x; cin >> x;
    q.push(x);
  }

  int r = q.front();
  dfs(1, n + 1);
  bfs(r);

  return 0;
}
