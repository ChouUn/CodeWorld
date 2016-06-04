//@ Including Header
#include <csl_std.h>

/**
 *  Name : L3-1.cpp
 *  Date : 2016年6月4日 下午2:52:23
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 510;

struct node {
  int l, t, n;
  bool operator > (const node& b) const {
    if (t != b.t) return t > b.t;
    else if (l != b.l) return l > b.l;
    return n > b.n;
  }
  bool operator < (const node& b) const {
    if (t != b.t) return t < b.t;
    else if (l != b.l) return l < b.l;
    return n < b.n;
  }
  node operator + (const node& b) const {
    return node{l + b.l, t + b.t, n + b.n};
  }
};

#include <climits>
#include <cstring>
#include <algorithm>
#include <utility>
#include <ext/pb_ds/priority_queue.hpp>

namespace dijkstra {
  const int V = N;
  const int E = N * N;
  const int oo = INT_MAX / 2;

  typedef std::pair<int,node> pii;
  const auto comp = [](const pii& a, const pii& b) -> bool {
    return a.second > b.second;
  };
  typedef __gnu_pbds::priority_queue<pii,decltype(comp)> container;

  struct edge {
    edge *next;
    int to;
    node cost;
  };

  edge e[E], *head[V]; bool vis[V];
  int en, S, T; node dis[V];
  int frm[V];

  inline void clear() {
    memset(head, 0x00, sizeof head), en = 0;
  }

  inline edge* add_edge(int from, int to, node cost) {
    edge* res = e + en++;
    res->to = to, res->cost = cost;
    return res->next = head[from], head[from] = res, res;
  }

  inline void add_double_edge(int from, int to, node cost) {
    add_edge(from, to, cost);
    add_edge(to, from, cost);
  }

  void solve(int s, int t, int n) {
    rep(i, 0, n) dis[i] = node{oo, oo, oo};
    std::fill_n(vis, n, false);
    S = s, T = t; dis[S] = node{0, 0, 0};
    static container::point_iterator ptr[V]; container pq(comp);
    for (int i = 0; i < n; ++i) ptr[i] = pq.push(std::make_pair(i, dis[i]));

    while (!pq.empty()) {
      int u = pq.top().first;
      node du = pq.top().second;
      pq.pop();
      dis[u] = du, vis[u] = true; if (u == T) return;
      for (edge* i = head[u]; i; i = i->next) {
        int v = i->to; if (vis[v]) continue;
        node dv = du + i->cost;
        if (dv < ptr[v]->second) pq.modify(ptr[v], std::make_pair(v, dv)), frm[v] = u;
      }
    }
  }

  inline void solve(int s, int n) {
    solve(s, -1, n);
  }
}

string i2s(int x) {
  stringstream ss; ss << x;
  string res; ss >> res; return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; cin >> n >> m;
  rep(i, 0, m) {
    int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    if (c == 1) dijkstra::add_edge(a, b, node{d, e, 1});
    else dijkstra::add_double_edge(a, b, node{d, e, 1});
  }
  int s, t; cin >> s >> t;

  dijkstra::solve(s, t, n);
  deque<int> x;
  {
    int d = t; x.push_front(d);
    while (d != s) d = dijkstra::frm[d], x.push_front(d);
  }
  int xx = dijkstra::dis[t].t;

  rep(i, 0, dijkstra::en) dijkstra::e[i].cost.t = 0;
  dijkstra::solve(s, t, n);
  deque<int> y;
  {
    int d = t; y.push_front(d);
    while (d != s) d = dijkstra::frm[d], y.push_front(d);
  }
  int yy = dijkstra::dis[t].l;

  if (x == y) {
    cout << "Time = " << xx << "; Distance = " << yy << ": ";
    int flag = 0;
    while (!x.empty()) {
      if (flag) cout << " => "; flag = 1;
      cout << x.front(), x.pop_front();
    }
    cout << endl;
  }
  else {
    cout << "Time = " << xx << ": ";
    int flag = 0;
    while (!x.empty()) {
      if (flag) cout << " => "; flag = 1;
      cout << x.front(), x.pop_front();
    }
    cout << endl;
    cout << "Distance = " << yy << ": ";
    flag = 0;
    while (!y.empty()) {
      if (flag) cout << " => "; flag = 1;
      cout << y.front(), y.pop_front();
    }
    cout << endl;
  }
  return 0;
}
