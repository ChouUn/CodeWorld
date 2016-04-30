//@ Including Header
#include <csl_std.h>

/**
 *  Name : usaco2016JanS-a.cpp
 *  Date : 2016年1月18日 下午9:08:20
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

int solve(vi& v, int m, int k) {
  int res = 0, x = 0, n = v.size();
  while(x < n) {
    if(res > k) return res;
    int y = x;
    while(x < n-1 && v[x+1] - v[y] <= m * 2) ++x;
    ++res, ++x;
  }
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ifstream in("angry.in");
  ofstream out("angry.out");

  int n, k; in >> n >> k;
  vi v(n); rep(i, 0, n) in >> v[i];
  sort(v.begin(), v.end());

  int l = 0, r = 1000000001;
  while(l < r) {
    int m = (l + r) >> 1;
    int x = solve(v, m, k);
    if(x > k) l = m + 1;
    else r = m;
  }
  out << l << endl;
  return 0;
}
