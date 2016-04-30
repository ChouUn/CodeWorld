//@ Including Header
#include <csl_std.h>
#include <graph.h>

/*
 *  Name : hdu5409.cpp
 *  Date : 2015年8月21日 下午4:17:37
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef csl::graph<bool> graph;
typedef csl::graph<bool>::_Link edge;
typedef csl::tarjan<bool> tarjan;

#define maxn 100010
int n, m;
graph g, f;
tarjan h;

int idx, cnt, x[maxn], y[maxn], dfn[maxn];
void dfs(int u, int p) {
  dfn[u] = cnt++;
  y[u] = x[u];
  for (edge i = f.getHead(u); i; i = i->next) {
    int v = i->to;
    if (v == p) continue;
    dfs(v, u);
    if (y[u] < y[v]) y[u] = y[v];
  }
}

//@ Main Function
void Main() {
  int _; scanf("%d", &_);
  while (_--) {
    scanf("%d%d", &n, &m);
    g.build(n + 1, 2 * m);
    rep(i, 0, m) {
      int u, v; scanf("%d%d", &u, &v);
      g.add_double_edge(u, v, true);
    }

    h.dcc(g), idx = h.size();
    f.build(idx, n << 1);
    rep(i, 1, n + 1) x[h[i]] = i;
    rep(i, 0, m) {
      edge z = g.getEdge((i << 1) | 1);
      int u = h[z->from], v = h[z->to];
      if (u != v) f.add_double_edge(u, v, true);
    }

    cnt = 0;
    rep(i, 0, idx) if (x[i] == n) dfs(i, -1);
    rep(i, 0, m) {
      edge z = g.getEdge((i << 1) | 1);
      int u = h[z->from], v = h[z->to];
      if (u == v) printf("0 0\n");
      else {
        if (dfn[u] > dfn[v]) swap(u, v);
        printf("%d %d\n", y[v], y[v] + 1);
      }
    }
    continue;
  }
}

// Anti Stack Overflow
int main() {
  int _size = 16 << 20; // MB : << 20 ; KB : << 10 ;
  char* _data = (char*)malloc(_size) + _size;
#if __x86_64__ || __ppc64__ || _WIN64
  __asm__ __volatile__("movq %0,%%rsp\n pushq $_exit\n"::"r"(_data));
#else // 64-bit
  __asm__ __volatile__("movl %0,%%esp\n pushl $_exit\n"::"r"(_data));
#endif // 32-bit
  Main();
  exit(0);
}
