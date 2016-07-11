//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6296.cpp
 *  Date : 2016年7月7日 上午9:00:59
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 300010;
const int M = 20;

struct node {
  int to;
  node* next;
};
node e[N * 2]; int en;
node* head[N];

void add_edge(int u, int v) {
  e[en].to = v;
  e[en].next = head[u];
  head[u] = e + en;
  ++en;
}

int a[N], d[N], h[N], o[N];
int g[N][M];

void dfs(int u, int f) {
  g[u][0] = f, d[u] = d[f] + 1;
  for (auto i = head[u]; i; i = i->next) {
    int v = i->to;
    if (v != f) dfs(v, u);
  }
}

int ddfs(int u, int f) {
  int res = h[u];
  for (auto i = head[u]; i; i = i->next) {
    int v = i->to;
    if (v != f) res += ddfs(v, u);
  }
  return o[u] += res, res;
}

int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  int d = ::d[x] - ::d[y];
  per(k, 0, M) if (d >= (1 << k)) d -= 1 << k, x = g[x][k];
  if (x == y) return x;
  per(k, 0, M) {
    int xx = g[x][k], yy = g[y][k];
    if (xx != yy) x = g[x][k], y = g[y][k];
  }
  return g[x][0];
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) memset(g[i], 0x00, sizeof g[i]);

    en = 0;
    memset(head, 0x00, sizeof head);
    rep(i, 1, n) {
      int u, v; cin >> u >> v;
      add_edge(u, v);
      add_edge(v, u);
    }

    memset(h, 0x00, sizeof h);
    memset(d, 0x00, sizeof d);
    memset(o, 0x00, sizeof o);
    d[n] = 1, dfs(n, n);
    rep(k, 1, M) rep(i, 0, n) g[i][k] = g[g[i][k - 1]][k - 1];
    rep(i, 2, n + 1) {
      int x = a[i - 1], y = a[i], z = lca(x, y);
      h[x] += 1, h[y] += 1, h[z] -= 2; ++o[z], --o[y];
    }

    ddfs(n, n), h[n] = 0;
    rep(i, 1, n + 1) cout << o[i] << endl; cout << endl;
  }
  return 0;
}
