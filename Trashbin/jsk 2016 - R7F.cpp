//@ Including Header
#include <csl_std.h>

/**
 *  Name : jsk 2016 - R7F.cpp
 *  Date : 2016年7月3日 下午2:02:42
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int V = 210;
const int E = 100 * 100 * 5;
const int S = 0, T = 1;

#include <climits>
#include <cmath>
#include <cstring>
#include <algorithm>

namespace sap {
  const int V = ::V;
  const int E = ::E;
  const int oo = INT_MAX / 2;

  struct edge {
    edge *next, *pair;
    int rest, to, ori;
  };

  edge e[E], *head[V], *copy[V];
  int en, S, T, N, h[V], g[V], ans;

  inline void clear() {
    memset(head, 0x00, sizeof head), en = 0;
  }

  inline edge* add_edge(int from, int to, int rest) {
    edge* res = e + en++;
    res->to = to, res->rest = rest, res->ori = rest;
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

vi ans;
void dfs(int u) {
  ans.push_back(u);
  if (u == T) return;
  for (auto e = sap::copy[u]; e; e = e->next) {
    if (e->rest < e->ori) {
      ++e->rest, dfs(e->to);
      return ;
    }
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
    int s, t, mid; cin >> s >> t >> mid;

    sap::clear();
    sap::add_couple_edge(S, mid * 2, 2);
    sap::add_couple_edge(s * 2 + 1, T, 1);
    sap::add_couple_edge(t * 2 + 1, T, 1);
    rep(i, 1, n + 1) sap::add_couple_edge(i * 2, i * 2 + 1, i == mid ? 2 : 1);
    rep(i, 0, m) {
      int u, v; cin >> u >> v;
      sap::add_couple_edge(u * 2 + 1, v * 2, 1);
      sap::add_couple_edge(v * 2 + 1, u * 2, 1);
    }
    sap::solve(S, T, n * 2 + 2);
//    cout << sap::ans << endl;
    ans.clear(), dfs(S);
    vi tot = ans, tmp;
    ans.clear(), dfs(S);
    for (int i = 1; i < (int)tot.size() - 1; i += 2) tmp.push_back(tot[i] / 2);
    reverse(tmp.begin(), tmp.end());
    for (int i = 3; i < (int)ans.size() - 1; i += 2) tmp.push_back(ans[i] / 2);
    if (tmp[0] != s) reverse(tmp.begin(), tmp.end());

    bool flag = 0;
    for (auto x : tmp) { if (flag) cout << " "; cout << x; flag = true; }
    cout << endl;
  }
  return 0;
}
