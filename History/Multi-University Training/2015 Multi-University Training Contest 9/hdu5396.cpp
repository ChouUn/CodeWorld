//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/*
 *  Name : hdu5396.cpp
 *  Date : 2015年8月18日 下午12:34:27
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 110
#define mod 1000000007ll
int a[maxn];
char b[maxn];
bool g[maxn][maxn];
ll f[maxn][maxn];

ll fac[maxn], inv[maxn];
ll com(int n, int k) {
  return fac[n] * inv[k] % mod * inv[n-k] % mod;
}

ll dfs(int l, int r) {
  if (l == r) return a[l];
  if (g[l][r]) return f[l][r];
  ll& ans = f[l][r]; g[l][r] = true;
  for (int i = l + 1; i <= r; i++) {
    ll p = dfs(l, i - 1), q = dfs(i, r);
    int c = i - 1 - l, d = r - i;
    ll x = fac[c], y = fac[d], tmp = 0;
    if (b[i] == '+') tmp = (p * y % mod + q * x % mod) % mod;
    if (b[i] == '-') tmp = (p * y % mod - q * x % mod) % mod, tmp = (tmp + mod) % mod;
    if (b[i] == '*') tmp = (p * q) % mod;
    ans = (ans + tmp * com(c + d, c)) % mod;
  }
  return ans;
}

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, maxn) fac[i] = fac[i-1] * i % mod;
  inv[maxn-1] = csl::pow(1ll, fac[maxn-1], mod-2, mod);
  per(i, 1, maxn) inv[i-1] = inv[i] * i % mod;

  for (int n; scanf("%d", &n) != EOF; ) {
    rep(i, 0, n) scanf("%d", a+i); gets(b);
    rep(i, 1, n) scanf("%c", b+i);
    memset(g, 0x00, sizeof(g));
    printf(i64 "\n", dfs(0, n-1));
  }
  return 0;
}
