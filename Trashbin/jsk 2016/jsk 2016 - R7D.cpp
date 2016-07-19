//@ Including Header
#include <csl_std.h>
#include <discrete.h>

/**
 *  Name : jsk 2016 - R7D.cpp
 *  Date : 2016年7月3日 下午3:32:23
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 200010;
vpii v;
int x[N], y[N];

struct node {
  ll sum;
};
node f[N << 2];

inline void pushup(int id) {
  f[id].sum = f[id * 2].sum + f[id * 2 + 1].sum;
}

void build(int id, int l, int r) {
  if (l == r) { f[id].sum = 0; return; }
  int m = (l + r) / 2;
  build(id * 2, l, m);
  build(id * 2 + 1, m + 1, r);
  pushup(id);
}

void update(int id, int l, int r, int p, int q) {
  if (l == r) { f[id].sum += q; return; }
  int m = (l + r) / 2;
  if (p <= m) update(id * 2, l, m, p, q);
  else update(id * 2 + 1, m + 1, r, p, q);
  pushup(id);
}

ll query(int id, int l, int r, int p, int q) {
  if (p <= l && r <= q) return f[id].sum;
  int m = (l + r) / 2;
  ll res = 0;
  if (p <= m) res += query(id * 2, l, m, p, q);
  if (m < q) res += query(id * 2 + 1, m + 1, r, p, q);
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; cin >> n;
  rep(i, 0, n) cin >> x[i] >> y[i];

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  csl::discrete<int> d;
  d.reserve(N * 2);
  d.insert(x, x + n);
  d.insert(y, y + n);
  d.build();
  rep(i, 0, n) x[i] = d.query(x[i]);
  rep(i, 0, n) y[i] = d.query(y[i]);

  v.reserve(N);
  rep(i, 0, n) v.push_back(make_pair(x[i] + 1, y[i] + 1));
  sort(v.begin(), v.end(), [](const pii& x, const pii& y) -> bool {
    return x.second < y.second;
  });

  int m = d.size();
  build(1, 1, m);
  update(1, 1, m, v[0].second, 1);
  int mi = v[0].second;

//  cout << m << endl;
//  cout << query(1, 1, m, 1, m) << endl;
//  rep(i, 0, n) cout << v[i].first << " " << v[i].second << endl;

//  ll prev = 0, ans = 0;
  rep(i, 1, n) {
    ll cnt = query(1, 1, m, v[i].first, v[i].second);
    update(1, 1, m, v[i].second, cnt);
//    cout << v[i].first << " " << v[i].second << " ";
//    cout << cnt << " " << query(1, 1, m, 1, m) << endl;
    if (v[i].first <= mi) update(1, 1, m, v[i].second, 1);
    mi = min(mi, v[i].second);
//    ll next = query(1, 1, m, 1, m); ans = next - prev, prev = next;
  }
  cout << query(1, 1, m, 1, m) << endl;

  return 0;
}
