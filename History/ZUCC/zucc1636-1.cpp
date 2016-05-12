//@ Including Header
// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#ifndef CSL_STD_H_
#define CSL_STD_H_ 20151122L
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<pii> vpii;

#define rep(i,a,b) for(auto i=a,i##_n=b;i<i##_n;++i)
#define per(i,a,b) for(auto i=b,i##_n=a;i-->i##_n;)

#endif /* CSL_STD_H_ */

// Name : Mathematical Computation 数学计算
// Copyright : fateud.com

#ifndef CSL_MATH_H_
#define CSL_MATH_H_ 20160313L

#include <cmath>
#include <functional>
#include <vector>

#if !_USE_MATH_DEFINES && !_POSIX_C_SOURCE
#define M_E        2.71828182845904523536     // - e
#define M_LOG2E    1.44269504088896340736     // - log2(e)
#define M_LOG10E   0.434294481903251827651    // - log10(e)
#define M_LN2      0.693147180559945309417    // - ln(2)
#define M_LN10     2.30258509299404568402     // - ln(10)
#define M_PI       3.14159265358979323846     // - pi
#define M_1_PI     0.318309886183790671538    // - 1/pi
#define M_SQRT2    1.41421356237309504880     // - sqrt(2)
#define M_SQRT1_2  0.707106781186547524401    // - 1/sqrt(2)
#endif /* !_USE_MATH_DEFINES && !_POSIX_C_SOURCE */

namespace csl {
  /*
   * greatest common divisor
   */
  template <typename T>
  inline T gcd(T a, T b) {
    for(T c = T(); !!b;)
      c = a % b, a = std::move(b), b = std::move(c);
    return a;
  }
  /*
   * extended Euclidean algorithm
   * solve ax + by = gcd(a,b)
   */
  template <typename T>
  T gcd(const T& a, const T& b, T& x, T& y) {
    if(!b) return x = 1, y = 0, a;
    T r = gcd(b, a % b, y, x);
    return y = y - a / b * x, r;
  }

  /**
   * least common multiple
   */
  template <typename T>
  inline T lcm(const T& a, const T& b) {
    return a / gcd(a, b) * b;
  }

  /**
   * divide and conquer algorithms (with modulo operation)
   */
  template <typename V, typename K, typename M, typename F1, typename F2>
  inline V dnc(V c, V n, K k, M m, const F1& op1, const F2& op2) {
    for(n = op2(n, m); !!k; n = op2(op1(n, n), m), k >>= 1)
      if(k & 1) c = op2(op1(c, n), m);
    return c;
  }

  /**
   * divide and conquer algorithms
   */
  template <typename V, typename K, typename F>
  inline V dnc(V c, V n, K k, const F& op) {
    for(; k; n = op(n, n), k >>= 1)
      if(k & 1) c = op(c, n);
    return c;
  }

  /**
   * return a * b (mod m)
   */
  template <typename V>
  inline V mul(V a, V b, const V m) {
    return dnc(V(), a, b, m, std::plus<V>(), std::modulus<V>());
  }

  /**
   * return c * n ^ k
   */
  template <typename V, typename K>
  inline V pow(V c, V n, const K k) {
    return dnc(c, n, k, std::multiplies<V>());
  }

  /**
   * return c * n ^ k (mod m)
   */
  template <typename V, typename K>
  inline V pow(V c, V n, const K k, V m) {
    return dnc(c, n, k, m, std::multiplies<V>(), std::modulus<V>());
  }

  /**
   * return 1 / x (mod m)
   */
  template <typename V>
  inline V inv(const V& x, const V& m) {
    V p, q;
    return gcd(x, m, p, q), (p % m + m) % m;
  }

  template <typename V>
  inline std::vector<V> divide(V x) {
    std::vector<V> res;
    if (x % 2 == 0) { res.push_back(2); while (x % 2 == 0) x >>= 1; }
    for (V i(3); i * i <= x; i += 2) {
      if (x % i) continue;
      res.push_back(i); while (x % i == 0) x /= i;
    }
    if (x != V(1)) res.push_back(x);
    return res;
  }

  /**
   * return Primitive Root of x about m
   */
  template <typename V>
  inline V root(const V& P) {
    std::vector<V> p = csl::divide(P - 1);
    for (V g = 2; g < P; ++g) {
      bool flag = true;
      for (auto i = p.begin(); i != p.end(); ++i)
        if (csl::pow(V(1), g, (P - 1) / *i, P) == 1) { flag = false; break; }
      if (flag) return g;
    }
    return -1;
  }

} // namespace csl

#endif /* CSL_MATH_H_ */

/**
 *  Name : zucc1636-1.cpp
 *  Date : 2016年4月7日 上午1:32:52
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 20
#define M 1000000
#define P 790660457

ll fac[M+N+1], inv[M+N+1];
int a[N];

ll com(int n, int m) {
  if (m < 0 || m > n) return 0;
  return fac[n] * inv[m] % P * inv[n-m] % P;
}

//@ Main Function
int main() {
  fac[0] = 1;
  rep(i, 1, M+N+1) fac[i] = fac[i-1] * i % P;
  inv[M+N] = csl::pow(ll(1), fac[M+N], P-2, ll(P));
  per(i, 1, M+N+1) inv[i-1] = inv[i] * i % P;
  assert(inv[1] == 1);

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    assert(1 <= n && n <= N);
    assert(1 <= m && m <= M);

    rep(i, 0, n) cin >> a[i];
    ll ans = 0;
    rep(i, 0, 1 << n) {
      int b = 0, c = m;
      rep(k, 0, n) {
        if (~i & (1 << k)) continue;
        ++b, c -= a[k] + 1;
      }
      ll sg = b & 1 ? P - 1: 1;
      ans = (ans + sg * com(c+n-1, n-1)) % P;
    }
    cout << ans << endl;
  }
  return 0;
}
