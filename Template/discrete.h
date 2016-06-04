// Name : Discretization 离散化
// Copyright : fateud.com
#ifndef DISCRETE_H_
#define DISCRETE_H_ 20150926L
#include <vector>
#include <algorithm>
namespace csl {
  template <typename _Tp>
  struct discrete {
    typedef std::size_t size_type;

    void build() {
      std::sort(data.begin(), data.end());
      data.resize(std::unique(data.begin(), data.end()) - data.begin());
    }
    inline void clear() {
      data.clear();
    }
    inline size_type size() const {
      return data.size();
    }
    inline void reserve(size_type __n) {
      data.reserve(__n);
    }

    inline size_type query(const _Tp& __x) const {
      return std::lower_bound(data.begin(), data.end(), __x) - data.begin();
    }
    _Tp operator [](size_type __x) const {
      return data[__x];
    }
    inline void insert(_Tp __x) {
      data.push_back(__x);
    }
    template <typename _InputIterator>
    inline void insert(_InputIterator first, _InputIterator last) {
      data.insert(data.end(), first, last);
    }

    std::vector< _Tp > data;
  };
} // namespace csl

#endif /* DISCRETE_H_ */
