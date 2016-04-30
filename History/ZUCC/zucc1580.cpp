//@ Including Header
#include <csl_std.h>
#include <csl_math.h>
#include <matrix.h>

/**
 *  Name : zucc1580.cpp
 *  Date : 2016年4月26日 下午1:01:25
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef csl::matrix<int> mat;
#define N 20
#define P 10000
int a[N];

struct mod {
  mat operator () (mat a, int p) const {
    rep(i, 0u, a.height()) rep(j, 0u, a.width()) a[i][j] %= p;
    return a;
  }
};

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];
    int k; cin >> k;

    mat base(1, n);
    rep(i, 0, n) base[0][i] = a[i];
    mat tran(n, n);
    rep(i, 1, n) tran[i][i-1] = 1;
    rep(i, 0, n) tran[i][n-1] = 1;

    base = csl::dnc(base, tran, k - 1, P, std::multiplies<mat>(), mod());
    cout << base[0][0] << '\n';
  }
  return 0;
}
