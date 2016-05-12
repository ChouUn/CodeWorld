//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>
#include <matrix.h>
#include <gauss.h>

/*
 *  Name : poj1830.cpp
 *  Date : 2015年10月7日 下午7:09:29
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

using csl::matrix;
using csl::gauss;
#define maxn 30
int a[maxn], b[maxn];

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    int n; scanf("%d", &n);
    rep(i, 0, n) scanf("%d", a+i);
    rep(i, 0, n) scanf("%d", b+i);

    matrix<int> mat(n, n+1);
    int u, v;
    while (scanf("%d%d", &u, &v) != EOF && u && v) mat[v-1][u-1] = 1;
    rep(i, 0, n) mat[i][i] = 1, mat[i][n] = a[i] ^ b[i];

    gauss<bool> gau;
    gau.build(mat);
    if (~gau.dim) printf("%d\n", 1 << gau.dim);
    else printf("Oh,it's impossible~!!\n");
  }
  return 0;
}
