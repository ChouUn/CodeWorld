// Name : Fast Fourier Transform 快速傅里叶变换
// Copyright : fateud.com

#ifndef NTT_H_
#define NTT_H_ 20160524L

#include <vector>
#ifndef CSL_MATH_H_
#pragma message("need : csl_math.h");
#include <csl_math.h>
#endif

namespace csl {
  template <typename T = long long, typename Seq = std::vector< T > >
  struct ntt {
  public:
    typedef int size_type;
    typedef Seq container;

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
    ntt(T P, T g = T()) :
        P(P), g(g ? g : csl::root(P)) {
    }

    ntt(size_type n) {
      for (P = (1 << n) + 1;; P += 1 << n) {
        bool b = true;
        for (T j = 2; j * j < P; j++)
          if (P % j == 0) {
            b = false;
            break;
          }
        if (b) break;
      }
      for (g = 2;; ++g) {
        T k = g;
        bool b = true;
        for (int j = 0; j < n; k = k * k % P, ++j)
          if (k == 1) {
            b = false;
            break;
          }
        if (b && k == 1) break;
      }
    }

    container operator ()(const container& a, const container& b) const {
      size_type n = StripLeadingZero(a), m = StripLeadingZero(b), d = n + m - 1, s;
      container u(a.data(), a.data() + n), v(b.data(), b.data() + m);
      for (s = 1; s < d; s <<= 1)
        ;
      u.resize(s), v.resize(s);
      T *l = u.data(), *r = v.data();
      trans(l, s), trans(r, s);
      T invs = csl::pow(T(1), T(s), P - 2, P);
      for (int i = 0; i < s; ++i)
        l[i] = l[i] * invs % P * r[i] % P;
      std::reverse(l + 1, l + s), trans(l, s), u.resize(d);
      return u;
    }

    void trans(T a[], int n) const {
      for (int i = 1, x = 0, y = 0; i <= n; i++) {
        if (x > y) std::swap(a[x], a[y]);
        x ^= i & -i, y ^= n / (i & -i) >> 1;
      }
      for (int m = 1; m < n; m += m) {
        T e = csl::pow(T(1), g, ((P - 1) / m) >> 1, P), w = 1;
        for (int x = 0; x < n; w = 1, x += m << 1)
          for (int y = 0; y < m; y++, w = w * e % P) {
            T t = w * a[x + y + m] % P;
            a[x + y + m] = (a[x + y] + P - t) % P;
            a[x + y] = (a[x + y] + t) % P;
          }
      }
    }

    static size_type StripLeadingZero(const container& value) {
      auto l = value.data(), r = value.data() + value.size();
      for (--r; r > l && !*r; --r)
        ;
      return r - l + 1;
    }

  private:
    T P, g;
  };
} // namespace csl
#endif /* NTT_H_ */
