//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : hdu5184.cpp
 *  Date : 2015年11月24日 上午12:19:05
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 1000010
#define mod 1000000007

ll fac[maxn], inv[maxn];

bool valid(char *s, int &l, int &r) {
  for(int i = 0; s[i]; i++) {
    if(s[i] == '(') l--;
    if(s[i] == ')') r--;
    if(l > r) return false;
    if(l < 0) return false;
  }
  return true;
}

inline ll com(size_t n, size_t m) {
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int n;
char s[maxn];

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, maxn) fac[i] = fac[i - 1] * i % mod;
  inv[maxn - 1] = csl::inv(fac[maxn - 1], (ll)mod);
  per(i, 1, maxn) inv[i - 1] = inv[i] * i % mod;

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(; cin >> n >> s; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    int l = n >> 1, r = n >> 1;
    ll ans = 0;
    if(n & 1) ans = 0;
    else if(!valid(s, l, r)) ans = 0;
    else if(!l) ans = 1;
    else ans = (com(l + r, l) - com(l + r, l - 1) + mod) % mod;
    cout << ans << endl;
  }
  return 0;
}
