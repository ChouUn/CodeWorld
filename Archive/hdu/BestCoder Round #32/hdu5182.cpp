//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5182.cpp
 *  Date : 2015年11月23日 下午7:12:57
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 110

struct node {
  int del, snd, idx;
  static bool cmp(const node &a,const node &b) {
    return a.del != b.del ? a.del > b.del :
      a.snd != b.snd ? a.snd < b.snd : a.idx < b.idx;
  }
} a[maxn];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    rep(i, 0, n) {
      int x, y; cin >> x >> y;
      a[i].del = x - y, a[i].snd = y, a[i].idx = i;
    }
    sort(a, a + n, node::cmp);
    rep(i, 0, n) cout << a[i].idx << (i != n - 1 ? ' ' : '\n');
  }
  return 0;
}
