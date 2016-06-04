// Name : Fast Fourier Transform 快速傅里叶变换
// Copyright : fateud.com
#ifndef FFT_H_
#define FFT_H_ 20160426L

#include <vector>
#include <complex>

#ifndef CSL_MATH_H_
#pragma message("need : csl_math.h");
#include <csl_math.h>
#endif

namespace csl {
  template <typename _Tp = double>
  class fft {
  public:
    typedef _Tp value_type;
    typedef std::complex< value_type > node;
    typedef std::size_t size_type;
    typedef std::vector< value_type > container;

    container operator ()(const container& u, const container& v) const {
      size_type n = StripLeadingZero(u), m = StripLeadingZero(v);
      size_type d = n + m - 1, s = 1;
      while (s < d)
        s <<= 1;
      std::vector< node > w(s);
      for (size_type i = 0; i < n; ++i)
        w[i].real(u[i]);
      for (size_type i = 0; i < m; ++i)
        w[i].imag(v[i]);

      this->operator()(w, 0);
      w[0] = w[0].real() * w[0].imag();
      for (size_type i = 1, j = s - 1; i <= j; ++i, --j) {
        _Tp a = w[i].real() / 2, b = w[i].imag() / 2;
        _Tp c = w[j].real() / 2, d = w[j].imag() / 2;
        node ui(a + c, b - d), vi(b + d, c - a);
        node uj(c + a, d - b), vj(d + b, a - c);
        w[i] = ui * vi, w[j] = uj * vj;
      }
      this->operator()(w, 1);

      container res(d);
      for (size_type i = 0; i < d; ++i)
        res[i] = w[i].real();
      return res.resize(StripLeadingZero(res)), std::move(res);
    }

    void operator ()(std::vector< node >& v, bool inv) const {
      int n = v.size();
      node* a = v.data();
      for (int i = 1, j, t, k; i < n; ++i) {
        for (j = 0, t = i, k = n >> 1; k; k >>= 1, t >>= 1)
          j = (j << 1) | (t & 1);
        if (i < j) swap(a[i], a[j]);
      }
      for (int s = 2, ds = 1; s <= n; ds = s, s <<= 1) {
        _Tp wo = (inv ? -1 : 1) * 2 * M_PI / s;
        node wn(std::cos(wo), std::sin(wo)), w(1, 0), t;
        for (int k = 0; k < ds; ++k, w = w * wn)
          for (int i = k; i < n; i += s)
            a[i + ds] = a[i] - (t = w * a[i + ds]), a[i] += t;
      }
      if (inv) for (size_type i = 0; i < n; ++i)
        a[i] /= n;
    }

    static size_type StripLeadingZero(const container& value) {
      size_type n = value.size();
      while (n > 1 && value[n - 1] < .5)
        --n;
      return n;
    }
  };
} // namespace csl
#endif /* FFT_H_ */
