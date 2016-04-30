//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>
#include <sparse.h>

/*
 *  Name : hdu5247.cpp
 *  Date : 2015年8月5日 下午7:41:50
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 10010
int a[maxn], b[maxn];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n, m; cin >> n >> m; --_, ++__) {
    std::cout << "Case #" << __ <<":\n";
    rep(i, 0, n) cin >> a[i];

    map<int,int> p;
    map<int,int>::iterator it;
    rep(i, 0, n) {
      it = p.find(a[i]);
      b[i] = (it == p.end()) ? -1 : it->second;
      p[a[i]] = i;
    }

    csl::sparse_table< int, csl::min<int> > st1; st1.build(a, n);
    csl::sparse_table< int, csl::max<int> > st2; st2.build(a, n);
    csl::sparse_table< int, csl::max<int> > st3; st3.build(b, n);

    while (m--) {
      int k; cin >> k;
      int ans = 0;
      rep(i, 0, n-k+1) {
        int x = st1.query(i, i+k-1);
        int y = st2.query(i, i+k-1);
        if(y - x + 1 != k) continue;
        int z = st3.query(i, i+k-1);
        if(z >= i) continue;
        ++ans;
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
