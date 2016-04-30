//@ Including Header
#include <csl_std.h>
#include <fenwick.h>
#include <discrete.h>

/*
 *  Name : hdu5249-2.cpp
 *  Date : 2015年8月5日 下午11:37:55
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 10010
char op[maxn];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    std::cout << "Case #" << __ <<":\n";

    vector<int> u;
    csl::discrete<int> v;
    rep(i, 0, n) {
      char s[10]; cin >> s; op[i] = s[0];
      if (s[0] == 'i') {
        int x; cin >> x;
        u.push_back(x), v.insert(x);
      }
    }
    v.build();

    csl::fenwick_tree<int> ft;
    ft.build(v.size());
    int l = -1, r = -1, pos;
    rep(i, 0, n)
      switch(op[i]) {
        case 'i':
          pos = v.query(u[++r]);
          ft.update(pos+1, +1);
          break;
        case 'o':
          pos = v.query(u[++l]);
          ft.update(pos+1, -1);
          break;
        case 'q':
          pos = csl::search(ft, (r-l)/2+1);
          cout << v[pos-1] << '\n';
          break;
      }
  }
  return 0;
}
