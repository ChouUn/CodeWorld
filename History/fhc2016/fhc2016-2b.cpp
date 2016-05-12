//@ Including Header
#include <csl_std.h>

/**
 *  Name : fhc2016-2b.cpp
 *  Date : 2016年1月17日 上午9:11:21
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef pair<ll,ll> pll;
struct cmp {
  bool operator () (const pll& a, const pll& b) const {
    ll x = a.first + a.second;
    ll y = b.first + b.second;
    return x != y ? x > y : a.second > b.second;
  }
};

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    int l, n, m; ll d; cin >> l >> n >> m >> d;
    priority_queue< pll, vector<pll>, cmp> q;
    rep(i, 0, n) {
      ll x; cin >> x;
      q.push(make_pair(0ll, x));
    }
    multiset<ll> p;
    rep(i, 0, m) p.insert(0ll);
    while(l--) {
      pll x = q.top(); q.pop();
      x.first += x.second; q.push(x);
      ll z = max(x.first, *p.begin());
      p.erase(p.begin());
      p.insert(z + d);
    }
    std::cout << "Case #" << __ << ": " << *p.rbegin() << endl;
  }
  return 0;
}
