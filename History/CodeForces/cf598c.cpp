//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf598c.cpp
 *  Date : 2015年12月25日 上午1:48:51
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

int quadrant(const pii& a) {
  return (a.first < 0) * 2 + ((a.second > 0) ^ (a.first >= 0))
      + (a.first + a.second == -1 && a.first * a.second == 0);
}

bool cmp(pii* a, pii* b) {
  if(quadrant(*a) != quadrant(*b)) return quadrant(*a) < quadrant(*b);
  else return a->first * b->second - a->second * b->first < 0;
}

ld cal(pii& a, pii& b) {
  return fabs(atan2(a.first * b.second - a.second * b.first, a.first * b.first + a.second * b.second));
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; cin >> n;
  vpii a(n);
  vector<pii*> b(n);
  rep(i, 0, n) {
    int x, y; cin >> x >> y;
    a[i] = make_pair(x, y), b[i] = &a[i];
  }
  sort(b.begin(), b.end(), cmp);
  b.push_back(b[0]);
  int k = 0;
  rep(i, 1, n) if(cal(*b[i], *b[i+1]) < cal(*b[k], *b[k+1])) k = i;
  cout << (b[k] - &a[0] + 1) << " " << (b[k+1] - &a[0] + 1) << endl;
  return 0;
}
