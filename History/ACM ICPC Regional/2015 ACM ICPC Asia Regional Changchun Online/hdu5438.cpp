//@ Including Header
#include <csl_std.h>
#include <graph.h>

/*
 *  Name : hdu5438.cpp
 *  Date : 2015年9月13日 下午7:32:30
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 10010
#define maxm 100010

typedef csl::graph<bool> graph;
typedef std::pair<int,ll> node;

graph g;
int n, m, a[maxn], b[maxm], c[maxm];
int d[maxn]; bool e[maxn];

void bfs() {
  queue<int> q;
  rep(i, 1, n+1) if (d[i] <= 1) q.push(i);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if(e[u]) continue; e[u] = true;
    if(d[u] != 1) continue;
    for(graph::iterator i = g.getHead(u); i; i = i->next) {
      int v = i->to;
      if(e[v]) continue;
      if((--d[v]) == 1) q.push(v);
    }
  }
}

node dfs(int u) {
  node res(1,a[u]);
  e[u] = true;
  for(graph::iterator i = g.getHead(u); i; i = i->next) {
    int v = i->to;
    if(e[v]) continue;
    node tmp = dfs(v);
    res.first += tmp.first, res.second += tmp.second;
  }
  return res;
}

//@ Main Function
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    cin >> n >> m;
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 0, m) cin >> b[i] >> c[i];

    g.build(n+1, m<<1);
    rep(i, 1, n+1) d[i] = 0, e[i] = 0;
    rep(i, 0, m) {
      g.add_double_edge(b[i], c[i], true);
      ++d[b[i]], ++d[c[i]];
    }

    bfs();
    ll ans = 0;
    rep(i, 1, n+1) if(!e[i]) {
      node res = dfs(i);
      if (res.first & 1) ans += res.second;
    }
    cout << ans << endl;
  }
  return 0;
}
