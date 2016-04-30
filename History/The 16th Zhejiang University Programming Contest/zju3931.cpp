//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju3931.cpp
 *  Date : 2016年4月12日 下午1:23:43
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

bitset<500000> bs;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    priority_queue<int,vi,greater<int>> pq;
    rep(i, 0, n) { int x; cin >> x; pq.push(x); }

    int m; cin >> m;
    vi a; a.reserve(n);
    rep(i, 1, n) {
      int x = pq.top(); pq.pop();
      int y = pq.top(); pq.pop();
      pq.push(x + y);
      if (x > y) swap(x, y);
      m -= x, a.push_back(y - x);
    }

    int mm = accumulate(a.begin(), a.end(), 0);
    if (mm < m || m < 0) { cout << "No" << endl; continue; }
    bs.reset(), bs[0] = true;
    for (auto &ai : a)
      rrep(i, 0, m-ai+1) bs[i+ai] = bs[i+ai] | bs[i];
    cout << (bs[m] ? "Yes" : "No") << endl;
  }
  return 0;
}
