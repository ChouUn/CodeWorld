//@ Including Header
#include <csl_std.h>

/**
 *  Name : 1009.cpp
 *  Date : 2016年7月28日 下午3:09:56
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 110;

#include <climits>
#include <cmath>
#include <cstring>
#include <algorithm>

namespace sap {
  const int V = ::N * ::N * 2;
  const int E = ::N * ::N * 10;
  const int oo = INT_MAX / 2;

  struct edge {
    edge *next, *pair;
    int rest, to;
  };

  edge e[E], *head[V], *copy[V];
  int en, S, T, N, h[V], g[V], ans;

  inline void clear() {
    memset(head, 0x00, sizeof head), en = 0;
  }

  inline edge* add_edge(int from, int to, int rest) {
    edge* res = e + en++;
    res->to = to, res->rest = rest;
    return res->next = head[from], head[from] = res, res;
  }

  inline void add_couple_edge(int from, int to, int rest) {
    edge* x = add_edge(from, to, rest);
    edge* y = add_edge(to, from, 0);
    x->pair = y, y->pair = x;
  }

  int aug(int u, int ma) {
    if (u == T) return ma;
    int mi = ma;
    for (edge*& i = head[u]; i; i = i->next)
      if (i->rest && h[i->to] + 1 == h[u]) {
        int d = aug(i->to, std::min(mi, i->rest));
        i->rest -= d, i->pair->rest += d, mi -= d;
        if (h[S] == N || !mi) return ma - mi;
      }
    return --g[h[u]] ? ++g[++h[u]] : h[S] = N, head[u] = copy[u], ma - mi;
  }

  void solve(int s, int t, int n) {
    S = s, T = t, N = n, ans = 0, std::copy(head, head + N, copy);
    std::fill(h, h + N, 0), std::fill(g, g + N + 1, 0), g[0] = N;
    while (h[S] < N) ans += aug(S, oo);
  }
}

int a[10], b[10], c[N], w[N][N];
int x[10], y[N], z[N][N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    string s; cin >> s;
    rep(i, 0, n) c[i] = s[i] - '0';
    rep(i, 0, 10) cin >> a[i] >> b[i];
    rep(i, 0, n) rep(j, 0, n) cin >> w[i][j];

    int S = 0, T = 1, id = 2;
    rep(i, 0, 10) x[i] = id++;
    rep(i, 0, n) y[i] = id++;
    rep(i, 0, n) rep(j, 0, n) z[i][j] = id++;

    int cnt = 0;
    sap::clear();
    rep(i, 0, 10) sap::add_couple_edge(S, x[i], b[i] - a[i]);
    rep(i, 0, n) sap::add_couple_edge(S, y[i], a[c[i]]);
    rep(i, 0, n) rep(j, 0, n) {
      if (i == j) continue;
      sap::add_couple_edge(x[c[i]], z[i][j], sap::oo);
      sap::add_couple_edge(x[c[j]], z[i][j], sap::oo);
      sap::add_couple_edge(y[i], z[i][j], sap::oo);
      sap::add_couple_edge(y[j], z[i][j], sap::oo);
      sap::add_couple_edge(z[i][j], T, w[i][j]);
      cnt += w[i][j];
    }
    sap::solve(S, T, id);
    cout << cnt - sap::ans << endl;
  }
  return 0;
}
