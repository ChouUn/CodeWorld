/*
 *	Name : zju3781.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��23�� ����4:31:14
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 42

int n, m;
char mp[maxN][maxN];
int vis[maxN][maxN];
set<int> g[maxN*maxN];

void dfs(int x, int y, int id) {
  if (x < 0 || x >= n || y < 0 || y >= m) return;
  if (vis[x][y] > -1) return; vis[x][y] = id;
  if (mp[x][y] == mp[x][y-1]) dfs(x, y-1, id);
  if (mp[x][y] == mp[x][y+1]) dfs(x, y+1, id);
  if (mp[x][y] == mp[x-1][y]) dfs(x-1, y, id);
  if (mp[x][y] == mp[x+1][y]) dfs(x+1, y, id);
}

void add_edge(int x, int y) {
  g[x].insert(y);
  g[y].insert(x);
}

int dis[maxN*maxN];
int bfs(int s) {
  int r = 0;
  memset(dis, 0xff, sizeof(dis));
  queue<int> q;
  q.push(s); dis[s] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    r = max(r, dis[u]);
//    printf("u = %d : ", u);
    for (set<int>::iterator i = g[u].begin(); i != g[u].end(); i++) {
      int v = *i;
//      printf("v = %d, ", v);
      if (dis[v] > -1) continue;
      q.push(v); dis[v] = dis[u] + 1;
    }
//    printf("\n");
  }
  return r;
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", mp[i]);

    memset(vis, 0xff, sizeof(vis));
    int id = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (vis[i][j] == -1) dfs(i, j, id++);
/*
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        printf("%d ", vis[i][j]);
      printf("\n");
    }
    printf("id = %d\n", id);
*/
    for (int i = 0; i < id; i++) g[i].clear();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (i + 1 < n && vis[i][j] != vis[i+1][j])
          add_edge(vis[i][j], vis[i+1][j]);
        if (j + 1 < m && vis[i][j] != vis[i][j+1])
          add_edge(vis[i][j], vis[i][j+1]);
      }

    int ans = n * m;
    for (int i = 0; i < id; i++)
      ans = min(ans,bfs(i));
    printf("%d\n", ans);
  }
  return 0;
}
