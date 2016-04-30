//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/*
 *  Name : hdu5407.cpp
 *  Date : 2015年8月20日 下午1:06:26
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 1000010
#define mod 1000000007ll

ll f[maxn];
int g[maxn];
int h[maxn];

//@ Main Function
int main() {
  rep(i, 2, maxn) {
    if (g[i]) continue;
    for (ll j = i << 1; j < maxn; j += i) g[j] = i;
    for (ll j = i; j < maxn; j *= i) h[j] = i;
  }

  f[0] = 1;
  rep(i, 1, maxn) f[i] = (h[i] ? h[i] : 1) * f[i-1] % mod;

  int _;
  for (scanf("%d", &_); _; _--) {
	int n; scanf("%d", &n);
	printf(i64 "\n", f[n+1] * csl::inv((ll)n + 1, mod) % mod);
  }
  return 0;
}
