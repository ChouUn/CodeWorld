//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju3933.cpp
 *  Date : 2016年4月16日 下午8:02:16
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 510;

namespace zkw_cost {
  const int V = 2 * ::N;
  const int E = 2 * V * V;
  const int oo = INT_MAX / 2;

  struct edge {
    edge *next, *pair;
    int cost, rest, from, to;
  };

  edge e[E], *head[V]; bool v[V];
  int en, S, T, cost, p;

  void clear() {
    memset(head, 0x00, sizeof head);
    en = 0;
  }

  edge* add_edge(int from, int to, int cost, int rest) {
    edge* res = e + en++;
    res->from = from, res->to = to, res->cost = cost, res->rest = rest;
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
        int d = aug(i->to, std::min(mi, i->rest));
        i->rest -= d, i->pair->rest += d, mi -= d;
        if (!mi) break;
      }
    return ma - mi;
  }

  bool relabel(int n) {
    static int d[V]; std::fill_n(d, n, oo); d[T] = 0;
    static std::deque<int> Q; Q.push_back(T);
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
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    int s = n, t = n + 1;
    zkw_cost::clear();
    rep(i, 0, n)
      if (s1[i] == '0') zkw_cost::add_couple_edge(s, i, s2[i] - '1', 1);
      else zkw_cost::add_couple_edge(i, t, s2[i] - '1', 1);
    rep(i, 0, n) {
      vector<bool> v(n, true); v[i] = false;
      int m; cin >> m;
      while (m--) { int x; cin >> x; v[x-1] = false; }
      rep(j, 0, n) if (s1[i] == '0' && s1[j] == '1' && v[j])
        zkw_cost::add_couple_edge(i, j, 0, 1);
    }
    zkw_cost::solve(s, t, n + 2);

    vpii ans;
    rep(i, 0, zkw_cost::en) {
      auto e = zkw_cost::e[i];
      if (e.from != s && e.to != t && s1[e.from] == '0' && s1[e.to] == '1' && e.rest == 0)
        ans.push_back(make_pair(e.from+1, e.to+1));
    }
    cout << ans.size() << " " << -zkw_cost::cost << '\n';
    for (auto& p : ans) cout << p.first << " " << p.second << '\n';
  }
  return 0;
}
