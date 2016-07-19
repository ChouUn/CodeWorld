//@ Including Header
// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#ifndef CSL_STD_H_
#define CSL_STD_H_ 20151122L
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair< int, int > pii;
typedef std::vector< int > vi;
typedef std::vector< vi > vvi;
typedef std::vector< pii > vpii;

#define rep(i,a,b) for(int i=a,i##_n=b;i<i##_n;++i)
#define per(i,a,b) for(int i=b,i##_n=a;i-->i##_n;)
#define endl '\n'

#endif /* CSL_STD_H_ */

/**
 *  Name : zju6326.cpp
 *  Date : 2016年7月8日 上午9:36:34
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 50010;
const int M = 300;
struct node {
  int x, y, l;
};
struct range {
  int l, r, min, max;
};
node p[4][N]; int pn[4];
range q[4][M]; int qn[4];

int func(int t, const node& a, int x, int y) {
  if (t == 0) return x + y <= a.x + a.y + a.l;
  else if (t == 1) return (x - y - a.x + a.y) >= 0 && (x - y - a.x + a.y) <= a.l;
  else if (t == 2) return (y - x - a.y + a.x) >= 0 && (y - x - a.y + a.x) <= a.l;
  else if (t == 3) return a.x + a.y - a.l <= x + y;
  else assert(false);
  return 0;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m, k; cin >> n >> m >> k;
    rep(j, 0, 4) pn[j] = 0;
    rep(i, 0, m) {
      int t, x, y, l; cin >> t >> x >> y >> l;
      --t;
      p[t][pn[t]].x = x;
      p[t][pn[t]].y = y;
      p[t][pn[t]].l = l;
      ++pn[t];
    }

    rep(i, 0, 4)
      sort(p[i], p[i] + pn[i], [](const node&a, const node& b) -> bool {
        return a.x < b.x;
      });
    rep(j, 0, 4) {
      qn[j] = 0;
      rep(i, 0, pn[j]) {
        int t = i / M;
        if (t >= qn[j]) q[j][t].l = i, q[j][t].min = p[j][i].x, ++qn[j];
        q[j][t].r = i, q[j][t].max = p[j][i].x;
      }
      rep(i, 0, qn[j])
        sort(p[j] + q[j][i].l, p[j] + q[j][i].r + 1, [](const node&a, const node& b) -> bool {
          return a.y < b.y;
        });
    }

    while (k--) {
      int x, y; cin >> x >> y;

      int j = 0, ans = 0;
      rep(i, 0, qn[j]) {
        if (x >= q[j][i].max) {
//          cout << j << " 1 " << i << endl;
          auto l = upper_bound(p[j] + q[j][i].l, p[j] + q[j][i].r + 1, y,
            [](int y, const node& a) { return y < a.y; }) - p[j];
          rep(k, q[j][i].l, l) ans += func(j, p[j][k], x, y);
        }
        else if (x >= q[j][i].min) {
//          cout << j << " 2 " << i << endl;
          rep(k, q[j][i].l, q[j][i].r + 1) {
            if (p[j][k].x <= x && p[j][k].y <= y) ans += func(j, p[j][k], x, y);
          }
        }
        else continue;
      }
//      cout << ans << endl;

      j = 1;
      rep(i, 0, qn[j]) {
        if (x >= q[j][i].max) {
//          cout << j << " 1 " << i << endl;
          auto l = lower_bound(p[j] + q[j][i].l, p[j] + q[j][i].r + 1, y,
            [](const node& a, int y) { return a.y < y; }) - p[j];
          rep(k, l, q[j][i].r + 1) ans += func(j, p[j][k], x, y);
        }
        else if (x >= q[j][i].min) {
//          cout << j << " 2 " << i << endl;
          rep(k, q[j][i].l, q[j][i].r + 1) {
            if (p[j][k].x <= x && p[j][k].y >= y) ans += func(j, p[j][k], x, y);
          }
        }
        else continue;
      }
//      cout << ans << endl;

      j = 2;
      rep(i, 0, qn[j]) {
        if (x <= q[j][i].min) {
//          cout << j << " 1 " << i << endl;
          auto l = upper_bound(p[j] + q[j][i].l, p[j] + q[j][i].r + 1, y,
            [](int y, const node& a) { return y < a.y; }) - p[j];
          rep(k, q[j][i].l, l) ans += func(j, p[j][k], x, y);
        }
        else if (x <= q[j][i].max) {
//          cout << j << " 2 " << i << endl;
          rep(k, q[j][i].l, q[j][i].r + 1) {
            if (p[j][k].x >= x && p[j][k].y <= y) ans += func(j, p[j][k], x, y);
          }
        }
        else continue;
      }
//      cout << ans << endl;

      j = 3;
      rep(i, 0, qn[j]) {
        if (x <= q[j][i].min) {
//          cout << j << " 1 " << i << endl;
          auto l = lower_bound(p[j] + q[j][i].l, p[j] + q[j][i].r + 1, y,
            [](const node& a, int y) { return a.y < y; }) - p[j];
          rep(k, l, q[j][i].r + 1) ans += func(j, p[j][k], x, y);
        }
        else if (x <= q[j][i].max) {
//          cout << j << " 2 " << i << endl;
          rep(k, q[j][i].l, q[j][i].r + 1) {
            if (p[j][k].x >= x && p[j][k].y >= y) ans += func(j, p[j][k], x, y);
          }
        }
        else continue;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
