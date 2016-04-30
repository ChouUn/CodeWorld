//@ Including Header
#include <csl_std.h>
#include <discrete.h>

/**
 *  Name : poj3680.cpp
 *  Date : 2016年4月16日 下午2:31:24
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 210;

namespace zkw_cost {
  const int N = 2 * ::N;
  const int M = 6 * ::N;
  const int oo = INT_MAX / 2;

  struct edge {
    edge *next, *pair;
    int cost, rest, to;
  };

  edge e[M], *head[N]; bool v[N];
  int en, S, T, cost, p;

  void clear() {
    memset(head, 0x00, sizeof head);
    en = 0;
  }

  edge* add_edge(int from, int to, int cost, int rest) {
    edge* res = e + en++;
    res->to = to, res->cost = cost, res->rest = rest;
    return res->next = head[from], head[from] = res, res;
  }

  void add_couple_edge(int from, int to, int cost, int rest) {
    edge* x = add_edge(from, to, +cost, rest);
    edge* y = add_edge(to, from, -cost, 0);
    x->pair = y, y->pair = x;
  }

  int aug(int u, int ma) {
    if (u == T) return cost += p * ma, ma;
    v[u] = true; int mi = ma;
    for (edge* i = head[u]; i; i = i->next)
      if (i->rest && !i->cost && !v[i->to]) {
        int d = aug(i->to, min(mi, i->rest));
        i->rest -= d, i->pair->rest += d, mi -= d;
        if (!mi) break;
      }
    return ma - mi;
  }

  bool relabel(int n) {
    static int d[N]; fill_n(d, n, oo); d[T] = 0;
    static deque<int> Q; Q.push_back(T);
    while(Q.size()) {
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
    while(relabel(n)) do memset(v, 0x00, sizeof v); while(aug(S, oo));
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, k; cin >> n >> k;
    vi u(n), v(n), w(n);
    rep(i, 0, n) cin >> u[i] >> v[i] >> w[i];

    csl::discrete<int> d; d.reserve(2 * n);
    d.insert(u.data(), u.data() + n);
    d.insert(v.data(), v.data() + n);
    d.build();
    rep(i, 0, n) u[i] = d.query(u[i]);
    rep(i, 0, n) v[i] = d.query(v[i]);

    int m = d.size(), s = m, t = m + 1;
    zkw_cost::clear();
    zkw_cost::add_couple_edge(s, 0, 0, k);
    zkw_cost::add_couple_edge(m - 1, t, 0, k);
    rep(i, 1, m) zkw_cost::add_couple_edge(i - 1, i, 0, k);
    rep(i, 0, n) zkw_cost::add_couple_edge(u[i], v[i], -w[i], 1);
    zkw_cost::solve(s, t, m + 2);
    cout << -zkw_cost::cost << endl;
  }
  return 0;
}
