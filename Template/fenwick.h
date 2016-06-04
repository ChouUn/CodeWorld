// Name : Fenwick Tree 树状数组
// AKA : Binary Indexed Tree 二分索引树
// Copyright : fateud.com

#ifndef FENWICK_H_
#define FENWICK_H_ 20150928L

#include <vector>
#include <functional>

#ifndef lowbit
#define lowbit(x) ((x)&-(x))
#endif

namespace csl {
  template <typename _Tp, typename _Op = std::plus< _Tp >>
  struct fenwick_tree {
    typedef _Tp value_type;
    typedef std::size_t size_type;
    std::vector< value_type > data;
    fenwick_tree() :
        func() {
    }
    inline void build(size_type p_size) {
      data.assign(p_size + 1, 0);
    }
    void build(const value_type* p_data, size_type p_size) {
      data.resize(p_size + 1);
      for (int i = 1; i <= p_size; ++i)
        data[i] = p_data[i - 1];
      for (int i = 1, j; i <= p_size; ++i)
        if ((j = i + lowbit(i)) <= p_size) data[j] = func(data[j], data[i]);
    }
    inline size_type size() const {
      return data.size();
    }
    value_type query(size_type __x, value_type __res = value_type()) const {
      for (; __x > 0; __x -= lowbit(__x))
        __res = func(__res, data[__x]);
      return __res;
    }
    void update(size_type __x, const value_type& __v) {
      for (; __x < data.size(); __x += lowbit(__x))
        data[__x] = func(data[__x], __v);
    }
  private:
    const _Op func;
  };

  std::size_t search(fenwick_tree< int >& f, int x) {
    if (f.query(f.size() - 1) < x) return -1;
    std::size_t res = 0;
    for (int i = 1 << 20; i > 0 && x > 0; i >>= 1) {
      if (res + i >= f.size()) continue;
      if (x <= f.data[res + i]) continue;
      x -= f.data[res += i];
    }
    return res + 1;
  }

} // namespace csl

#endif /* FENWICK_H_ */
