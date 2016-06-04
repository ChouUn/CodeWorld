// Name : Fast Fourier Transform 快速傅里叶变换
// Copyright : fateud.com
#ifndef FOURIER_H_
#define FOURIER_H_ 20151229L
#include <vector>
#ifndef CSL_MATH_H_
#pragma message("need : csl_math.h");
#include <csl_math.h>
#endif
namespace csl {
  template <typename _Tp>
  struct fourier {
  public:
    typedef _Tp value_type;
    typedef std::size_t size_type;
    typedef std::vector< value_type > container;

    /**
     * g ^ (P - 1) = 1 (mod P)
     * P            g
     * 786433       10
     * 880803841    26
     * 985661441    3
     * 998244353    3
     * 1004535809   3
     * 1811939329   13
     * 2113929217   5
     * 2130706433   3
     */
    fourier(size_type n, value_type P, value_type g) :
        P(P), g(g) {
      for (K = 1; K < (n << 1); K <<= 1)
        ;
      w[0].resize(K + 1), w[1].resize(K + 1);
      w[0][0] = w[0][K] = w[1][0] = w[1][K] = value_type(1);
      value_type G = csl::pow(value_type(1), g, (P - 1) / K);
      for (int i = 1; i < K; ++i)
        w[0][i] = w[0][i - 1] * G % P;
      for (int i = 0; i <= K; ++i)
        w[1][i] = w[0][K - i];
    }

    /**
     * Functor of Convolution
     */
    container operator ()(const container& a, const container& b) const {
      container u(a), v(b);
      size_type n = u.size(), m = v.size(), d = n + m - 1, s;
      for (s = 1; s < d; s <<= 1)
        ;
      u.resize(s), trans(u, false);
      v.resize(s), trans(v, false);
      value_type is = inv((value_type)s, P);
      for (int i = 0; i < s; ++i)
        u[i] = u[i] * is % P * v[i] % P;
      trans(u, true), u.resize(d);
      return u;
    }

  private:
    container w[2];
    size_type K;
    value_type P;
    value_type g;

    void trans(container& x, bool v) const {
      size_type k = x.size();
      for (size_type i = 0, j = 0; i < k; ++i) {
        if (i > j) std::swap(x[i], x[j]);
        for (size_type l = k >> 1; (j ^= l) < l; l >>= 1)
          ;
      }
      for (size_type i = 2; i <= k; i <<= 1)
        for (size_type j = 0; j < k; j += i)
          for (size_type l = 0; l < (i >> 1); ++l) {
            value_type t = x[j + l + (i >> 1)] * w[v][K / i * l] % P;
            x[j + l + (i >> 1)] = (P - t + x[j + l]) % P;
            x[j + l] = (x[j + l] + t) % P;
          }
    }
  };
} // namespace csl
#endif /* FOURIER_H_ */
