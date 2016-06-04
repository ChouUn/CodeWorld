//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu2962.cpp
 *  Date : 2016年4月30日 下午1:26:55
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 1010;

#include <climits>
#include <cstring>
#include <algorithm>
#include <utility>
#include <ext/pb_ds/priority_queue.hpp>

namespace dijkstra {
  const int V = ::N;
  const int E = V * V * 2;
  const int oo = INT_MAX / 2;

  typedef std::pair<int,int> pii;
  const auto comp = [](const pii& a, const pii& b) -> bool {
    return a.second > b.second;
  };
  typedef __gnu_pbds::priority_queue<pii,decltype(comp)> container;

  struct edge {
    edge *next;
    int cost, to, lim;
  };

  edge e[E], *head[V]; bool vis[V];
  int en, S, T, dis[V];

  inline void clear() {
    memset(head, 0x00, sizeof head), en = 0;
  }

  inline edge* add_edge(int from, int to, int cost, int lim) {
    edge* res = e + en++;
    res->to = to, res->cost = cost, res->lim = lim;
    return res->next = head[from], head[from] = res, res;
  }

  inline void add_double_edge(int from, int to, int cost, int lim) {
    add_edge(from, to, cost, lim);
    add_edge(to, from, cost, lim);
  }

  void solve(int s, int t, int n, int m) {
    std::fill_n(dis, n, oo), std::fill_n(vis, n, false);
    S = s, T = t; dis[S] = 0;
    static container::point_iterator ptr[V]; container pq(comp);
    for (int i = 0; i < n; ++i) ptr[i] = pq.push(std::make_pair(i, dis[i]));

    while (!pq.empty()) {
      int u = pq.top().first, du = pq.top().second; pq.pop();
      dis[u] = du, vis[u] = true; if (u == T) return;
      for (edge* i = head[u]; i; i = i->next) {
        int v = i->to; if (vis[v] || i->lim < m) continue;
        int dv = du + i->cost;
        if (dv < ptr[v]->second) pq.modify(ptr[v], std::make_pair(v, dv));
      }
    }
  }

  inline void solve(int s, int n, int m) {
    solve(s, -1, n, m);
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m; cin >> n >> m && n; --_, ++__) {
    if (__ != 1) cout << '\n';
    std::cout << "Case " << __ << ":\n";
    dijkstra::clear();
    while (m--) {
      int u, v, w, c; cin >> u >> v >> w >> c;
      dijkstra::add_double_edge(u, v, c, w == -1 ? dijkstra::oo : w);
    }
    int S, T, M; cin >> S >> T >> M;
    ll l = 0, r = M;
    while (l < r) {
      int m = (l + r + 1) / 2;
      dijkstra::solve(S, T, n + 1, m);
      if (dijkstra::dis[T] == dijkstra::oo) r = m - 1;
      else l = m;
    }

    dijkstra::solve(S, T, n + 1, l);
    if (dijkstra::dis[T] == dijkstra::oo) { cout << "cannot reach destination\n"; continue; }
    cout << "maximum height = " << l << '\n';
    cout << "length of shortest route = " << dijkstra::dis[T] << '\n';
  }
  return 0;
}
