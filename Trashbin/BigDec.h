// Name : BigDec 高精度自然数
// Copyright : fateud.com

#ifndef BIGDEC_H_
#define BIGDEC_H_ 20160313L

#include <cstring>
#include <vector>
#include <iostream>
#include <iomanip>

namespace csl {
#define long long long
  class BigDec {
  public:
    typedef std::uint32_t uint;
    typedef std::uint64_t ulong;
    typedef std::vector< uint > container;

    typedef BigDec _Self;

  public:
    static const int kcBit = 9;
    static const int kcBase = 1000000000;

  private:
    container _bits;

  public:
    BigDec() : _bits(1, 0) {}
    BigDec(int value) { split(_bits, (ulong)value); }
    BigDec(uint value) { split(_bits, (ulong)value); }
    BigDec(long value) { split(_bits, (ulong)value); }
    BigDec(ulong value) { split(_bits, value); }
    BigDec(const container& value) : _bits(value) {}
    BigDec(container&& value) : _bits(std::move(value)) {}

    explicit BigDec(const char *p) {
      int n = strlen(p), m = (n - 1) / kcBit + 1;
      _bits.resize(m);
      for (int i = n, j = 0, k = 1; i > 0; --i) {
        _bits[j] += (p[i - 1] - '0') * k;
        if ((k *= 10) == kcBase) k = 1, ++j;
      }
    }

  public:
    inline uint* data()
    { return _bits.data(); }
    inline const uint* data() const
    { return _bits.data(); }
    inline uint size() const
    { return _bits.size(); }

  public:
    _Self& operator +=(const _Self& right) {
      int ll = size(), rl = right.size(), i = 0, c = 0;
      if (rl > ll) _bits.resize(ll = rl, 0);
      uint* l = data(); const uint* r = right.data();
      for (; i < ll || i < rl; ++i) {
        if (i < ll) c += l[i];
        if (i < rl) c += r[i];
        if (c >= kcBase) l[i] = c - kcBase, c = 1;
        else l[i] = c, c = 0;
      }
      if (c) _bits.push_back(c); return *this;
    }

    _Self& operator -=(const _Self& right) {
      int ll = size(), rl = right.size(), i = 0, c = 0;
      uint* l = data(); const uint* r = right.data();
      for (; i < ll; ++i) {
        c += l[i];
        if (i < rl) c -= r[i];
        if (c < 0) l[i] = c + kcBase, c = -1;
        else l[i] = c, c = 0;
      }
      StripLeadingZero(_bits); return *this;
    }

    _Self& operator *=(const _Self& right) {
      int ll = size(), rl = right.size();
      uint* l = data(); const uint* r = right.data();
      container res(ll + rl); int resl = res.size();
      for (int i = 0; i < ll; i++) {
        long c = 0;
        for (int j = 0; j < rl || c > 0; j++) {
          if (j < rl) c += (long)l[i] * r[j];
          int k = i + j;
          if (k < resl) c += res[k];
          else res.resize(resl = k + 1);
          res[k] = c % kcBase, c /= kcBase;
        }
      }
      StripLeadingZero(res), _bits = std::move(res); return *this;
    }

    _Self& operator /=(const _Self& b) {
      _Self q; Divide(*this, b, q);
      return *this = std::move(q);
    }

    _Self& operator %=(const _Self& b) {
      _Self q; Divide(*this, b, q);
      return *this;
    }

    inline _Self operator +(const _Self& b) const
    { return _Self(*this) += b; }
    inline _Self operator -(const _Self& b) const
    { return _Self(*this) -= b; }
    inline _Self operator *(const _Self& b) const
    { return _Self(*this) *= b; }
    inline _Self operator /(const _Self& b) const
    { return _Self(*this) /= b; }
    inline _Self operator %(const _Self& b) const
    { return _Self(*this) %= b; }
    inline bool operator ==(const _Self& b) const
    { return Compare(*this, b) == 0; }
    inline bool operator !=(const _Self& b) const
    { return Compare(*this, b) != 0; }
    inline bool operator <=(const _Self& b) const
    { return Compare(*this, b) <= 0; }
    inline bool operator >=(const _Self& b) const
    { return Compare(*this, b) >= 0; }
    inline bool operator <(const _Self& b) const
    { return Compare(*this, b) < 0; }
    inline bool operator >(const _Self& b) const
    { return Compare(*this, b) > 0; }
    inline bool operator !() const
    { return size() == 1 && data()[0] == 0; }

    friend std::istream& operator >>(std::istream &i, _Self& n)
    { std::string s; return i >> s, n = _Self(s.data()), i; }

    friend std::ostream& operator <<(std::ostream &o, const _Self& n) {
      o << n.data()[n.size() - 1];
      for (int i = n.size() - 2; i >= 0; i--)
        o << std::setfill('0') << std::setw(kcBit) << n.data()[i];
      return o << std::setfill(' ');
    }

  private:
    static void split(container& bits, ulong value) {
      bits.clear();
      do { bits.push_back(value % kcBase), value /= kcBase; } while (value);
    }

    static int Compare(const _Self& left, const _Self& right) {
      int ll = left.size(), rl = right.size();
      const uint *l = left.data(), *r = right.data();
      if (ll ^ rl) return (ll < rl) ? -1 : 1;
      for (int i = ll - 1; i >= 0; i--)
        if (l[i] ^ r[i]) return (l[i] < r[i]) ? -1 : 1;
      return 0;
    }

    static void StripLeadingZero(container& bits) {
      const uint* data = bits.data(); uint len = bits.size();
      while (len > 1 && data[len - 1] == 0) --len;
      bits.resize(len);
    }

    static void Divide(_Self& l, const _Self& r, _Self& q) {
      if (Compare(l, r) == -1 && (q = 0, true)) return;
      q._bits.resize(l.size());
      _Self c;
      for (int i = l.size() - 1; i >= 0; --i) {
        if (!!c) {
          c._bits.resize(c.size() + 1);
          for (int j = c.size() - 1; j > 0; --j)
            c.data()[j] = c.data()[j - 1];
        }
        c.data()[0] = l.data()[i];
        int left = 0, right = kcBase - 1;
        while (left < right) {
          int mid = (left + right + 1) / 2;
          if (Compare(r * mid, c) <= 0) left = mid;
          else right = mid - 1;
        }
        q.data()[i] = left, c = c - r * left;
      }
      l = std::move(c), StripLeadingZero(q._bits);
    }
  };
  // class BigDec
#undef long
} // namespace csl

#endif /* BIGDEC_H_ */
