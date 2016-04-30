/*
 * matrix.h
 *
 *  Created on: 2015��4��23��
 *      Author: ChouUn
 */

#ifndef _MATRIX_H_
#define _MATRIX_H_
#define _MATRIX_H_VERSION

namespace csl
{

  template <typename _Tp, int _Sz>
  class matrix
  {
  private :

    _Tp _data[_Sz][_Sz];
    int _h, _w;

  public :
    matrix()
    : _h(), _w()
    { }

  public :
    matrix(int a, int b)
    : _h(a), _w(b)
    { clear(); }

  public :
    static inline _Self
    identity(int n, int m)
    {
      _Self r(n, m);
      for (int i = 0; i < n && i < m; i++)
        r._data[i][i] = _Tp(1);
      return r;
    }

    inline void
    clear()
    {
      for (int i = 0; i < _h; i++)
        for (int j = 0; j < _w; j++)
          _data[i][j] = _Tp();
    }

    _Tp&
    operator += (const _Self b)
    {
      assert(_h == b._h && _w == b._w);
      for (int i = 0; i < _h; i++)
        for (int j = 0; j < _w; j++)
          _data[i][j] += b._data[i][j];
      return (*this);
    }

    _Tp&
    operator *= (const _Self b)
    {
      matrix a(*this);
      assert(a._w == b._h);
      int n = a._h, m = b._w, p = a._w;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
          _Tp &t = (_data[i][j] = _Tp());
          for (int k = 0; k < p; k++)
            t += a._data[i][k] * b._data[k][j];
        }
      return (*this);
    }

  };

} // namespace csl

#endif /* _MATRIX_H_ */
