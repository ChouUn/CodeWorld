// Name : BigInt.h 大整数
// Copyright : fateud.com

#ifndef BIGINT_H_
#define BIGINT_H_ 20160312L

#include <vector>
#include <climits>
#include <iostream>

namespace csl {
#define long long long
  class BigInt {
  public:
    typedef unsigned int uint;
    typedef long unsigned int ulong;
    typedef std::vector< uint > container;
    typedef BigInt _Self;

  public:
    static const int kcbitUint = 32;
    static const uint kuMaskHighBit = (uint)INT_MIN;
    static const int MultiplyThreshold = 32;

  private:
    int _sign;
    container _bits;

  public:
    BigInt() :
        _sign(0), _bits() {
    }

    BigInt(int value) {
      if (value < 0)
        _sign = -1, _bits = container(1, -value);
      else if (value > 0)
        _sign = +1, _bits = container(1, value);
      else
        _sign = 0, _bits = container();
    }

    BigInt(uint value) :
        _sign(+1), _bits(1, value) {
    }

    BigInt(long value) {
      if (INT_MIN <= value && value <= INT_MAX)
        *this = _Self(int(value));
      else {
        ulong x = 0;
        if (value < 0)
          x = (ulong)-value, _sign = -1;
        else
          x = (ulong)value, _sign = +1;
        if (x <= UINT_MAX)
          _bits = container(1, x);
        else
          _bits = container(2), _bits[0] = x, _bits[1] = x >> kcbitUint;
      }
    }

    BigInt(ulong value) {
      _sign = +1;
      if (value <= UINT_MAX)
        _bits = container(1, value);
      else
        _bits = container(2), _bits[0] = value, _bits[1] = value >> kcbitUint;
    }

    BigInt(int n, const container& rgu) :
        _sign(n), _bits(rgu) {
    }

    BigInt(const container& value, bool negative) {
      StripLeadingZero(_bits = value);
      _sign = !_bits.size() ? 0 : negative ? -1 : +1;
    }

    BigInt(container&& value, bool negative) {
      StripLeadingZero(_bits = std::move(value));
      _sign = !_bits.size() ? 0 : negative ? -1 : +1;
    }

    BigInt(const std::string& s) {
      int n = s.size(), cur = 0;
      if (s[cur] == '0')
        _sign = 0, ++cur;
      else if (s[cur] == '-')
        _sign = -1, ++cur;
      else
        _sign = 1;

      container base = container(1, 10);
      _bits = container(1, 0);
      while (cur < n) {
        uint d = s[cur++] - '0';
        container lb = container(_bits.size() + base.size());
        std::swap(lb, _bits);
        Multiply(lb.data(), lb.size(), base.data(), base.size(), data(), size());
        container newBits = container(1, d);
        if (d) AddSelf(data(), size(), newBits.data(), newBits.size());
        StripLeadingZero(_bits);
      }
    }

  public:
    inline uint* data() {
      return _bits.data();
    }

    inline const uint* data() const {
      return _bits.data();
    }

    inline uint size() const {
      return _bits.size();
    }

    inline std::string to_string() const {
      return FormatBigInt(*this);
    }

    inline _Self abs() const {
      return _Self(_sign < 0 ? -_sign : _sign, _bits);
    }

    inline friend std::istream& operator >>(std::istream& is, _Self& value) {
      std::string s;
      return is >> s, value = _Self(s), is;
    }

    inline friend std::ostream& operator <<(std::ostream& os, const _Self& value) {
      return os << value.to_string();
    }

    inline int compareTo(const _Self& other) const {
      if (_sign != other._sign) return _sign < other._sign ? -1 : +1;
      if (!_sign) return 0;
      int cmp = Compare(data(), size(), other.data(), other.size());
      return _sign > 0 ? cmp : -cmp;
    }

    inline bool equals(const _Self& other) const {
      if (_sign != other._sign) return false;
      if (_bits == other._bits) return true;
      return false;
    }

    static void DnM(const _Self& left, const _Self& right, _Self& q, _Self& r) {
      if (!left._sign)
        q = r = left;
      else if (left.size() < right.size())
        q = _Self(0), r = left;
      else {
        container cr = container(left._bits), cq = container(left.size() - right.size() + 1);
        Divide(cr.data(), cr.size(), right.data(), right.size(), cq.data(), cq.size());
        r = _Self(std::move(cr), left._sign < 0);
        q = _Self(std::move(cq), (left._sign < 0) ^ (right._sign < 0));
      }
    }

  public:
    inline _Self operator +() const {
      return _Self(_sign, _bits);
    }

    inline _Self operator -() const {
      return _Self(-_sign, _bits);
    }

    inline bool operator !() const {
      return _sign == 0;
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

    friend _Self operator +(_Self left, const _Self& right) {
      return left += right;
    }

    friend _Self operator -(_Self left, const _Self& right) {
      return left -= right;
    }

    friend _Self operator *(const _Self& left, const _Self& right) {
      if (!left._sign) return left;
      if (!right._sign) return right;
      container bits = container(left.size() + right.size());
      if (left.size() < right.size())
        Multiply(right.data(), right.size(), left.data(), left.size(), bits.data(), bits.size());
      else
        Multiply(left.data(), left.size(), right.data(), right.size(), bits.data(), bits.size());
      return _Self(std::move(bits), (left._sign < 0) ^ (right._sign < 0));
    }

    friend _Self operator /(const _Self& left, const _Self& right) {
      if (!left._sign) return left;
      if (left.size() < right.size())
        return _Self(0);
      else {
        container local = container(left._bits), bits = container(left.size() - right.size() + 1);
        Divide(local.data(), local.size(), right.data(), right.size(), bits.data(), bits.size());
        return _Self(std::move(bits), (left._sign < 0) ^ (right._sign < 0));
      }
    }

    friend _Self operator %(_Self left, const _Self& right) {
      return left %= right;
    }

    friend _Self& operator +=(_Self& left, const _Self& right) {
      if (!right._sign) return left;
      if (!left._sign) return left = right;
      if (left._sign != right._sign)
        left = Subtract(left._bits, left._sign, right._bits, right._sign);
      else
        left = Add(left._bits, left._sign, right._bits, right._sign);
      return left;
    }

    friend _Self& operator -=(_Self& left, const _Self& right) {
      if (!right._sign) return left;
      if (!left._sign) return left = -right;
      if (left._sign != right._sign)
        left = Add(left._bits, left._sign, right._bits, -right._sign);
      else
        left = Subtract(left._bits, left._sign, right._bits, right._sign);
      return left;
    }

    friend _Self& operator *=(_Self& left, const _Self& right) {
      return left = left * right;
    }

    friend _Self& operator /=(_Self& left, const _Self& right) {
      return left = left / right;
    }

    friend _Self& operator %=(_Self& left, const _Self& right) {
      if (!left._sign) return left;
      if (left.size() < right.size()) return left;
      Divide(left.data(), left.size(), right.data(), right.size(), container().data(), 0);
      return left = _Self(std::move(left._bits), left._sign < 0);
    }

    friend _Self operator <<(const _Self& value, int shift) {
      if (shift == 0)
        return value;
      else if (shift == INT_MIN)
        return (value >> INT_MAX) >> 1;
      else if (shift < 0) return value >> -shift;
      int ds = shift / kcbitUint, ss = shift - (ds * kcbitUint);
      container xd;
      int xl;
      bool negx = GetPartsForBitManipulation(value, xd, xl);
      int zl = xl + ds + 1;
      container zd = container(zl);
      if (ss == 0)
        for (int i = 0; i < xl; i++)
          zd[i + ds] = xd[i];
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
      if (shift == 0)
        return value;
      else if (shift == INT_MIN)
        return ((value << INT_MAX) << 1);
      else if (shift < 0) return value << -shift;
      int ds = shift / kcbitUint, ss = shift - (ds * kcbitUint);
      container xd;
      int xl;
      bool negx = GetPartsForBitManipulation(value, xd, xl);
      if (negx) {
        if (shift >= (kcbitUint * xl)) return _Self(-1LL);
        xd.resize(xl), DangerousMakeTwosComplement(xd);
      }
      int zl = xl - ds;
      if (zl < 0) zl = 0;
      container zd = container(zl);
      if (ss == 0)
        for (int i = xl - 1; i >= ds; i--)
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

  private:
    static int Compare(const uint* l, int ll, const uint* r, int rl) {
      if (ll ^ rl) return (ll < rl) ? -1 : 1;
      for (int i = ll - 1; i >= 0; i--)
        if (l[i] ^ r[i]) return (l[i] < r[i]) ? -1 : 1;
      return 0;
    }

    static void StripLeadingZero(container& bits) {
      const uint* data = bits.data();
      uint len = bits.size();
      while (len > 0 && data[len - 1] == 0)
        --len;
      bits.resize(len);
    }

    static _Self Add(container left, int ls, container right, int rs) {
      container *l = &left, *s = &right;
      if (l->size() < s->size()) std::swap(l, s);
      uint ll = l->size(), sl = s->size();
      long res = AddSelf(l->data(), ll, s->data(), sl);
      if (res) l->push_back(res);
      return _Self(std::move(*l), ls < 0);
    }

    static _Self Subtract(container left, int ls, container right, int rs) {
      container *l = &left, *s = &right;
      if (Compare(l->data(), l->size(), s->data(), s->size()) < 0) std::swap(l, s), ls = -ls;
      uint ll = l->size(), sl = s->size();
      SubtractSelf(l->data(), ll, s->data(), sl);
      StripLeadingZero(*l);
      return _Self(std::move(*l), ls < 0);
    }

    static long AddSelf(uint* l, int ll, const uint* r, int rl) {
      long c = 0;
      for (int i = 0; i < rl; i++)
        c = (l[i] + c) + r[i], l[i] = c, c >>= 32;
      for (int i = rl; c != 0 && i < ll; i++)
        c = l[i] + c, l[i] = c, c >>= 32;
      return c;
    }

    static long SubtractSelf(uint* l, int ll, const uint* r, int rl) {
      long c = 0;
      for (int i = 0; i < rl; i++)
        c = (l[i] + c) - r[i], l[i] = c, c >>= 32;
      for (int i = rl; c != 0 && i < ll; i++)
        c = l[i] + c, l[i] = c, c >>= 32;
      return c;
    }

    static void Multiply(const uint* l, int ll, const uint* r, int rl, uint* b, int bl) {
      if (rl < MultiplyThreshold) {
        for (int i = 0; i < rl; i++) {
          ulong c = 0;
          for (int j = 0; j < ll; j++)
            c = b[i + j] + c + (ulong)l[j] * r[i], b[i + j] = c, c >>= 32;
          b[i + ll] = c;
        }
      }
      else {
        int n = rl >> 1, n2 = n << 1;
        const uint *llo = l, *lhi = l + n, *rlo = r, *rhi = r + n;
        int llol = n, lhil = ll - n, rlol = n, rhil = rl - n;
        uint *blo = b, *bhi = b + n2;
        int blol = n2, bhil = bl - n2;
        Multiply(llo, llol, rlo, rlol, blo, blol);
        Multiply(lhi, lhil, rhi, rhil, bhi, bhil);
        int lfl = lhil + 1, rfl = rhil + 1, col = lfl + rfl;
        container lf(lhi, lhi + lhil);
        lf.resize(lfl);
        AddSelf(lf.data(), lfl, llo, llol);
        container rf(rhi, rhi + rhil);
        rf.resize(rfl);
        AddSelf(rf.data(), rfl, rlo, rlol);
        container co = container(col);
        Multiply(lf.data(), lfl, rf.data(), rfl, co.data(), col);
        SubtractSelf(co.data(), col, bhi, bhil);
        SubtractSelf(co.data(), col, blo, blol);
        AddSelf(b + n, bl - n, co.data(), col);
      }
    }

    static void Divide(uint* l, int ll, const uint* r, int rl, uint* b, int bl) {
      uint dHi = r[rl - 1], dLo = rl > 1 ? r[rl - 2] : 0;
      int sh = __builtin_clz(dHi), bsh = 32 - sh;
      if (sh > 0) {
        uint dNx = rl > 2 ? r[rl - 3] : 0;
        dHi = (dHi << sh) | (dLo >> bsh);
        dLo = (dLo << sh) | (dNx >> bsh);
      }
      for (int i = ll; i >= rl; i--) {
        int n = i - rl;
        uint t = i < ll ? l[i] : 0;
        ulong vHi = ((ulong)t << 32) | l[i - 1];
        uint vLo = i > 1 ? l[i - 2] : 0;
        if (sh > 0) {
          uint vNx = i > 2 ? l[i - 3] : 0;
          vHi = (vHi << sh) | (vLo >> bsh);
          vLo = (vLo << sh) | (vNx >> bsh);
        }
        ulong d = std::min(vHi / dHi, 0xFFFFFFFFULL);
        while (DivideGuessTooBig(d, vHi, vLo, dHi, dLo))
          --d;
        if (d > 0 && SubtractDivisor(l + n, ll - n, r, rl, d) != t)
          AddDivisor(l + n, ll - n, r, rl), --d;
        if (bl != 0) b[n] = (uint)d;
        if (i < ll) l[i] = 0;
      }
    }

    static uint AddDivisor(uint* l, int ll, const uint* r, int rl) {
      ulong c = 0;
      for (int i = 0; i < rl; i++)
        c = (l[i] + c) + r[i], l[i] = c, c >>= 32;
      return c;
    }

    static uint SubtractDivisor(uint* l, int ll, const uint* r, int rl, ulong q) {
      ulong c = 0;
      for (int i = 0; i < rl; i++) {
        c += r[i] * q;
        uint digit = (uint)c;
        c = (c >> 32) + (l[i] < digit), l[i] -= digit;
      }
      return c;
    }

    static bool DivideGuessTooBig(ulong q, ulong vHi, uint vLo, uint dHi, uint dLo) {
      ulong cHi = dHi * q, cLo = dLo * q;
      cHi = cHi + (cLo >> 32), cLo = cLo & 0xFFFFFFFF;
      if (cHi ^ vHi) return cHi > vHi;
      if (cLo ^ vLo) return cLo > vLo;
      return false;
    }

    inline static bool GetPartsForBitManipulation(const _Self& x, container& xd, int& xl) {
      if (x._bits.empty())
        xd.assign(1, (x._sign < 0) ? (uint)-x._sign : (uint)x._sign);
      else
        xd = x._bits;
      xl = (x._bits.empty() ? 1 : x._bits.size());
      return x._sign < 0;
    }

    static void DangerousMakeTwosComplement(container& d) {
      if (!d.empty() && d.size() > 0) {
        d[0] = ~d[0] + 1;
        uint i = 1;
        for (; d[i - 1] == 0 && i < d.size(); i++)
          d[i] = ~d[i] + 1;
        for (; i < d.size(); i++)
          d[i] = ~d[i];
      }
    }

    static std::string FormatBigInt(const _Self& value) {
      if (value._sign == 0) return "0";
      const uint kuBase = 1000000000;
      const int kcchBase = 9;
      int d = 0, cs = value._bits.size(), cd = 0;
      container rd = container(cs * 10 / 9 + 2);
      for (int is = cs; --is >= 0;) {
        uint uc = value._bits[is];
        for (int id = 0; id < cd; id++) {
          ulong ur = ((ulong)rd[id] << kcbitUint) | uc;
          rd[id] = (uint)(ur % kuBase), uc = (uint)(ur / kuBase);
        }
        if (uc != 0) {
          rd[cd++] = uc % kuBase, uc /= kuBase;
          if (uc != 0) rd[cd++] = uc;
        }
      }
      int cm = cd * kcchBase;
      if (d > 0 && d > cm) cm = d;
      if (value._sign < 0) cm = cm + 1;
      char* s = new char[cm + 1];
      int id = cm;
      for (int iuDst = 0; iuDst < cd - 1; iuDst++) {
        uint ud = rd[iuDst];
        for (int cch = kcchBase; --cch >= 0;)
          s[--id] = (char)('0' + ud % 10), ud /= 10;
      }
      for (uint uDig = rd[cd - 1]; uDig != 0;)
        s[--id] = (char)('0' + uDig % 10), uDig /= 10;
      for (int t = cm - id; d > 0 && d > t;)
        s[--id] = '0', d--;
      if (value._sign < 0) s[--id] = '-';
      return std::string(s + id, s + cm);
    }
  };
// class BigInt
#undef long
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

