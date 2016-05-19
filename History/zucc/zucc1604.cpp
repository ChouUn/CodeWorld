//@ Including Header
// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#include <csl_std.h>

/**
 *  Name : zucc1604.cpp
 *  Date : 2015年12月3日 下午3:27:17
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

struct node {
  ll clr;
  ll cnt;
  ll tag;
};

#define maxn 100010
node f[maxn<<2];

void push_up(int id) {
  f[id].clr = (f[id<<1].clr == f[id<<1|1].clr) ? f[id<<1].clr : 0;
  f[id].cnt = f[id<<1].cnt + f[id<<1|1].cnt;
  f[id].tag = 0;
}

void push_down(int id, int num) {
  if (f[id].clr) {
    f[id<<1].clr = f[id].clr;
    f[id<<1|1].clr = f[id].clr;
    f[id<<1].tag += f[id].tag;
    f[id<<1|1].tag += f[id].tag;
    f[id<<1].cnt += (num-(num>>1)) * f[id].tag;
    f[id<<1|1].cnt += (num>>1) * f[id].tag;
    f[id].clr = 0;
  }
}

void build(int id, int l, int r) {
  if (l == r) { f[id].clr = l; f[id].cnt = 0; f[id].tag = 0; return; }
  int m = (l + r) >> 1;
  build(id<<1, l, m);
  build(id<<1|1, m+1, r);
  push_up(id);
}

void update(int id, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y && f[id].clr) {
    f[id].cnt += abs(f[id].clr - z) * (r - l + 1);
    f[id].tag += abs(f[id].clr - z);
    f[id].clr = z; return;
  }
  push_down(id, r - l + 1);
  int m = (l + r) >> 1;
  if(x <= m) update(id<<1, l, m, x, y, z);
  if(m < y) update(id<<1|1, m+1, r, x, y, z);
  push_up(id);
}

ll query(int id, int l, int r, int x, int y) {
  if (x <= l && r <= y) return f[id].cnt;
  push_down(id, r - l + 1);
  int m = (l + r) >> 1;
  ll ans = 0;
  if(x <= m) ans += query(id<<1, l, m, x, y);
  if(m < y) ans += query(id<<1|1, m+1, r, x, y);
  return ans;
}

//@ Main Function
int main() {
//  std::ios_base::sync_with_stdio(false);
//  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m; cin >> n >> m; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    build(1, 1, n);
    while (m--) {
      int op, x, y, z; scanf("%d%d%d", &op, &x, &y);
      if(op == 1) scanf("%d", &z), update(1, 1, n, x, y, z);
      else if(op == 2) printf("%lld\n", query(1, 1, n, x, y));
      else assert(false);
    }
  }
  return 0;
}
