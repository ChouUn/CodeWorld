//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6228.cpp
 *  Date : 2016年7月22日 下午3:09:27
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef vector<ll> vll;

vll analyse(string s) {
  vll res(10, 0);
  int sgn = 1, coe, exp, status = 0; s += '$';
  for (auto ch : s) {
    if (status == 0)
      if (ch == '-') sgn = -1, status = 0;
      else if (ch == 'x') coe = 1, exp = 1, status = 1;
      else coe = ch - '0', exp = 0, status = 1;
    else if (status == 1)
      if (ch == 'x') exp = 1, status = 1;
      else if (ch == '^') status = 2;
      else if (ch == '$') res[exp] += coe * sgn, status = 3;
      else res[exp] += coe * sgn, status = 0, sgn = (ch == '+' ? 1 : -1);
    else exp = ch - '0', status = 1;
  }
  return res;
}

vll derivative(vll fml) {
  rep(i, 1, 10) fml[i - 1] = fml[i] * i;
  return fml[9] = 0, fml;
}

ll substitute(const vll& fml, int x) {
  ll res = 0;
  per(i, 0, 10) res = res * x + fml[i];
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    string s, t; int x; cin >> s >> t >> x;
    vll p = analyse(s), q = analyse(t);
    ll a, b;
    do {
      a = substitute(p, x), p = derivative(p);
      b = substitute(q, x), q = derivative(q);
    } while (!a && !b);
    if (a && b) {
      ll c = __gcd(a, b); a /= c, b /= c;
      if (b < 0) a = -a, b = -b;
      if (b == 1) cout << a << endl;
      else cout << a << '/' << b << endl;
    }
    else if (a) cout << "INF" << endl;
    else if (b) cout << "0" << endl;
    else assert(false);
  }
  return 0;
}
