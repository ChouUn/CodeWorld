//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6206.cpp
 *  Date : 2016年7月5日 上午8:59:11
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 110;
int n, m, flag;
char g[N][N];
int f[N][N], h[N][N];

void label() {
  m = 1, flag = 0;
  rep(i, 0, n) {
    rep(j, 0, n) {
      if (g[i][j] == 'W' && flag) ++m, flag = 0;
      else if (g[i][j] == 'S') f[i][j] = m, flag = 1;
    }
    if (flag) ++m, flag = 0;
  }
  rep(j, 0, n) {
    rep(i, 0, n) {
      if (g[i][j] == 'W' && flag) ++m, flag = 0;
      else if (g[i][j] == 'S') h[i][j] = m, flag = 1;
    }
    if (flag) ++m, flag = 0;
  }
}

const int MAXN = 20010;//点数的最大值
const int MAXM = 20010;//边数的最大值
struct Edge {
  int to,next;
} edge[MAXM];
int head[MAXN], tot;
void init()
{
  tot = 0;
  memset(head,-1,sizeof(head));
}
void addedge(int u, int v)
{
  edge[tot].to = v; edge[tot].next = head[u];
  head[u] = tot++;
}
int linker[MAXN];
bool used[MAXN];
int uN;
bool dfs(int u)
{
  for(int i = head[u]; i != -1 ;i = edge[i].next)
  {
    int v = edge[i].to;
    if(!used[v])
    {
      used[v] = true;
      if(linker[v] == -1 || dfs(linker[v]))
      {
        linker[v] = u;
        return true;
      }
    }
  }
  return false;
}
int hungary()
{
  int res = 0;
  memset(linker,-1,sizeof(linker));
  for(int u = 0; u < uN;u++)//点的编号0~uN-1
  {
    memset(used,false,sizeof(used));
    if(dfs(u))res++;
  }
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(; cin >> n && n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, n) cin >> g[i];
    memset(f, 0x00, sizeof f);
    memset(h, 0x00, sizeof h);
    label();
    init(), uN = m;
    rep(i, 0, n) rep(j, 0, n)
      if (f[i][j] && h[i][j]) addedge(f[i][j], h[i][j]);
    cout << hungary() << endl;
  }
  return 0;
}
