// Name : Manacher Algorithm 马拉车算法
// Copyright : fateud.com

#ifndef MANACHER_H_
#define MANACHER_H_ 20150814L

#include <vector>

namespace csl {
  template<typename _Tp = char,_Tp _FlagS = '@',_Tp _FlagD = '#',_Tp _FlagT =
      '\0'>
  struct manacher {
    // template parameter.
    typedef _Tp key_type;
    typedef int value_type;
    typedef std::size_t size_type;

    void generate(const key_type* __src) {
      m_dest.clear();
      m_dest.push_back(_FlagS), m_dest.push_back(_FlagD);
      for(size_type i = 0; __src[i] != _FlagT; i++)
        m_dest.push_back(__src[i]), m_dest.push_back(_FlagD);
      m_dest.push_back(_FlagT);
      m_size = m_dest.size();
    }

    void calculate() {
      m_data.resize(m_size);
      for(int i = 1, j = 0, p = 0; i < m_size; ++i) {
        register int k = (p > i) ? std::min(m_data[2 * j - i], p - i) : 1;
        while(m_dest[i + k] == m_dest[i - k])
          ++k;
        if(k + i > p) p = k + i, j = i;
        m_data[i] = k;
      }
    }

    // capacity.
    inline void build(const key_type* __src) {
      generate(__src);
      calculate();
    }

    size_type size() const {
      return m_size - 4;
    }

    // element access.
    value_type query() const {
      value_type __res = value_type();
      for(size_type i = 0; i < m_size; ++i)
        if(m_data[i] > __res) __res = m_data[i];
      return __res - 1;
    }

    value_type at(size_type __x) {
      return __x + 2 < m_size ? this->operator[](__x) : 0;
    }

    value_type operator [](size_type __x) const {
      return m_data[__x + 2] - 1;
    }

    // member variable.
    std::vector<key_type> m_dest;
    std::vector<value_type> m_data;
    size_type m_size;

  };

} // namespace csl

#endif /* MANACHER_H_ */
