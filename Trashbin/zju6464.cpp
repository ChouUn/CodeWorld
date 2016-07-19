//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : zju6464.cpp
 *  Date : 2016年7月15日 上午4:03:05
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
const ll P = 100000007;

ll fac[N], inv[N];

ll f(int n, int m) {
  if (n == 0 || m > n) return 0;
  return fac[n] * inv[m] % P * inv[n - m] % P;
}

int n, m;

ll dfs(int* g, int* h, int k, int s, int n) {
  if (k-- == 0) {
    if (n == 1) return f(s - 1, m - 1);
    else return P - f(s - 1, m - 1);
  }
  ll res = 0;
  for (int i = 0; i <= h[k]; ++i) {
    if (i) s = s * g[k];
    res = (res + dfs(g, h, k, s, n * ((h[k] - i) & 1 ? -1 : 1))) % P;
  }
  return res;
}

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, N) fac[i] = fac[i - 1] * i % P;
  inv[N - 1] = csl::inv(fac[N - 1], P);
  per(i, 1, N) inv[i - 1] = inv[i] * i % P;

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> n >> m;
    int g[20], f[20], k = 0;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i) continue;
      g[k] = i, f[k] = 0;
      while (n % i == 0) n /= i, ++f[k];
      ++k;
    }
    if (n != 1) g[k] = n, f[k] = 1, ++k;

//    ll ans = 0;
    cout << (dfs(g, f, k, 1, +1) % P + P) % P << endl;
//    n = (1 << k);
//    rep(i, 0, n) {
//      int x = 0, y = 1;
//      rep(j, 0, k) if (i & (1 << j)) {
//        ++x, y *= g[j];
//      }
//      if ((k - x) & 1)
//        ans = (ans - f(y - 1, m - 1) + P) % P;
//      else
//        ans = (ans + f(y - 1, m - 1)) % P;
//    }
//    cout << ans << endl;
  }
  return 0;
}
