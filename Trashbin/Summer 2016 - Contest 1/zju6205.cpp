//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6205.cpp
 *  Date : 2016年7月5日 上午10:19:23
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef vector<ll> vll;
string a, b; int x;

vll split(char *s) {
  vll res(10, 0);
  for (char *t; *s; s = t) {
    for (t = s + 1; *t && *t != '-' && *t != '+'; ++t);
    int p, q;
    if (s[3] == '^') p = s[1] - '0', q = s[4] - '0';
    else if (s[2] == '^') p = 1, q = s[3] - '0';
    else if (s[2] == 'x') p = s[1] - '0', q = 1;
    else if (s[1] == 'x') p = 1, q = 1;
    else if (t - s == 2) p = s[1] - '0', q = 0;
    else assert(false);
    if (s[0] == '-') p = -p;
    res[q] += p;
  }
  return res;
}

ll func(const vll& p) {
  ll res = 0, tmp = 1;
  rep(i, 0, 10) res += p[i] * tmp, tmp *= x;
  return res;
}

void solve(vll& p, vll& q) {
  ll x = func(p), y = func(q);
  if (x == 0 && y != 0) cout << 0 << endl;
  else if (x != 0 && y == 0) cout << "INF" << endl;
  else if (x != 0 && y != 0) {
    ll z = __gcd(x, y);
    x /= z, y /= z;
    if (y < 0) x = -x, y = -y;
    if (y == 1) cout << x << endl;
    else cout << x << '/' << y << endl;
  }
  else {
    rep(i, 1, 10) p[i - 1] = p[i] * i, p[i] = 0;
    rep(i, 1, 10) q[i - 1] = q[i] * i, q[i] = 0;
    solve(p, q);
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    cin >> a >> b >> x;
    if (a[0] != '-' && a[0] != '+') a = "+" + a;
    if (b[0] != '-' && b[0] != '+') b = "+" + b;
    a = a + '\0', b = b + '\0';

    vll p = split((char*)a.c_str());
    vll q = split((char*)b.c_str());
    solve(p, q);
  }
  return 0;
}
