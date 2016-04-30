//@ Including Header
#include <csl_std.h>
#include <csl_math.h>
#include <ModInt.h>

/*
 *  Name : hdu5498.cpp
 *  Date : 2015年11月12日 下午3:27:26
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 110
typedef csl::ModInt<> mint;
mint g[maxn][maxn], f[maxn], c[maxn][maxn];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    int n, m, q; ll p; cin >> n >> m >> p >> q;
    mint::M = p;

    rep(i, 0, n) rep(j, 0, n) g[i][j] = 0;
    while(m--) {
      int u, v; cin >> u >> v; --u, --v;
      --g[u][v], --g[v][u], ++g[u][u], ++g[v][v];
    }

    int sgn = 0;
    rep(i, 0, n-1) {
      int t = -1;
      rep(j, i, n-1) if(g[j][i] != 0) { t = j; break; }
      if(t == -1) break;
      if(t != i) {
        ++sgn;
        rep(k, i, n-1) swap(g[i][k], g[t][k]);
      }
      rep(j, i+1, n-1) {
        while(g[j][i] != 0) {
          ++sgn;
          rep(k, i, n-1) swap(g[i][k], g[j][k]);
          mint tmp = *g[j][i] / *g[i][i];
          rep(k, i, n-1) g[j][k] -= g[i][k] * tmp;
        }
      }
    }

    mint ans = 1;
    rep(i, 0, n-1) ans *= g[i][i];
    if(sgn&1) ans = mint(p) - ans;

    rep(i, 0, n) {
      c[i][0] = 1;
      rep(j, 1, i+1) c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
    rep(i, 1, n) {
      f[i] = csl::pow(1LL, (ll)i, q, p);
      rep(j, 0, i) f[i] -= c[i][j] * f[j];
    }
    cout << ans * f[n-1] << endl;
  }
  return 0;
}
