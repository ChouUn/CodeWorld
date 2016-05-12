//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1644.cpp
 *  Date : 2016年5月5日 下午9:57:53
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#include <climits>
#include <cmath>
#include <cstring>
#include <algorithm>

const int N = 5010;
const int M = 50010;

namespace sap {
  const int V = N + M;
  const int E = (N + M * 3) * 2;
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

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    int S = 0, T = n + m + 1, ans = 0;
    sap::clear();
    rep(i, 1, n + 1) {
      int x; cin >> x;
      sap::add_couple_edge(i, T, x);
    }
    rep(i, n + 1, n + m + 1) {
      int x, y, z; cin >> x >> y >> z; ans += z;
      sap::add_couple_edge(S, i, z);
      sap::add_couple_edge(i, x, sap::oo);
      sap::add_couple_edge(i, y, sap::oo);
    }
    sap::solve(S, T, n + m + 2);
    cout << ans - sap::ans << endl;
  }
  return 0;
}
