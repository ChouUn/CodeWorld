//@ Including Header
#include <csl_std.h>
#include <csl_math.h>
#include <ntt.h>

/**
 *  Name : zucc5516.cpp
 *  Date : 2016年5月21日 上午9:44:04
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
const ll P = 880803841;

namespace seg {
  struct node {
    int cnt;
    int sum;
    bool lzy;
  };
  node f[N << 2];

  inline int ls(int id) { return id * 2; }
  inline int rs(int id) { return id * 2 + 1; }

  inline void pushdown(int id) {
    if (f[id].lzy) {
      f[id].lzy = 0;
      f[ls(id)].lzy ^= 1;
      f[ls(id)].cnt = f[ls(id)].sum - f[ls(id)].cnt;
      f[rs(id)].lzy ^= 1;
      f[rs(id)].cnt = f[rs(id)].sum - f[rs(id)].cnt;
    }
  }

  inline void pushup(int id) {
    f[id].cnt = f[ls(id)].cnt + f[rs(id)].cnt;
  }

  void build(int id, int l, int r) {
    if (l == r) {
      f[id].cnt = 1;
      f[id].sum = 1;
      f[id].lzy = 1;
      return;
    }
    int m = (l + r) >> 1;
    build(ls(id), l, m);
    build(rs(id), m + 1, r);
    pushup(id);
    f[id].sum = f[ls(id)].sum + f[rs(id)].sum;
    f[id].lzy = 0;
  }

  inline int query() {
    return f[1].cnt;
  }

  void update(int id, int l, int r, const int& p, const int& q) {
    if (p <= l && r <= q) {
      f[id].cnt = f[id].sum - f[id].cnt;
      f[id].lzy ^= 1;
      return;
    }
    int m = (l + r) >> 1;
    pushdown(id);
    if (p <= m) update(ls(id), l, m, p, q);
    if (q > m) update(rs(id), m + 1, r, p, q);
    pushup(id);
  }
}

ll fac[N], inv[N], neg[N], pwr[N];

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, N) fac[i] = fac[i - 1] * i % P;
  inv[N - 1] = csl::inv(fac[N - 1], P);
  per(i, 1, N) inv[i - 1] = inv[i] * i % P;
  neg[0] = 1;
  rep(i, 1, N) neg[i] = neg[i - 1] * (P - 1) % P;

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m, k; cin >> n >> m >> k;

    rep(i, 0, N) pwr[i] = csl::pow(ll(1), ll(i), n, P);
    vector<ll> g, h; g.reserve(n + 1); h.reserve(n + 1);
    rep(i, 0, n + 1) g.push_back(neg[i] * inv[i] % P);
    rep(i, 0, n + 1) h.push_back(pwr[i] * inv[i] % P);
    vector<ll> ans = csl::ntt<>(P)(g, h);

    seg::build(1, 1, m);
    while (k--) {
      int x, y; cin >> x >> y;
      seg::update(1, 1, m, x, y);
      int z = seg::query();
      cout << ans[z] << endl;
    }
  }
  return 0;
}
