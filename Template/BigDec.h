// Name : BigDec 高精度自然数
// Copyright : fateud.com
#ifndef BIGDEC_H_
#define BIGDEC_H_ 20160318L
#include <cstdint>
#include <cstring>
#include <iomanip>
namespace csl {
  template <typename _Tp, int _Sz>
  class array {
  private:
    _Tp _data[_Sz];
    int _size;
  public:
    array() :
        _size() {
    }
    array(int n, _Tp x = _Tp()) :
        _size(n) {
      while (n > 0)
        _data[--n] = x;
    }
  public:
    inline _Tp* data() {
      return _data;
    }
    inline const _Tp* data() const {
      return _data;
    }
    inline int size() const {
      return _size;
    }
    inline void clear() {
      _size = 0;
    }
    inline _Tp& operator [](int x) {
      return _data[x];
    }
    inline const _Tp& operator [](int x) const {
      return _data[x];
    }
    inline _Tp& at(int x) {
      return _data[x];
    }
    inline void resize(int x) {
      if (x <= _size)
        _size = x;
      else
        while (_size < x)
          _data[_size++] = _Tp();
    }
    inline void push_back(_Tp x) {
      _data[_size++] = x;
    }
    inline void pop_back() {
      --_size;
    }
  };
  // class array

  template <typename _Sequence = csl::array< std::uint32_t, 50 > >
  class BigDec {
  public:
    typedef std::int32_t int32;
    typedef std::uint32_t uint32;
    typedef std::int64_t int64;
    typedef std::uint64_t uint64;
    typedef _Sequence container;
    typedef BigDec< _Sequence > _Self;
    static int32 Bit, Base;
    BigDec() :
        _bits(1, 0) {
    }
    BigDec(int32 value) {
      split(_bits, value);
    }
    BigDec(uint32 value) {
      split(_bits, value);
    }
    BigDec(int64 value) {
      split(_bits, value);
    }
    BigDec(uint64 value) {
      split(_bits, value);
    }
    BigDec(const container& value) :
        _bits(value) {
    }
    BigDec(container&& value) :
        _bits(std::move(value)) {
    }
    explicit BigDec(const char *p) {
      int n = strlen(p);
      _bits.resize((n - 1) / Bit + 1);
      for (int i = n, j = 0, k = 1; i > 0; --i) {
        _bits[j] += (p[i - 1] - '0') * k;
        if ((k *= 10) == Base) k = 1, ++j;
      }
    }
    inline uint32* data() {
      return _bits.data();
    }
    inline const uint32* data() const {
      return _bits.data();
    }
    inline int32 size() const {
      return _bits.size();
    }
    inline _Self& operator +=(const _Self& value) {
      AddSelf(_bits, value._bits);
      return *this;
    }
    inline _Self& operator -=(const _Self& value) {
      SubSelf(_bits, value._bits);
      return *this;
    }
    inline _Self& operator *=(const _Self& value) {
      _bits = Multi(_bits, value._bits);
      return *this;
    }
    inline _Self& operator /=(const _Self& value) {
      container r;
      Divide(_bits, value._bits, r);
      return _bits = std::move(r), *this;
    }
    inline _Self& operator %=(const _Self& value) {
      container r;
      Divide(_bits, value._bits, r);
      return *this;
    }
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
    inline _Self operator %(const _Self& b) const {
      return _Self(*this) %= b;
    }
    inline bool operator ==(const _Self& b) const {
      return Compare(_bits, b._bits) == 0;
    }
    inline bool operator !=(const _Self& b) const {
      return Compare(_bits, b._bits) != 0;
    }
    inline bool operator <=(const _Self& b) const {
      return Compare(_bits, b._bits) <= 0;
    }
    inline bool operator >=(const _Self& b) const {
      return Compare(_bits, b._bits) >= 0;
    }
    inline bool operator <(const _Self& b) const {
      return Compare(_bits, b._bits) < 0;
    }
    inline bool operator >(const _Self& b) const {
      return Compare(_bits, b._bits) > 0;
    }
    inline bool operator !() const {
      return _bits.size() == 1 && _bits[0] == 0;
    }
    friend std::istream& operator >>(std::istream &i, _Self& n) {
      std::string s;
      return i >> s, n = _Self(s.data()), i;
    }
    friend std::ostream& operator <<(std::ostream &o, const _Self& n) {
      const container& b = n._bits;
      for (int i = b.size() - 1; i >= 0; i--)
        o << b[i] << std::setfill('0') << std::setw(Bit);
      return o << std::setfill(' ') << std::setw(0);
    }
  private:
    static void split(container& bits, uint64 value) {
      bits.clear();
      do {
        bits.push_back(value % Base), value /= Base;
      } while (value);
    }
    static void StripLeadingZero(container& bits) {
      int32 l = bits.size();
      while (l > 1 && bits[l - 1] == 0)
        --l;
      bits.resize(l);
    }

    static int Compare(const container& l, const container& r) {
      int32 ll = l.size(), rl = r.size();
      if (ll ^ rl) return (ll < rl) ? -1 : 1;
      for (int i = ll - 1; i >= 0; i--)
        if (l[i] ^ r[i]) return (l[i] < r[i]) ? -1 : 1;
      return 0;
    }

    static void AddSelf(container& l, const container& r) {
      int32 ll = l.size(), rl = r.size(), c = 0;
      if (ll < rl) l.resize(ll = rl);
      for (int32 i = 0; i < ll; ++i) {
        c = c + l[i];
        if (i < rl) c = c + r[i];
        if (c < Base)
          l[i] = c, c = 0;
        else
          l[i] = c - Base, c = 1;
      }
      if (c) l.push_back(c);
    }

    static void SubSelf(container& l, const container& r) {
      int32 ll = l.size(), rl = r.size(), c = 0;
      for (int32 i = 0; i < ll; ++i) {
        c = c + l[i];
        if (i < rl) c = c - r[i];
        if (c < 0)
          l[i] = c + Base, c = -1;
        else
          l[i] = c, c = 0;
      }
      StripLeadingZero(l);
    }

    static container Multi(const container& l, const container& r) {
      int32 ll = l.size(), rl = r.size(), bl = ll + rl;
      container b(bl);
      for (int32 i = 0; i < ll; i++) {
        int64 c = 0;
        for (int32 j = 0; j < rl || c > 0; j++) {
          if (j < rl) c += (int64)l[i] * r[j];
          int32 k = i + j;
          if (k < bl)
            c += b[k];
          else
            b.resize(bl = k + 1);
          b[k] = c % Base, c /= Base;
        }
      }
      return StripLeadingZero(b), std::move(b);
    }

    static void Divide(container& l, const container& r, container& q) {
      if (Compare(l, r) == -1 && (q = container(1, 0), true)) return;
      int32 ll = l.size();
      q.resize(ll);
      container c(1, 0);
      for (int32 i = ll - 1; i >= 0; --i) {
        if (c.size() != 1 || c[0] != 0) {
          c.resize(c.size() + 1);
          for (int32 j = c.size() - 1; j > 0; --j)
            c[j] = c[j - 1];
        }
        c[0] = l[i];
        int32 left = 0, right = Base - 1;
        while (left < right) {
          int32 mid = (left + right + 1) / 2;
          if (Compare(Multi(r, container(1, mid)), c) <= 0)
            left = mid;
          else
            right = mid - 1;
        }
        q[i] = left, SubSelf(c, Multi(r, container(1, left)));
      }
      l = std::move(c), StripLeadingZero(q);
    }
  private:
    container _bits;
  };
  // class BigDec

  template <typename _Sequence> int BigDec< _Sequence >::Bit = 9;
  template <typename _Sequence> int BigDec< _Sequence >::Base = 1000000000;

} // namespace csl

#endif /* BIGDEC_H_ */
