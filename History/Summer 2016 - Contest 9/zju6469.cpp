//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6469.cpp
 *  Date : 2016年7月15日 上午2:20:39
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

struct node {
  int a[5], b[5], c, x, y, z;
};

const int N = 100010;
const int P = 1000000007;

int a[N], b[N];
node f[N << 2];

int lln(int x) {
  return x ? lround(floor(log(x))) : 0;
}

void refresh(int id, int c) {
  f[id].c = c;
  f[id].x = f[id].a[c];
  f[id].y = f[id].b[c];
}

void pushup(int id) {
  int ls = id * 2, rs = id * 2 + 1;
  rep(i, 0, 5) {
    f[id].a[i] = (ll)f[ls].a[i] * f[rs].a[i] % P;
    f[id].b[i] = ((ll)f[rs].a[i] * f[ls].b[i] + f[rs].b[i]) % P;
  }
  if (f[ls].c != -1 && f[ls].c == f[rs].c) refresh(id, f[ls].c);
  else {
    f[id].c = -1;
    f[id].x = (ll)f[ls].x * f[rs].x % P;
    f[id].y = ((ll)f[rs].x * f[ls].y + f[rs].y) % P;
  }
}

void pushdown(int id) {
  int ls = id * 2, rs = id * 2 + 1;
  if (f[id].z) {
    f[id].z = 0, f[ls].z = f[rs].z = 1;
    refresh(ls, f[id].c);
    refresh(rs, f[id].c);
  }
}

void build(int id, int l, int r) {
  if (l == r) {
    f[id].a[0] = ::a[l];
    f[id].b[0] = ::b[l];
    rep(i, 1, 5) f[id].a[i] = lln(f[id].a[i - 1]);
    rep(i, 1, 5) f[id].b[i] = lln(f[id].b[i - 1]);
    refresh(id, 0);
    f[id].z = 0;
    return;
  }
  int ls = id * 2, rs = id * 2 + 1;
  int m = (l + r) / 2;
  build(ls, l, m);
  build(rs, m + 1, r);
  pushup(id);
}

void update(int id, int l, int r, int i, int a, int b) {
  if (l == r) {
    f[id].a[0] = a;
    f[id].b[0] = b;
    rep(i, 1, 5) f[id].a[i] = lln(f[id].a[i - 1]);
    rep(i, 1, 5) f[id].b[i] = lln(f[id].b[i - 1]);
    refresh(id, 0);
    f[id].z = 0;
    return;
  }
  pushdown(id);
  int ls = id * 2, rs = id * 2 + 1;
  int m = (l + r) / 2;
  if (i <= m) update(ls, l, m, i, a, b);
  else update(rs, m + 1, r, i, a, b);
  pushup(id);
}

void update(int id, int l, int r, int x, int y) {
//  cout << id << " " << l << " " << r << " " << x << " " << y << endl;
  if (x <= l && r <= y) {
    if (f[id].c != -1) {
      if (f[id].c < 4) refresh(id, f[id].c + 1), f[id].z = 1;
      return;
    }
  }
  pushdown(id);
  int ls = id * 2, rs = id * 2 + 1;
  int m = (l + r) / 2;
  if (x <= m) update(ls, l, m, x, y);
  if (y > m) update(rs, m + 1, r, x, y);
  pushup(id);
}

pii query(int id, int l, int r, int i) {
  if (r <= i) return make_pair(f[id].x, f[id].y);
  pushdown(id);
  int ls = id * 2, rs = id * 2 + 1;
  int m = (l + r) / 2;
  if (i <= m) return query(ls, l, m, i);
  else {
    pii tmp = query(rs, m + 1, r, i);
    pii ans;
    ans.first = (ll)f[ls].x * tmp.first % P;
    ans.second = ((ll)tmp.first * f[ls].y + tmp.second) % P;
    return ans;
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, q; cin >> n >> q;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) cin >> b[i];

    build(1, 1, n);
    while (q--) {
      int op; cin >> op;
      if (op == 1) {
        int i, a, b; cin >> i >> a >> b;
        update(1, 1, n, i, a, b);
      }
      else if (op == 2) {
        int l, r; cin >> l >> r;
//        rep(i, 1, 8) cout << i << " " << f[i].x << " " << f[i].y << endl;
        update(1, 1, n, l, r);
//        rep(i, 1, 8) cout << i << " " << f[i].x << " " << f[i].y << " " << f[i].a[1] << " " << f[i].b[1] << endl;
      }
      else if (op == 3) {
        int i; cin >> i;
        pii ans = query(1, 1, n, i);
        cout << (ans.first + ans.second) % P << endl;
      }
      else assert(false);
    }
  }
  return 0;
}
