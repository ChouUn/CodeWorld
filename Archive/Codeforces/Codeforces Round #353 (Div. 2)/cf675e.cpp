//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>
#include <sparse.h>

/**
 *  Name : cf675e.cpp
 *  Date : 2016年5月17日 上午1:16:41
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef csl::sparse_table<int,csl::max<int>> st;
const int N = 100010;
int a[N];
int b[N], c[N], d[N];
ll e[N], ans[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i]; a[0] = 0; a[n] = n;

  st p; p.build(a, n + 1);
  rep(i, 1, n + 1) {
    int l = i, r = i, cnt = 0; ll sum = 0;
    while (r != n) {
      int q = p.query(l, r);
      if (b[r] == 0 || b[r] != q) {
        b[r] = q;
        c[r] = cnt;
        d[r] = l;
        e[r] = sum;
        cnt += 1;
        sum += (ll)cnt * (q - r);
        r = q;
      }
      else if (b[r] == q) {
        sum += (ans[d[r]] - e[r]) + (cnt - c[r]) * ll(n - r);
        break;
      }
    }
    ans[l] = sum;
  }
  ll tot = 0;
  rep(i, 1, n) tot += ans[i];
  cout << tot <<endl;

  return 0;
}
