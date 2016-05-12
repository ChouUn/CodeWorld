/*
 *	Name : zju3497.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��23�� ����6:27:10
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define REP(i,n)    for(int _t=n,i=0;i<_t;i++)
template <typename _Tp, size_t _Sz>
class Matrix {
  // Name : Matrix ����
  // Copyright : www.fateud.com
public  :
  typedef Matrix<_Tp, _Sz>        _Self;
  typedef _Tp                     value_type;
  typedef _Tp &                   reference;
private :
  size_t _h, _w;
  value_type _data[_Sz][_Sz];
public  :
  Matrix() : _h(_Sz), _w(_Sz) { clear(); }
  Matrix(size_t __h, size_t __w) : _h(__h), _w(__w) { clear(); }
  static _Self basic(size_t __n) { _Self __res(__n, __n); REP(i,__n) __res._data[i][i] = 1; return __res; }
  inline static _Self basic(const _Self& target) { return basic(target._h); }
  inline size_t height() const { return _h; }
  inline size_t width() const { return _w; }
  inline reference at(size_t x, size_t y) { return _data[x][y]; }
  inline void clear() { memset(_data, 0x00, sizeof(_data)); }
  _Self & operator += (_Self other) { REP(i,_h) REP(j,_w) at(i,j) += other.at(i,j); return (*this); }
  _Self & operator *= (_Self other) { _Self __res(_h, other._w); REP(i,__res._h) REP(j,__res._w) REP(k,_w) __res.at(i,j) += (*this).at(i,k) * other.at(k,j); *this = __res; return (*this); }
  _Self operator + (const _Self other) const { return _Self(*this) += other; }
  _Self operator * (const _Self other) const { return _Self(*this) *= other; }
  _Self operator ^ (int __k) { _Self n = *this, __res = basic(*this); while (__k) { if (__k & 1) __res *= n; n *= n, __k >>= 1; } return __res; }
};
int getint() { int ret = 0; bool ok=0, neg=0; while (true) { int c = getchar();
    if (c >= '0' && c <= '9') ret = (ret<<3) + (ret << 1) + c - '0', ok = 1;
    else if (ok) break; else if (c=='-') neg=1; } return neg ? -ret : ret;
}

typedef Matrix<int, 25> mat;

//@ Main Function
int main() {
  int _ = getint();
  while (_--) {
    int n = getint(), m = getint();
    mat t(n*m, n*m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        for (int k = 0; k < 4; k++) {
          int x = getint() - 1, y = getint() - 1;
          int u = i * m + j;
          int v = x * m + y;
          t.at(u,v) = 1;
        }
    int tar = n * m - 1;
    for (int i = 0; i < n*m; i++)
      t.at(tar, i) = 0;

    mat s(1, n*m);
    s.at(0,0) = 1;
    int q = getint();
    while (q--) {
      int x = getint();
      mat p = s * (t ^ x);
      int sum = 0;
      for (int i = 0; i < n*m; i++)
        sum += p.at(0, i);
      if (p.at(0, tar) == 0)
        printf("False\n");
      else if (sum != p.at(0, tar))
        printf("Maybe\n");
      else
        printf("True\n");
    }
    printf("\n");
  }
  return 0;
}
