// Name : ModInt 自取余整型
// Copyright : fateud.com
#ifndef MODINT_H_
#define MODINT_H_ 20160318L
#include <iostream>
#ifndef CSL_MATH_H_
#pragma message("need : csl_math.h")
#include <csl_math.h>
#endif
namespace csl {
  template <typename T = std::uint64_t>
  class ModInt {
  public:
    typedef ModInt< T > _Self;
    static T M;
  public:
    ModInt() :
        x() {
    }
    ModInt(T y) :
        x(y % M) {
      if (x < 0) x = x + M;
    }
  public:
    inline _Self operator +(const _Self& b) const {
      return _Self(*this) += b;
    }
    inline _Self operator -(const _Self& b) const {
      return _Self(*this) -= b;
    }
    inline _Self operator *(const _Self& b) const {
      return _Self(*this) *= b;
    }
    inline _Self operator /(const _Self& b) const {
      return _Self(*this) /= b;
    }
    inline _Self& operator +=(_Self b) {
      if ((x += b.x) >= M) x -= M;
      return *this;
    }
    inline _Self& operator -=(_Self b) {
      if ((x += M - b.x) >= M) x -= M;
      return *this;
    }
    inline _Self& operator *=(_Self b) {
      x = x * b.x % M;
      return *this;
    }
    inline _Self& operator /=(_Self b) {
      x = x * csl::inv(b.x, M) % M;
      return *this;
    }
    inline friend bool operator <(const _Self& a, const _Self& b) {
      return a.x < b.x;
    }
    inline friend bool operator >(const _Self& a, const _Self& b) {
      return a.x > b.x;
    }
    inline friend bool operator <=(const _Self& a, const _Self& b) {
      return a.x <= b.x;
    }
    inline friend bool operator >=(const _Self& a, const _Self& b) {
      return a.x >= b.x;
    }
    inline friend bool operator !=(const _Self& a, const _Self& b) {
      return a.x != b.x;
    }
    inline friend bool operator ==(const _Self& a, const _Self& b) {
      return a.x == b.x;
    }
    inline bool operator !() const {
      return x == 0;
    }
    inline T& operator *() {
      return x;
    }
    inline const T& operator *() const {
      return x;
    }
    inline friend std::ostream& operator <<(std::ostream& os, const _Self& value) {
      return os << value.x;
    }
    inline friend std::istream& operator >>(std::istream& is, const _Self& value) {
      return is >> value.x;
    }
  private:
    T x;
  };
  // class ModInt
  template <typename T> T ModInt< T >::M = 1000000007;
} // namespace csl
#endif /* MODINT_H_ */
