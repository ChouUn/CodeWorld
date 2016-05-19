//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu2966.cpp
 *  Date : 2015年12月4日 上午11:57:24
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 100010

struct node {
  int idx;
  int dim[2];
  int l, r;
  int operator[] (int k) const { return dim[k]; }
  int& operator[] (int k) { return dim[k]; }
};
node g[maxn];
int pos[maxn];

struct cmp {
  int k;
  cmp(int k) : k(k) {}
  bool operator() (const node& a, const node& b) const {
    return a[k] < b[k];
  }
};

int build(int l, int r, int k) {
  int m = (l + r) >> 1;
  nth_element(g + l, g + m, g + r + 1, cmp(k));
  g[m].l = (m != l) ? build(l, m - 1, !k) : 0;
  g[m].r = (m != r) ? build(m + 1, r, !k) : 0;
  return m;
}

ll dis(ll x, ll y) {
  return x * x + y * y;
}

ll ans;
void query(int m, int k, int x, int y) {
  ll res = dis(x - g[m][0], y - g[m][1]);
  if(res) ans = min(ans, res);
  if(g[m].l && g[m].r) {
    bool d = k ? (y <= g[m][1]) : (x <= g[m][0]);
    query(d ? g[m].l : g[m].r, !k, x, y);
    ll tmp = k ? dis(y - g[m][1], 0) : dis(x - g[m][0], 0);
    if(tmp < ans) query(d ? g[m].r : g[m].l, !k, x, y);
  }
  else if(g[m].l) query(g[m].l, !k, x, y);
  else if(g[m].r) query(g[m].r, !k, x, y);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int n; cin >> n;
    rep(i, 1, n+1) cin >> g[i][0] >> g[i][1];
    rep(i, 1, n+1) g[i].idx = i;
    int root = build(1, n, 0);
    rep(i, 1, n+1) pos[g[i].idx] = i;
    rep(i, 1, n+1) {
      ans = 9e18;
      query(root, 0, g[pos[i]][0], g[pos[i]][1]);
      cout << ans << endl;
    }
  }
  return 0;
}
