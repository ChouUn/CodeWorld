// Name : Manacher Algorithm 马拉车算法
// Copyright : fateud.com

#ifndef MANACHER_H_
#define MANACHER_H_ 20150814L

#include <vector>

namespace csl {
  template <typename T = char, T FlagS = '@', T FlagD = '#', T FlagT = '\0'>
  class manacher {
  public:
    typedef T key_type;
    typedef int value_type;
    typedef std::size_t size_type;

    inline void build(const key_type* src) {
      generate(src), calculate();
    }

    size_type size() const {
      return dest.size() - 4;
    }

    value_type at(size_type x) {
      return x + 2 < dest.size() ? this->operator[](x) : 0;
    }

    value_type operator [](size_type x) const {
      return data[x + 2] - 1;
    }

    value_type query() const {
      value_type res = value_type();
      for (size_type i = 0; i < dest.size(); ++i)
        if (data[i] > res) res = data[i];
      return res - 1;
    }

  private:
    std::vector< key_type > dest;
    std::vector< value_type > data;

    void generate(const key_type* src) {
      dest.clear(), dest.push_back(FlagS), dest.push_back(FlagD);
      for (size_type i = 0; src[i] != FlagT; i++)
        dest.push_back(src[i]), dest.push_back(FlagD);
      dest.push_back(FlagT);
    }

    void calculate() {
      data.resize(dest.size());
      for (int i = 1, j = 0, p = 0; i < dest.size(); ++i) {
        int k = (p > i) ? std::min(data[2 * j - i], p - i) : 1;
        while (dest[i + k] == dest[i - k])
          ++k;
        if (k + i > p) p = k + i, j = i;
        data[i] = k;
      }
    }

  };

} // namespace csl

#endif /* MANACHER_H_ */
