// Name : Mathematical Computation 数学计算
// Copyright : fateud.com

#ifndef CSL_MATH_H_
#define CSL_MATH_H_ 20160313L

#include <cmath>
#include <functional>
#include <vector>

#ifndef M_PI
#define M_E        2.71828182845904523536     // - e
#define M_LOG2E    1.44269504088896340736     // - log2(e)
#define M_LOG10E   0.434294481903251827651    // - log10(e)
#define M_LN2      0.693147180559945309417    // - ln(2)
#define M_LN10     2.30258509299404568402     // - ln(10)
#define M_PI       3.14159265358979323846     // - pi
#define M_1_PI     0.318309886183790671538    // - 1/pi
#define M_SQRT2    1.41421356237309504880     // - sqrt(2)
#define M_SQRT1_2  0.707106781186547524401    // - 1/sqrt(2)
#endif /* M_PI */

namespace csl {
  /*
   * greatest common divisor
   */
  template <typename T>
  inline T gcd(T a, T b) {
    for (T c = T(); !!b;)
      c = a % b, a = std::move(b), b = std::move(c);
    return a;
  }
  /*
   * extended Euclidean algorithm
   * solve ax + by = gcd(a,b)
   */
  template <typename T>
  T gcd(const T& a, const T& b, T& x, T& y) {
    if (!b) return x = 1, y = 0, a;
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
    for (n = op2(n, m); !!k; n = op2(op1(n, n), m), k >>= 1)
      if (k & 1) c = op2(op1(c, n), m);
    return c;
  }

  /**
   * divide and conquer algorithms
   */
  template <typename V, typename K, typename F>
  inline V dnc(V c, V n, K k, const F& op) {
    for (; k; n = op(n, n), k >>= 1)
      if (k & 1) c = op(c, n);
    return c;
  }

  /**
   * return a * b (mod m)
   */
  template <typename V>
  inline V mul(V a, V b, const V m) {
    return dnc(V(), a, b, m, std::plus< V >(), std::modulus< V >());
  }

  /**
   * return c * n ^ k
   */
  template <typename V, typename K>
  inline V pow(V c, V n, const K k) {
    return dnc(c, n, k, std::multiplies< V >());
  }

  /**
   * return c * n ^ k (mod m)
   */
  template <typename V, typename K>
  inline V pow(V c, V n, const K k, V m) {
    return dnc(c, n, k, m, std::multiplies< V >(), std::modulus< V >());
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
  inline std::vector< V > divide(V x) {
    std::vector< V > res;
    if (x % 2 == 0) {
      res.push_back(2);
      while (x % 2 == 0)
        x >>= 1;
    }
    for (V i(3); i * i <= x; i += 2) {
      if (x % i) continue;
      res.push_back(i);
      while (x % i == 0)
        x /= i;
    }
    if (x != V(1)) res.push_back(x);
    return res;
  }

  /**
   * return Primitive Root of x about m
   */
  template <typename V>
  inline V root(const V& P) {
    std::vector< V > p = csl::divide(P - 1);
    for (V g = 2; g < P; ++g) {
      bool flag = true;
      for (auto i = p.begin(); i != p.end(); ++i)
        if (csl::pow(V(1), g, (P - 1) / *i, P) == 1) {
          flag = false;
          break;
        }
      if (flag) return g;
    }
    return -1;
  }

} // namespace csl

#endif /* CSL_MATH_H_ */
