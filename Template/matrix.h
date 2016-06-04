// Name : Matrix 矩阵
// Copyright : fateud.com
#ifndef MATRIX_H_
#define MATRIX_H_ 20151229L

#include <vector>
#include <iostream>

namespace csl {
  template <typename T>
  class matrix {
  public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef std::size_t size_type;
    typedef matrix< T > _Self;

    matrix() :
        data(), h(), w() {
    }

    matrix(size_type h, size_type w) :
        data(h * w), h(h), w(w) {
    }

    static _Self identity(size_type n) {
      _Self res(n, n);
      for (size_type i = 0; i < n; ++i)
        res[i][i] = value_type(1);
      return std::move(res);
    }

    inline size_type height() const {
      return h;
    }

    inline size_type width() const {
      return w;
    }

    _Self& operator *=(const _Self& b) {
      _Self c(h, b.w);
      for (size_type i = 0; i < h; ++i) {
        for (size_type k = 0; k < w; ++k) {
          value_type tmp = (*this)[i][k];
          if (!tmp) continue;
          for (size_type j = 0; j < b.w; ++j)
            c[i][j] += tmp * b[k][j];
        }
      }
      return *this = c;
    }

    _Self& operator +=(const _Self& b) {
      for (size_type i = 0, n = height() * width(); i < n; ++i)
        data[i] += b.data[i];
      return *this;
    }

    _Self operator *(const _Self& b) const {
      return _Self(*this) *= b;
    }

    _Self operator +(const _Self& b) const {
      return _Self(*this) += b;
    }

    inline value_type* operator [](size_type x) {
      return data.data() + x * w;
    }

    inline const value_type* operator [](size_type x) const {
      return data.data() + x * w;
    }

    friend std::ostream& operator <<(std::ostream &os, const _Self& a) {
      size_type n = a.height();
      size_type m = a.width();
      for (size_type i = 0; i < n; ++i) {
        for (size_type j = 0; j < m; ++j)
          os << a[i][j] << ' ';
        os << '\n';
      }
      return os;
    }

  private:
    std::vector< value_type > data;
    size_type h, w;
  };
} // namespace csl
#endif /* MATRIX_H_ */
