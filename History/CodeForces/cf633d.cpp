//@ Including Header
// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#ifndef CSL_STD_H_
#define CSL_STD_H_ 20151122L
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<pii> vpii;

#define rep(i,a,b) for(auto i=a,i##_n=b;i<i##_n;++i)
#define per(i,a,b) for(auto i=b,i##_n=a;i-->i##_n;)

#endif /* CSL_STD_H_ */


/**
 *  Name : cf633d.cpp
 *  Date : 2016年2月27日 下午7:59:41
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; cin >> n;
  vector<int> a(n);
  for (auto& ai : a) cin >> ai;

  unordered_map< int, deque<int> > m;
  for (auto& ai : a) m[ai].push_back(-1);

  int times = 0, ans = 0;
  for (auto i : m) for (auto j : m) {
    ++times;
    int x = i.first, y = j.first, p = 2;
    {
      auto q = m.find(x);
      q->second.pop_front();
      q->second.push_back(times);
      if (x != y) q = m.find(y);
      else if (q->second.front() == times) continue;
      q->second.pop_front();
      q->second.push_back(times);
    }
    do {
      int z = x + y;
      auto q = m.find(z);
      if (q == m.end()) break;
      if (q->second.front() == times) break;
      q->second.pop_front();
      q->second.push_back(times);
      x = y, y = z, ++p;
    } while (true);
    ans = max(ans, p);
  }
  cout << ans << endl;

  return 0;
}
