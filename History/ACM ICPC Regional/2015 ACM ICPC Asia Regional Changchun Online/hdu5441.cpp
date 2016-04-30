//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5441.cpp
 *  Date : 2015年9月13日 上午9:23:47
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 20010
#define maxm 100010
#define maxq 5010
int s[maxn];
int a[maxm], b[maxm], c[maxm], d[maxm], f[maxm];
int g[maxn], h[maxn];

inline bool cmp(int a, int b) {
  return c[a] < c[b];
}

int root(int u) {
  return g[u] == u ? u : g[u] = root(g[u]);
}

int merge(int u, int v) {
  int ru = root(u), rv = root(v);
  if(ru == rv) return 0;
  int ret = s[h[ru]] + s[h[rv]];
  g[rv] = ru, h[ru] += h[rv];
  return s[h[ru]] - ret;
}

//@ Main Function
int main(){
  rep(i, 1, maxn) s[i] = i * (i-1) / 2;

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int n, m, q; cin >> n >> m >> q;
    rep(i, 0, m) cin >> a[i] >> b[i] >> c[i], d[i]=i;
    sort(d, d+m, cmp);

    rep(i, 1, n+1) g[i]=i, h[i]=1;
    int cnt = 0;
    rep(i, 0, m) {
      int j = d[i];
      f[j] = (cnt += merge(a[j],b[j]));
    }

    rep(i, 0, q) {
      int x; cin >> x;
      int l = 0, r = m-1;
      while(l < r) {
        int m = (l + r) >> 1;
        c[d[m]] <= x ? l = m+1 : r = m;
      }
      if(l && c[d[l]] > x) --l;
      cout << (c[d[l]] <= x ? f[d[l]] << 1 : 0) << endl;
    }
  }
  return 0;
}
