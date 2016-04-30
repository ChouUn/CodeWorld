//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu2112.cpp
 *  Date : 2016年4月30日 下午1:40:05
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 210;

#include <cstring>
#include <algorithm>
#include <utility>
#include <ext/pb_ds/priority_queue.hpp>

namespace dijstra {
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
    int cost, to;
  };

  edge e[E], *head[V]; bool vis[V];
  int en, S, T, dis[V];

  inline void clear() {
    memset(head, 0x00, sizeof head), en = 0;
  }

  inline edge* add_edge(int from, int to, int cost) {
    edge* res = e + en++;
    res->to = to, res->cost = cost;
    return res->next = head[from], head[from] = res, res;
  }

  inline void add_douple_edge(int from, int to, int cost) {
    add_edge(from, to, cost);
    add_edge(to, from, cost);
  }

  void solve(int s, int t, int n) {
    std::fill_n(dis, n, oo), std::fill_n(vis, n, false);
    S = s, T = t; dis[S] = 0;
    static container::point_iterator ptr[V]; container pq(comp);
    for (int i = 0; i < n; ++i) ptr[i] = pq.push(std::make_pair(i, dis[i]));

    while (!pq.empty()) {
      int u = pq.top().first, du = pq.top().second; pq.pop();
      dis[u] = du, vis[u] = true; if (u == T) return;
      for (edge* i = head[u]; i; i = i->next) {
        int v = i->to; if (vis[v]) continue;
        int dv = du + i->cost;
        if (dv < ptr[v]->second) pq.modify(ptr[v], std::make_pair(v, dv));
      }
    }
  }

  inline void solve(int s, int n) {
    solve(s, -1, n);
  }
}

map<string,int> s;
int in() {
  static string x; cin >> x;
  auto it = s.find(x);
  if (it != s.end()) return it->second;
  int res = s.size();
  return s[x] = res, res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n && ~n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    s.clear();
    int S = in(), T = in();
    dijstra::clear();
    while (n--) {
      int u = in(), v = in(), w; cin >> w;
      dijstra::add_douple_edge(u, v, w);
    }
    dijstra::solve(S, T, s.size());
    int ans = dijstra::dis[T];
    cout << (ans == dijstra::oo ? -1 : ans) << '\n';
  }
  return 0;
}
