//@ Including Header
#include <csl_std.h>

/**
 *  Name : fhc2016-2d.cpp
 *  Date : 2016年1月17日 下午3:50:09
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 16;
const int T[6][5] = {{1},{2,1},{3,2,1},{5,3,2,1},{9,5,3,2,1}};
bool g[N][N];
bool f[1<<N][N];

int nxt(int n, int m) {
  int x = __builtin_popcount(n) / 2;
  do {
    int i = 1;
    while(i <= n) {
      if((n & i) && !(m & i)) break;
      m &= ~i, i <<= 1;
    }
    if(i > n) return -1;
    m |= i;
  } while(__builtin_popcount(m) != x);
  return m;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    int n; cin >> n;
    rep(i, 0, n) rep(j, 0, n) cin >> g[i][j];
    int m = 0; while((1 << m) != n) ++m;

    memset(f, 0x00, sizeof f);
    rep(i, 0, n) f[1<<i][i] = 1;
    for(int l = 1; l <= m; ++l) {
      rep(i, 0, 1 << n) {
        if(__builtin_popcount(i) != (1 << l)) continue;
//        clog << "i = " << i << "; ";
        int x = nxt(i, 0);
        do {
//          clog << x << " ";
          rep(p, 0, n) {
            if(!f[x][p]) continue;
            int y = i ^ x;
            rep(q, 0, n) {
              if(!f[y][q]) continue;
              int r = g[p][q] ? p : q;
              f[i][r] = true;
//              clog << "i = " << i << ", r = " << r << endl;
            }
          }
          x = nxt(i, x);
        } while(x != -1);
//        clog << endl;
      }
    }

    vector<int> ans[2]; ans[0].assign(n, 0); ans[1].assign(n, m);
    for(int l = 0; (1 << l) <= n; ++l) {
      rep(i, 1, 1 << n) {
        if(__builtin_popcount(i) != (1 << l)) continue;
        rep(p, 0, n) {
          if(!f[i][p]) continue;
          rep(k, 0, n) {
            if((1 << k) & i) {
              if(k != p) ans[1][k] = min(ans[1][k], l - 1);
              else ans[0][k] = max(ans[0][k], l);
            }
          }
        }
      }
    }
    std::cout << "Case #" << __ << ": \n";
    rep(i, 0, n) cout << T[m][ans[0][i]] << " " << T[m][ans[1][i]] << endl;
  }
  return 0;
}
