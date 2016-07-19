//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6490.cpp
 *  Date : 2016年7月17日 上午7:48:47
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 510;

namespace sap {
  const int V = ::N * 5 * 2;
  const int E = 1000010;
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

int in[5][N], out[5][N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m, k, h; cin >> n >> m >> k >> h;

    int S = 0, T = 1, cnt = 2;
    rep(l, 0, k) rep(i, 1, m + 1) in[l][i] = cnt++, out[l][i] = cnt++;

    sap::clear();
    rep(l, 0, k) rep(i, 1, m + 1) sap::add_couple_edge(in[l][i], out[l][i], 1);

    rep(u, 1, m + 1) {
      int p; cin >> p;
      while (p--) {
        int v; cin >> v;
        rep(l, 0, k - 1) sap::add_couple_edge(out[l][u], in[l + 1][v], 1);
        rep(l, 0, k) sap::add_couple_edge(out[l][u], in[l][v], 1);
      }
    }
    rep(i, 0, n) {
      int x; cin >> x;
      sap::add_couple_edge(S, in[0][x], 1);
    }
    rep(i, 0, h) {
      int x; cin >> x;
      rep(l, 0, k) sap::add_couple_edge(out[l][x], T, 1);
    }
    sap::solve(S, T, cnt);
    cout << sap::ans << endl;
  }
  return 0;
}
