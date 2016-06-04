// Name : segment tree 非递归线段树
// Copyright : fateud.com
#ifndef SEG_TREE_H_
#define SEG_TREE_H_ 20151229L
#include <vector>
#include <functional>
using std::size_t;
namespace csl {
  template <typename T, typename Func = std::plus< T > >
  class seg_tree {
  public:
    seg_tree() :
        data(), n(), func() {
    }

    void build(size_t m) {
      for (n = 1; n < m; n <<= 1)
        ;
      data.assign(n << 1, T());
    }

    template <typename Iterator>
    inline void build(Iterator first, Iterator last) {
      size_t m = last - first;
      for (n = 1; n < m; n <<= 1)
        ;
      data.assign(n << 1, T());
      std::copy(first, last, data.data() + n);
      for (size_t i = n - 1; i; --i)
        data[i] = func(data[i << 1], data[i << 1 ^ 1]);
    }

    T query(size_t l, size_t r, T res = T()) const {
      for (++r; l && l + (l & -l) <= r; l += (l & -l))
        res = func(res, data[(n + l) / (l & -l)]);
      for (; l < r; r -= r & -r)
        res = func(res, data[(n + r) / (r & -r) - 1]);
      return res;
    }

    T operator [](const size_t x) const {
      return data[n + x];
    }

    void update(size_t x, const size_t& v) {
      data[n + x] = v;
      for (size_t i = (n + x) >> 1; i; i >>= 1)
        data[i] = func(data[i << 1], data[i << 1 ^ 1]);
    }

  private:
    std::vector< T > data;
    size_t n;
    const Func func;
  };
} // namespace csl
#endif /* SEG_TREE_H_ */
