// Name : BigInt
// Copyright : fateud.com

#ifndef BIGINT_H_
#define BIGINT_H_ 20160305L

#include <vector>
#include <climits>
#include <iostream>

namespace csl {
  class BigInt {
  public:
    typedef unsigned int uint;
    typedef unsigned long long ulong;
    typedef std::vector< uint > container;
    typedef BigInt _Self;

  private:
    static const int kcbitUint = 32;
    static const int kcbitUlong = 64;
    static const int knMaskHighBit = INT_MIN;
    static const uint kuMaskHighBit = (uint)INT_MIN;
    static const int MultiplyThreshold = 32;
    static const int AllocationThreshold = 256;

  private:
    int _sign;
    container _bits;

  public:
    BigInt() : _sign(0), _bits() {}

    BigInt(int value) {
      if (value == 0) _sign = 0, _bits = container();
      else if (value > 0) _sign = +1, _bits = container(1, (uint)value);
      else _sign = -1, _bits = container(1, (uint)(-value));
    }

    BigInt(uint value) :
      _sign(+1), _bits(1, value) {
    }

    BigInt(long long value) {
      if (INT_MIN <= value && value <= INT_MAX) *this = _Self((int)value);
      else {
        ulong x = 0;
        if (value < 0) _sign = -1, x = (ulong)(-value); else _sign = +1, x = (ulong)value;
        if (x <= UINT_MAX) _bits = container(1, (uint)x);
        else _bits.resize(2), _bits[0] = (uint)x, _bits[1] = (uint)(x >> kcbitUint);
      }
    }

    BigInt(ulong value) {
      if (value <= UINT_MAX) *this = _Self((uint)value);
      else _sign = +1, _bits.resize(2),
          _bits[0] = (uint)value, _bits[1] = (uint)(value >> kcbitUint);
    }

    BigInt(int n, const container& rgu) :
      _sign(n), _bits(rgu) {
    }

    BigInt(const container& value, bool negative) {
      StripLeadingZero(_bits = value);
      if (_bits.size() == 0) *this = _Self(0); else _sign = negative ? -1 : +1;
    }

    BigInt(const std::string& s) {
      int n = s.size(), cur = 0;
      if (s[cur] == '0') _sign = 0, ++cur;
      else if (s[cur] == '-') _sign = -1, ++cur;
      else _sign = 1;

      container base = container(1, 10);
      _bits = container(1, 0);
      while (cur < n)
      {
        uint d = s[cur++] - '0';
        _bits = Multiply(_bits, base);
        if (d) _bits = Add(_bits, container(1, d));
        StripLeadingZero(_bits);
      }
    }

  public:
    inline int compareTo(const _Self& other) const {
      if (_sign != other._sign) return _sign < other._sign ? -1 : +1;
      if (_sign == 0) return 0;
      int cmp = Compare(_bits, other._bits);
      return _sign > 0 ? cmp : -cmp;
    }

    inline bool equals(const _Self& other) const {
      if (_sign != other._sign) return false;
      if (_bits == other._bits) return true;
      return false;
    }

    inline std::string to_string() const {
      return FormatBigInt(*this);
    }

    inline _Self abs() const {
      return _Self(-_sign, _bits);
    }

    inline friend std::istream& operator >>(std::istream& is, _Self& value) {
      std::string s; is >> s; value = _Self(s); return is;
    }

    inline friend std::ostream& operator <<(std::ostream& os, const _Self& value) {
      return os << value.to_string();
    }

    friend _Self operator <<(const _Self& value, int shift) {
      if (shift == 0) return value;
      else if (shift == INT_MIN) return (value >> INT_MAX) >> 1;
      else if (shift < 0) return value >> -shift;
      int ds = shift / kcbitUint, ss = shift - (ds * kcbitUint);
      container xd; int xl; bool negx = GetPartsForBitManipulation(value, xd, xl);
      int zl = xl + ds + 1;
      container zd = container(zl);
      if (ss == 0) for (int i = 0; i < xl; i++) zd[i + ds] = xd[i];
      else {
        int carryShift = kcbitUint - ss, i;
        uint carry = 0, rot;
        for (i = 0; i < xl; i++)
          rot = xd[i], zd[i + ds] = rot << ss | carry, carry = rot >> carryShift;
        zd[i + ds] = carry;
      }
      return _Self(zd, negx);
    }

    friend _Self operator >>(const _Self& value, int shift) {
      if (shift == 0) return value;
      else if (shift == INT_MIN) return ((value << INT_MAX) << 1);
      else if (shift < 0) return value << -shift;
      int ds = shift / kcbitUint, ss = shift - (ds * kcbitUint);
      container xd; int xl; bool negx = GetPartsForBitManipulation(value, xd, xl);
      if (negx) {
        if (shift >= (kcbitUint * xl)) return _Self(-1LL);
        xd.resize(xl), DangerousMakeTwosComplement(xd);
      }
      int zl = xl - ds; if (zl < 0) zl = 0;
      container zd = container(zl);
      if (ss == 0) for (int i = xl - 1; i >= ds; i--)
        zd[i - ds] = xd[i];
      else {
        int carryShift = kcbitUint - ss;
        uint carry = 0, rot;
        for (int i = xl - 1; i >= ds; i--) {
          rot = xd[i];
          zd[i - ds] = (rot >> ss) | ((negx && i == xl - 1) ? (0xFFFFFFFF << carryShift) : carry);
          carry = (rot << carryShift);
        }
      }
      if (negx) DangerousMakeTwosComplement(zd); // mutates zd
      return _Self(zd, negx);
    }

    inline _Self operator +() const {
      return _Self(this->_sign, this->_bits);
    }

    inline _Self operator -() const {
      return _Self(-this->_sign, this->_bits);
    }

    inline bool operator !() const {
      return _sign == 0;
    }


    friend _Self operator +(const _Self& left, const _Self& right) {
      bool tl = (left._sign == 0), tr = (right._sign == 0);
      if (tl) return tr ? _Self(0) : right;
      else if (tr) return left;
      if ((left._sign < 0) != (right._sign < 0)) return Subtract(left._bits, left._sign,
        right._bits, -right._sign);
      return Add(left._bits, left._sign, right._bits, right._sign);
    }

    friend _Self operator -(const _Self& left, const _Self& right) {
      bool tl = (left._sign == 0), tr = (right._sign == 0);
      if (tl) return tr ? _Self(0) : right.operator -();
      else if (tr) return left;
      if ((left._sign < 0) != (right._sign < 0)) return Add(left._bits, left._sign, right._bits,
        -right._sign);
      return Subtract(left._bits, left._sign, right._bits, right._sign);
    }

    inline friend _Self operator *(const _Self& left, const _Self& right) {
      if ((left._sign == 0) || (right._sign == 0)) return _Self(0);
      if (left._bits.size() < right._bits.size())
        return _Self(Multiply(right._bits, left._bits), (left._sign < 0) ^ (right._sign < 0));
      else return _Self(Multiply(left._bits, right._bits), (left._sign < 0) ^ (right._sign < 0));
    }

    inline friend _Self operator /(const _Self& dividend, const _Self& divisor) {
      if (dividend._sign == 0) return dividend;
      if (dividend._bits.size() < divisor._bits.size()) return _Self(0);
      else return _Self(Divide(dividend._bits, divisor._bits),
        (dividend._sign < 0) ^ (divisor._sign < 0));
    }

    inline friend _Self operator %(const _Self& dividend, const _Self& divisor) {
      if (dividend._sign == 0) return dividend;
      if (dividend._bits.size() < divisor._bits.size()) return dividend;
      else return _Self(Remainder(dividend._bits, divisor._bits), dividend._sign < 0);
    }

    inline friend bool operator <(const _Self& left, const _Self& right) {
      return left.compareTo(right) < 0;
    }
    inline friend bool operator <=(const _Self& left, const _Self& right) {
      return left.compareTo(right) <= 0;
    }
    inline friend bool operator >(const _Self& left, const _Self& right) {
      return left.compareTo(right) > 0;
    }
    inline friend bool operator >=(const _Self& left, const _Self& right) {
      return left.compareTo(right) >= 0;
    }
    inline friend bool operator ==(const _Self& left, const _Self& right) {
      return left.equals(right);
    }
    inline friend bool operator !=(const _Self& left, const _Self& right) {
      return !left.equals(right);
    }

  private:
    static void StripLeadingZero(container& bits) {
      const uint* b = bits.data(); uint len;
      for (len = bits.size(); len > 0 && b[len - 1] == 0; --len);
      if (len != bits.size()) bits.resize(len);
    }

    inline static bool GetPartsForBitManipulation(const _Self& x, container& xd, int& xl) {
      if (x._bits.empty()) xd.assign(1, (x._sign < 0) ? (uint)-x._sign : (uint)x._sign);
      else xd = x._bits;
      xl = (x._bits.empty() ? 1 : x._bits.size());
      return x._sign < 0;
    }

    static void DangerousMakeTwosComplement(container& d) {
      if (!d.empty() && d.size() > 0) {
        d[0] = ~d[0] + 1;
        uint i = 1;
        for (; d[i - 1] == 0 && i < d.size(); i++) d[i] = ~d[i] + 1;
        for (; i < d.size(); i++) d[i] = ~d[i];
      }
    }

    static int Compare(const container& left, const container& right) {
      int llen = left.size(), rlen = right.size();
      if (llen < rlen) return -1;
      if (llen > rlen) return 1;
      for (int i = llen - 1; i >= 0; i--) {
        if (left[i] < right[i]) return -1;
        if (left[i] > right[i]) return 1;
      }
      return 0;
    }

    inline static _Self Add(const container& lb, int ls, const container& rb, int rs) {
      return (lb.size() < rb.size()) ? _Self(Add(rb, lb), ls < 0) : _Self(Add(lb, rb), ls < 0);
    }

    inline static container Add(const container& left, const container& right) {
      container bits = container(left.size() + 1);
      Add(left.data(), left.size(), right.data(), right.size(), bits.data(), bits.size());
      return bits;
    }

    static void Add(const uint* left, int llen, const uint* right, int rlen, uint* bits, int blen) {
      int i = 0;
      long long carry = 0LL, d;
      for (; i < rlen; i++) d = (left[i] + carry) + right[i], bits[i] = (uint)d, carry = d >> 32;
      for (; i < llen; i++) d = left[i] + carry, bits[i] = (uint)d, carry = d >> 32;
      bits[i] = (uint)carry;
    }

    static void AddSelf(uint* l, int llen, uint* r, int rlen) {
      int i = 0;
      long long carry = 0LL, d;
      for (; i < rlen; i++) d = (l[i] + carry) + r[i], l[i] = (uint)d, carry = d >> 32;
      for (; carry != 0 && i < llen; i++) d = l[i] + carry, l[i] = (uint)d, carry = d >> 32;
    }

    inline static _Self Subtract(const container& lb, int ls, const container& rb, int rs) {
      return (Compare(lb, rb) < 0) ?
          _Self(Subtract(rb, lb), ls >= 0) : _Self(Subtract(lb, rb), ls < 0);
    }

    inline static container Subtract(const container& left, const container& right) {
      container bits = container(left.size());
      Subtract(left.data(), left.size(), right.data(), right.size(), bits.data(), bits.size());
      return bits;
    }

    static void Subtract(const uint* l, int llen, const uint* r, int rlen, uint* b, int blen) {
      int i = 0;
      long long carry = 0LL, d;
      for (; i < rlen; i++) d = (l[i] + carry) - r[i], b[i] = (uint)d, carry = d >> 32;
      for (; i < llen; i++) d = l[i] + carry, b[i] = (uint)d, carry = d >> 32;
    }

    inline static container Multiply(const container& left, const container& right) {
      container bits = container(left.size() + right.size());
      Multiply(left.data(), left.size(), right.data(), right.size(), bits.data(), bits.size());
      return bits;
    }

    static void Multiply(const uint* l, int llen, const uint* r, int rlen, uint* b, int blen) {
      if (rlen < MultiplyThreshold) {
        for (int i = 0; i < rlen; i++) {
          ulong carry = 0ULL, d;
          for (int j = 0; j < llen; j++)
            d = b[i + j] + carry + (ulong)l[j] * r[i], b[i + j] = (uint)d, carry = d >> 32;
          b[i + llen] = (uint)carry;
        }
      } else {
        int n = rlen >> 1, n2 = n << 1, lllen = n, lhlen = llen - n;
        int rllen = n, rhlen = rlen - n, bllen = n2, bhlen = blen - n2;
        const uint *ll = l, *lh = l + n, *rl = r, *rh = r + n;
        uint *bl = b, *bh = b + n2;
        Multiply(ll, lllen, rl, rllen, bl, bllen);
        Multiply(lh, lhlen, rh, rhlen, bh, bhlen);
        int lflen = lhlen + 1, rflen = rhlen + 1, clen = lflen + rflen;
        if (clen < AllocationThreshold) {
          uint *lf = new uint[lflen], *rf = new uint[rflen], *c = new uint[clen];
          Add(lh, lhlen, ll, lllen, lf, lflen);
          Add(rh, rhlen, rl, rllen, rf, rflen);
          Multiply(lf, lflen, rf, rflen, c, clen);
          SubtractCore(bh, bhlen, bl, bllen, c, clen);
          AddSelf(b + n, blen - n, c, clen);
        } else {
          uint *lf = new uint[lflen], *rf = new uint[rflen], *c = new uint[clen];
          Add(lh, lhlen, ll, lllen, lf, lflen);
          Add(rh, rhlen, rl, rllen, rf, rflen);
          Multiply(lf, lflen, rf, rflen, c, clen);
          SubtractCore(bh, bhlen, bl, bllen, c, clen);
          AddSelf(b + n, blen - n, c, clen);
        }
      }
    }

    static void SubtractCore(const uint* l, int llen, const uint* r, int rlen, uint* c, int clen) {
      int i = 0; long long carry = 0LL, d;
      for (; i < rlen; i++) d = (c[i] + carry) - l[i] - r[i], c[i] = (uint)d, carry = d >> 32;
      for (; i < llen; i++) d = (c[i] + carry) - l[i], c[i] = (uint)d, carry = d >> 32;
      for (; carry != 0 && i < clen; i++) d = c[i] + carry, c[i] = (uint)d, carry = d >> 32;
    }

    inline static container Divide(const container& left, const container& right) {
      container local = left, bits = container(left.size() - right.size() + 1);
      Divide(local.data(), local.size(), right.data(), right.size(), bits.data(), bits.size());
      return bits;
    }

    inline static container Remainder(const container& left, const container& right) {
      container local = left;
      Divide(local.data(), local.size(), right.data(), right.size(), 0, 0);
      return local;
    }

    static void Divide(uint* l, int llen, const uint* r, int rlen, uint* b, int blen) {
      uint divHi = r[rlen - 1], divLo = rlen > 1 ? r[rlen - 2] : 0;
      int shift = LeadingZeros(divHi), backShift = 32 - shift;
      if (shift > 0) {
        uint divNx = rlen > 2 ? r[rlen - 3] : 0;
        divHi = (divHi << shift) | (divLo >> backShift);
        divLo = (divLo << shift) | (divNx >> backShift);
      }
      for (int i = llen; i >= rlen; i--) {
        int n = i - rlen; uint t = i < llen ? l[i] : 0;
        ulong valHi = ((ulong)t << 32) | l[i - 1];
        uint valLo = i > 1 ? l[i - 2] : 0;
        if (shift > 0) {
          uint valNx = i > 2 ? l[i - 3] : 0;
          valHi = (valHi << shift) | (valLo >> backShift);
          valLo = (valLo << shift) | (valNx >> backShift);
        }
        ulong d = valHi / divHi;
        if (d > 0xFFFFFFFF) d = 0xFFFFFFFF;
        while (DivideGuessTooBig(d, valHi, valLo, divHi, divLo)) --d;
        if (d > 0) {
          uint carry = SubtractDivisor(l + n, llen - n, r, rlen, d);
          if (carry != t) carry = AddDivisor(l + n, llen - n, r, rlen), --d;
        }
        if (blen != 0) b[n] = (uint)d;
        if (i < llen) l[i] = 0;
      }
    }

    static uint AddDivisor(uint* left, int llen, const uint* right, int rlen) {
      ulong carry = 0ULL, d;
      for (int i = 0; i < rlen; i++)
        d = (left[i] + carry) + right[i], left[i] = (uint)d, carry = d >> 32;
      return (uint)carry;
    }

    static uint SubtractDivisor(uint* left, int llen, const uint* right, int rlen, ulong q) {
      ulong carry = 0ULL;
      for (int i = 0; i < rlen; i++) {
        carry += right[i] * q; uint d = (uint)carry;
        carry = (carry >> 32) + (left[i] < d), left[i] -= d;
      }
      return (uint)carry;
    }

    inline static bool DivideGuessTooBig(ulong q, ulong valHi, uint valLo, uint divHi, uint divLo) {
      ulong chkHi = divHi * q, chkLo = divLo * q;
      chkHi = chkHi + (chkLo >> 32), chkLo = chkLo & 0xFFFFFFFF;
      if (chkHi < valHi) return false;
      if (chkHi > valHi) return true;
      if (chkLo < valLo) return false;
      if (chkLo > valLo) return true;
      return false;
    }

    inline static int LeadingZeros(uint value) {
      if (value == 0) return 32;
      int count = 0;
      if ((value & 0xFFFF0000) == 0) count += 1 << 4, value = value << 16;
      if ((value & 0xFF000000) == 0) count += 1 << 3, value = value << 8;
      if ((value & 0xF0000000) == 0) count += 1 << 2, value = value << 4;
      if ((value & 0xC0000000) == 0) count += 1 << 1, value = value << 2;
      if ((value & 0x80000000) == 0) count += 1 << 0;
      return count;
    }

    inline static ulong MakeUlong(uint uHi, uint uLo) {
      return ((ulong)uHi << kcbitUint) | uLo;
    }

    static std::string FormatBigInt(const _Self& value) {
      if (value._sign == 0) return "0";
      int digits = 0;
      const uint kuBase = 1000000000;
      const int kcchBase = 9;
      int cuSrc = value._bits.size();
      container rguDst = container(cuSrc * 10 / 9 + 2);
      int cuDst = 0;
      for (int iuSrc = cuSrc; --iuSrc >= 0;) {
        uint uCarry = value._bits[iuSrc];
        for (int iuDst = 0; iuDst < cuDst; iuDst++) {
          ulong uuRes = MakeUlong(rguDst[iuDst], uCarry);
          rguDst[iuDst] = (uint)(uuRes % kuBase), uCarry = (uint)(uuRes / kuBase);
        }
        if (uCarry != 0) {
          rguDst[cuDst++] = uCarry % kuBase, uCarry /= kuBase;
          if (uCarry != 0) rguDst[cuDst++] = uCarry;
        }
      }
      int cchMax = cuDst * kcchBase;
      if (digits > 0 && digits > cchMax) cchMax = digits;
      if (value._sign < 0) cchMax = cchMax + 1;
      char* rgch = new char[cchMax + 1];
      int ichDst = cchMax;
      for (int iuDst = 0; iuDst < cuDst - 1; iuDst++) {
        uint uDig = rguDst[iuDst];
        for (int cch = kcchBase; --cch >= 0;) rgch[--ichDst] = (char)('0' + uDig % 10), uDig /= 10;
      }
      for (uint uDig = rguDst[cuDst - 1]; uDig != 0;)
        rgch[--ichDst] = (char)('0' + uDig % 10), uDig /= 10;
      int numDigitsPrinted = cchMax - ichDst;
      while (digits > 0 && digits > numDigitsPrinted) rgch[--ichDst] = '0', digits--;
      if (value._sign < 0) rgch[--ichDst] = '-';
      return string(rgch + ichDst, rgch + cchMax);
    }
  };

} // namespace csl

namespace std {
  inline csl::BigInt abs(const csl::BigInt& x) {
    return x.abs();
  }
  inline string to_string(const csl::BigInt& x) {
    return x.to_string();
  }
} // namespace std

#endif /* BIGINT_H_ */
