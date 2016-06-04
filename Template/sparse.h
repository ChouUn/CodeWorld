// Name : Sparse Table 稀疏表
// Copyright : fateud.com
#ifndef SPARSE_H_
#define SPARSE_H_ 20160524L
#include <vector>
using std::size_t;

#ifndef CSL_ALGO_H_
#pragma message("need : csl_algo.h");
#include <csl_algo.h>
#endif

namespace csl {
  static std::vector< std::size_t > msb(2, 0);
  void msb_build(std::size_t p_data) {
    msb.reserve(p_data + 1);
    for (std::size_t i = msb.size(), t = msb[i - 1]; i <= p_data; ++i)
      msb.push_back(t += !(i & (i - 1)));
  }

  template <typename T, typename Func = csl::min< T >>
  class sparse_table {
  public:
    sparse_table() :
        data(), func() {
    }

    inline void clear() {
      data.clear();
    }

    inline size_t size() const {
      return data.empty() ? 0 : data.at(0).size();
    }

    inline T query(size_t first, size_t last) const {
      size_t k = csl::msb[last - first + 1];
      return func(data[k][first], data[k][last + 1 - (1 << k)]);
    }

    void build(T* s, size_t n) {
      msb_build(n), data.clear();
      data.push_back(std::vector< T >(s, s + n));
      for (size_t k = 1, d = 2, t = 1; d <= n; ++k, d <<= 1, t <<= 1) {
        data.push_back(std::vector< T >(n - d + 1));
        for (size_t i = 0, j = n + 1 - d; i < j; ++i)
          data[k][i] = func(data[k - 1][i], data[k - 1][i + t]);
      }
    }

  private:
    std::vector< std::vector< T > > data;
    const Func func;
  };
} // namespace csl
#endif /* SPARSE_H_ */
