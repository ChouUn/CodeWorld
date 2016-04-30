//@ Including Header
#include <csl_std.h>

/**
 *  Name : zucc1624.cpp
 *  Date : 2016年3月29日 下午6:00:26
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 210
#define M 210

int n, m;
int a[N], b[N], c[N], d[N], e, l[N];
vector<int> g[N];
int f[N][M], h[M];

inline void update(int& x, int y) {
  if (x == -1 || y < x) x = y;
}

int dfs(int u) {
  fill(f[u], f[u] + m + 1, -1);
  f[u][0] = a[u], d[e++] = c[u] - b[u];
  int *first = d + e, *last = first, cnt = 0;
  rep(w, 0u, g[u].size()) {
    int v = g[u][w];
    cnt += dfs(v);
    copy(f[u], f[u] + m + 1, h);
    fill(f[u], f[u] + m + 1, -1);
    rep(i, 0, m+1) rep(j, 0, i+1)
      if (~f[v][j] && ~h[i-j]) update(f[u][i], f[v][j] + h[i-j]);
    int *r = copy(first, last, l);
    last = merge(l, r, last, d + e, first);
  }
  if (u != n) {
    int sum = cnt + c[u];
    update(f[u][1], sum);
    rep(i, first, last) update(f[u][i-first+2], sum += *i);
  }
  rep(i, first, last) if (*(i-1) > *i) swap(*(i-1), *i);
  return cnt + b[u];
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> n >> m;
    rep(i, 0, n+1) g[i].clear();
    rep(i, 0, n) {
      int p; cin >> p; p = p ? p - 1 : n;
      cin >> a[i] >> b[i] >> c[i];
      g[p].push_back(i);
      b[i] = min(a[i], b[i]);
    }

    a[n] = b[n] = c[n] = e = 0, dfs(n);
    int ans = -1;
    rep(i, 0, m+1) if (~f[n][i]) update(ans, f[n][i]);
    cout << ans << endl;
  }
  return 0;
}
