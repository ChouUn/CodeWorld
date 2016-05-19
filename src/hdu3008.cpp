//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu3008.cpp
 *  Date : 2016年5月16日 下午9:03:16
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

/*
There are several test cases,intergers n ,t and q (0<n<=100，1<=t<=5，q>0)
in the first line which mean you own n kinds of skills ,
and the "ResumingCirclet" helps you resume t points of MagicValue per second
and q is of course the hurt points of LifeValue the Boss attack you each time
(we assume when fighting in a second the attack you show is before the Boss).
Then n lines follow,each has 2 intergers ai and bi(0<ai,bi<=100).
which means using i skill costs you ai MagicValue and costs the Boss bi LifeValue.
The last case is n=t=q=0.
4 2 25
10 5
20 10
30 28
76 70
4 2 25
10 5
20 10
30 28
77 70
0 0 0
*/

const int N = 110;
const int M = 100;
int a[N], b[N];
int dp[2][N], *f = dp[0], *g = dp[1];

void update(int& a, int b, int c = 0) {
  if (b == -1) return;
  b += c;
  if (a == -1 || a < b) a = b;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, p, q; cin >> n >> p >> q && n && p && q; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    rep(i, 0, n) cin >> a[i] >> b[i];
    a[n] = 0, b[n] = 1, ++n;

    int ans = -1;
    fill_n(f, N, -1); f[M] = 0;
    for (int m = M, cnt = 1; m > 0; m -= q, ++cnt) {
      fill_n(g, N, -1);
      rep(k, 0, n) rep(i, a[k], M + 1) update(g[min(i - a[k] + p, M)], f[i], b[k]);
      swap(f, g);
      rep(i, 0, M + 1) if (f[i] >= M) { ans = cnt; break; }
    }
    if (~ans) cout << ans << endl;
    else cout << "My god" << endl;
  }
  return 0;
}
