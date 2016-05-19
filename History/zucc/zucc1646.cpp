//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1646.cpp
 *  Date : 2016年5月17日 下午9:26:24
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 510;

#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <algorithm>

namespace zkw_cost {
  const int V = N * N * 2;
  const int E = V * 4;
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


int n, m, a[N][N];

inline int sl(int x, int y) { return x * m + y; }
inline int in(int x) { return x * 2; }
inline int out(int x) { return x * 2 + 1; }

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];

    zkw_cost::clear();
    int S = in(sl(0, 0)), T = out(sl(n - 1, m - 1));
    rep(i, 0, n) rep(j, 0, m) zkw_cost::add_couple_edge(in(sl(i, j)), out(sl(i, j)), 0, 1);
    rep(i, 0, n) rep(j, 0, m - 1) zkw_cost::add_couple_edge(out(sl(i, j)), in(sl(i, j + 1)), -a[i][j], 1);
    rep(i, 0, n - 1) rep(j, 0, m) zkw_cost::add_couple_edge(out(sl(i, j)), in(sl(i + 1, j)), -a[i][j], 1);
    zkw_cost::add_couple_edge(S, out(sl(0, 0)), 0, 1);
    zkw_cost::add_couple_edge(in(sl(n - 1, m - 1)), T, 0, 1);
    zkw_cost::solve(S, T, T + 1);
    cout << -zkw_cost::cost - a[0][0] + a[n - 1][m - 1] << endl;
  }
  return 0;
}
