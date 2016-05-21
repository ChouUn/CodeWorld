//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5692.cpp
 *  Date : 2016年5月21日 下午6:31:48
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;

vector<int> g[N];
int w[N], s[N], t[N];
ll p[N * 2]; int pn;

void dfs(int u, ll& pi, int f) {
  p[++pn] = pi += w[u], s[u] = pn;
  for (auto v : g[u]) if (v != f) dfs(v, pi, u);
  p[++pn] = pi -= w[u], t[u] = pn;
}

namespace seg {
  struct node {
    ll cnt;
    ll lzy;
  };
  node f[N << 3];

  inline int ls(int id) { return id * 2; }
  inline int rs(int id) { return id * 2 + 1; }

  inline void pushdown(int id) {
    if (f[id].lzy) {
      f[ls(id)].cnt += f[id].lzy;
      f[ls(id)].lzy += f[id].lzy;
      f[rs(id)].cnt += f[id].lzy;
      f[rs(id)].lzy += f[id].lzy;
      f[id].lzy = 0;
    }
  }

  inline void pushup(int id) {
    f[id].cnt = max(f[ls(id)].cnt, f[rs(id)].cnt);
  }

  void build(int id, int l, int r) {
    if (l == r) {
      f[id].cnt = p[l];
      f[id].lzy = 0;
      return;
    }
    int m = (l + r) >> 1;
    build(ls(id), l, m);
    build(rs(id), m + 1, r);
    pushup(id);
    f[id].lzy = 0;
  }

  inline ll query(int id, int l, int r, const int& p, const int& q) {
    if (p <= l && r <= q) return f[id].cnt;
    int m = (l + r) >> 1;
    ll res = -1e12;
    pushdown(id);
    if (p <= m) res = max(res, query(ls(id), l, m, p, q));
    if (q > m) res = max(res, query(rs(id), m + 1, r, p, q));
    return res;
  }

  void update(int id, int l, int r, const int& p, const int& q, int d) {
    if (p <= l && r <= q) {
      f[id].cnt += d;
      f[id].lzy += d;
      return;
    }
    int m = (l + r) >> 1;
    pushdown(id);
    if (p <= m) update(ls(id), l, m, p, q, d);
    if (q > m) update(rs(id), m + 1, r, p, q, d);
    pushup(id);
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ":\n";
    int n, m; cin >> n >> m;
    rep(i, 0, n) g[i].clear();
    rep(i, 1, n) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    rep(i, 0, n) cin >> w[i];

    ll cnt = 0;
    pn = 0, dfs(0, cnt, -1), --pn;
    seg::build(1, 1, pn);
    while (m--) {
      int op; cin >> op;
      if (op == 0) {
        int x, y; cin >> x >> y;
        int d = y - w[x]; w[x] = y;
        seg::update(1, 1, pn, s[x], t[x] - 1, d);
      }
      else {
        int x; cin >> x;
        cout << seg::query(1, 1, pn, s[x], t[x] - 1) << endl;
      }
    }
  }
  return 0;
}
