//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6295.cpp
 *  Date : 2016年7月7日 上午8:57:04
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
const int M = 31;
int n, a[N];
bool f[N];

void split(int k) {
  rep(i, 0, n) f[i] = (a[i] >> k) & 1;
}

ll calc(ll y) {
  return y * y;
}

void solve_xor() {
  ll ans = 0;
  rep(k, 0, M) {
    split(k);
    int odd = 0, even = 1;
    bool x = 0; ll y = 0;
    rep(i, 0, n) {
      x ^= f[i];
      if (x) odd += 1; else even += 1;
      if (x) y += even; else y += odd;
    }
    y = y * 2;
    rep(i, 0, n) y -= f[i];
    ans += y * (1 << k);
  }
  cout << fixed << setprecision(3) << double(ans) / calc(n) << " ";
}

void solve_and() {
  ll ans = 0;
  rep(k, 0, M) {
    split(k);
    ll x = 0; int y = 0;
    rep(i, 0, n) {
      if (f[i]) ++y;
      else x += calc(y), y = 0;
    }
    if (y) x += calc(y);
    ans += x * (1 << k);
  }
  cout << fixed << setprecision(3) << double(ans) / calc(n) << " ";
}

void solve_or() {
  ll ans = 0;
  rep(k, 0, M) {
    split(k);
    ll x = 0; int y = 0;
    rep(i, 0, n) {
      if (!f[i]) ++y;
      else x += calc(y), y = 0;
    }
    if (y) x += calc(y);
    ans += (calc(n) - x) * (1 << k);
  }
  cout << fixed << setprecision(3) << double(ans) / calc(n) << endl;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> n;
    rep(i, 0, n) cin >> a[i];

    solve_xor();
    solve_and();
    solve_or();
  }
  return 0;
}
