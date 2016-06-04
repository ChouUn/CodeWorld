// Name : Gaussian Elimination 高斯消元法
// Copyright : fateud.com

#ifndef GAUSS_H_
#define GAUSS_H_ 20151229L

#include <vector>

#ifndef CSL_ALGO_H_
#pragma message("need : csl_algo.h")
#include <csl_algo.h>
#endif

#ifndef MATRIX_H_
#pragma message("need : matrix.h")
#include <matrix.h>
#endif

namespace csl {
  // for matrix of normal type
  template <typename T>
  class gauss {
  public:
    typedef T value_type;
    typedef int size_type;

    size_type dim;
    size_type equ;
    size_type var;
    std::vector< bool > free;
    std::vector< value_type > ans;

    void build(csl::matrix< value_type > mat) {
      equ = mat.height();
      var = mat.width() - 1;
      dim = 0;
      free.assign(var, true);
      ans.assign(var, value_type());

      // 阶梯矩阵
      size_type r, c;
      for (r = 0, c = 0; r < equ && c < var; ++c) {
        // 行变换
        size_type max_r = r;
        for (size_type i = r + 1; i < equ; ++i)
          if (std::abs(mat[i][c]) > std::abs(mat[max_r][c])) max_r = i;
        if (max_r != r) for (size_type i = r; i <= var; ++i)
          std::swap(mat[r][i], mat[max_r][i]);
        if (!csl::sgn(mat[r][c])) continue;

        // 消元
        for (size_type i = r + 1; i < equ; ++i) {
          if (csl::sgn(mat[i][c])) {
            value_type tmp = mat[i][c] / mat[r][c];
            for (size_type j = c; j <= var; ++j)
              mat[i][j] -= tmp * mat[r][j];
          }
        }
        ++r;
      }

      // 无解
      for (size_type i = r; i < equ; ++i)
        if (csl::sgn(mat[i][c])) {
          dim = -1;
          return;
        }

      // 无穷解
      if (r < var) {
        for (size_type i = r - 1; i >= 0; --i) {
          // 不确定变元
          size_type cnt = 0, idx;
          for (size_type j = 0; j < var; ++j)
            if (csl::sgn(mat[i][j]) && free[j]) ++cnt, idx = j;
          if (cnt > 1) continue;

          // 求出变元
          value_type tmp = mat[i][var];
          for (size_type j = 0; j < var; ++j)
            if (csl::sgn(mat[i][j]) && j != idx) tmp -= mat[i][j] * ans[j];
          ans[idx] = tmp / mat[i][idx], free[idx] = 0;
        }
        dim = var - r;
        return;
      }

      // 唯一解
      for (size_type i = var - 1; i >= 0; --i) {
        value_type tmp = mat[i][var];
        for (size_type j = i + 1; j < var; ++j)
          if (csl::sgn(mat[i][j])) tmp -= mat[i][j] * ans[j];
        ans[i] = tmp / mat[i][i];
      }
      dim = 0;
      return;
    }

  };

  // for matrix of boolean
  template <>
  class gauss< bool > {
  public:
    typedef int value_type;
    typedef int size_type;

    size_type dim;
    size_type equ;
    size_type var;
    std::vector< bool > free;
    std::vector< value_type > ans;

    void build(csl::matrix< value_type > mat) {
      equ = mat.height();
      var = mat.width() - 1;
      dim = 0;
      free.assign(var, true);
      ans.assign(var, value_type());

      // 阶梯矩阵
      size_type r, c;
      for (r = 0, c = 0; r < equ && c < var; ++c) {
        // 行变换
        size_type max_r = r;
        for (size_type i = r + 1; i < equ; ++i)
          if (mat[i][c] > mat[max_r][c]) max_r = i;
        if (max_r != r) for (size_type i = r; i <= var; ++i)
          std::swap(mat[r][i], mat[max_r][i]);
        if (!mat[r][c]) continue;

        // 消元
        for (size_type i = r + 1; i < equ; ++i)
          if (mat[i][c]) for (size_type j = c; j <= var; ++j)
            mat[i][j] ^= mat[r][j];
        ++r;
      }

      // 无解
      for (size_type i = r; i < equ; ++i)
        if (mat[i][c]) {
          dim = -1;
          return;
        }

      // 无穷解
      if (r < var) {
        for (size_type i = r - 1; i >= 0; --i) {
          // 不确定变元
          size_type cnt = 0, idx;
          for (size_type j = 0; j < var; ++j)
            if (mat[i][j] && free[j]) ++cnt, idx = j;
          if (cnt > 1) continue;

          // 求出变元
          value_type tmp = mat[i][var];
          for (size_type j = 0; j < var; ++j)
            if (mat[i][j] && j != idx) tmp ^= mat[i][j] * ans[j];
          ans[idx] = tmp, free[idx] = 0;
        }
        dim = var - r;
        return;
      }

      // 唯一解
      for (size_type i = var - 1; i >= 0; --i) {
        value_type tmp = mat[i][var];
        for (size_type j = i + 1; j < var; ++j)
          if (mat[i][j]) tmp ^= mat[i][j] * ans[j];
        if (mat[i][i]) ans[i] = tmp;
      }
      dim = 0;
      return;
    }

  };

} // namespace csl

#endif /* GAUSS_H_ */
