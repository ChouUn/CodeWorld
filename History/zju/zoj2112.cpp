//@ Including Header
#include <csl_std.h>

/**
 *  Name : zoj2112.cpp
 *  Date : 2016年5月1日 上午2:14:32
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 50010;
const int M = 10010;

#include <vector>
#include <fenwick.h>

namespace overall_dnc {
  const int N = ::N;
  const int M = ::N + ::M * 2;

  struct node {
    int type, x, y, kth;
  };

  int a[N];
  node b[M]; int bn, t[M], ptr[M];
  csl::fenwick_tree<int> ft;

  inline void clear() {
    bn = 0;
  }

  inline void add_build(int p, int x) {
    b[bn++] = node{+1, p, x, 0}, a[p] = x;
  }

  inline void add_update(int p, int x) {
    b[bn++] = node{-1, p, a[p], 0};
    b[bn++] = node{+1, p, x, 0}, a[p] = x;
  }

  inline void add_query(int l, int r, int k) {
    b[bn++] = node{0, l, r, k};
  }

  void solve(int l, int r, int lo, int up) {
    if (l >= r) return;               // [l, r) when query and update is empty
    if (lo == up) {                   // when lower_bound and upper_bound meet
      for (int i = l, k; k = ptr[i], i < r; ++i)  // ptr is a pointer for b[]
        if(!b[k].type) b[k].kth = lo; // to save space, "answer" replace "kth"
      return;
    }

    int mi = (lo + up) / 2;
    for (int i = l, k; k = ptr[i], i < r; ++i)    // mark
      if (!b[k].type) t[k] = ft.query(b[k].y) - ft.query(b[k].x - 1);
      else if (b[k].y <= mi) ft.update(b[k].x, b[k].type);
    for (int i = l, k; k = ptr[i], i < r; ++i)    // unmark
      if (b[k].type && b[k].y <= mi) ft.update(b[k].x, -b[k].type);

    std::vector<int> b1, b2;
    for (int i = l, k; k = ptr[i], i < r; ++i) {
      if (b[k].type)    // divide "change operate" by interval
        if (b[k].y <= mi) b1.push_back(k);
        else b2.push_back(k);
      else              // "kth" indicates the number of smaller numbers needed
        if (t[k] < b[k].kth) b[k].kth -= t[k], b2.push_back(k);
        else b1.push_back(k);
    }

    int p = b1.size(), q = b2.size();
    for (int i = 0; i < p; ++i) ptr[l+i] = b1[i];
    for (int i = 0; i < q; ++i) ptr[l+p+i] = b2[i];
    solve(l, l + p, lo, mi);
    solve(l + p, r, mi + 1, up);
  }

  void solve(int n, int lo, int up) {
    ft.build(n);
    for (int i = 0; i < bn; ++i) ptr[i] = i;
    solve(0, bn, lo, up);
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    overall_dnc::clear();
    rep(i, 1, n+1) {
      int x; cin >> x;
      overall_dnc::add_build(i, x);
    }
    while (m--) {
      char op; cin >> op;
      if (op == 'Q') {
        int l, r, k; cin >> l >> r >> k;
        overall_dnc::add_query(l, r, k);
      }
      else {
        int p, x; cin >> p >> x;
        overall_dnc::add_update(p, x);
      }
    }
    overall_dnc::solve(n, 0, INT_MAX / 2);
    rep(i, 0, overall_dnc::bn)
      if (!overall_dnc::b[i].type) cout << overall_dnc::b[i].kth << '\n';
  }
  return 0;
}
