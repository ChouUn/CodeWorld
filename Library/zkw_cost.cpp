#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <algorithm>

namespace zkw_cost {
  const int V;
  const int E;
  const int oo = INT_MAX / 2;

  struct edge {
    edge *next, *pair;
    int cost, rest, to;
  };

  edge e[E], *head[V]; bool vis[V];
  int en, S, T, cost, p;

  inline void clear() {
    memset(head, 0x00, sizeof head), en = 0;
  }

  inline edge* add_edge(int from, int to, int cost, int rest) {
    edge* res = e + en++;
    res->to = to, res->cost = cost, res->rest = rest;
    return res->next = head[from], head[from] = res, res;
  }

  inline void add_couple_edge(int from, int to, int cost, int rest) {
    edge* x = add_edge(from, to, +cost, rest);
    edge* y = add_edge(to, from, -cost, 0);
    x->pair = y, y->pair = x;
  }

  int aug(int u, int ma) {
    if (u == T) return cost += p * ma, ma;
    vis[u] = true; int mi = ma;
    for (edge* i = head[u]; i; i = i->next)
      if (i->rest && !i->cost && !vis[i->to]) {
        int d = aug(i->to, std::min(mi, i->rest));
        i->rest -= d, i->pair->rest += d, mi -= d;
        if (!mi) break;
      }
    return ma - mi;
  }

  bool relabel(int n) {
    static int d[V]; std::fill_n(d, n, oo); d[T] = 0;
    std::deque<int> Q; Q.push_back(T);
    while(!Q.empty()) {
      int dt, u = Q.front(); Q.pop_front();
      for(edge* i = head[u]; i; i = i->next)
        if(i->pair->rest && (dt = d[u] - i->cost) < d[i->to])
          ((d[i->to] = dt) <= d[Q.size() ? Q.front() : S]) ?
          Q.push_front(i->to) : Q.push_back(i->to);
    }
    for(int u = 0; u < n; ++u)
      for(edge* i = head[u]; i; i = i->next) i->cost += d[i->to] - d[u];
    return p += d[S], d[S] < oo;
  }

  void solve(int s, int t, int n) {
    S = s, T = t, cost = 0, p = 0;
    while(relabel(n)) do memset(vis, 0x00, sizeof vis); while(aug(S, oo));
  }
}
