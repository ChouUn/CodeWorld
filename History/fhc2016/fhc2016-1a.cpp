//@ Including Header
// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#include <csl_std.h>

/**
 *  Name : fhc2016-1a.cpp
 *  Date : 2016年1月9日 上午11:08:41
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

struct point {
  int x, y;
};

int dist(point a, point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    int n; cin >> n;
    vector<point> vp(n);
    rep(i, 0, n) cin >> vp[i].x >> vp[i].y;

    long long ans = 0;
    rep(i, 0, n) {
      map<int,int> mp;
      rep(j, 0, n) {
        if(i == j) continue;
        ++mp[dist(vp[i],vp[j])];
      }
      for(auto &j : mp) {
        int x = j.second;
        ans += (ll)x * (x - 1) / 2;
      }
    }
    std::cout << "Case #" << __ <<": " << ans << '\n';
  }
  return 0;
}
