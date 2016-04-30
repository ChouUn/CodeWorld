//@ Including Header
#include <csl_std.h>

/**
 *  Name : fbhc2016-1c.cpp
 *  Date : 2016年1月9日 下午12:09:35
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

deque<pii> deal(char* s) {
  deque<pii> res;
  int i = 0, p = 0, q = 0;
  do {
    if(s[i] == '.') {
      if(q) q = q + 1;
      else p = i, q = 1;
    }
    else if(q) {
      res.push_back(make_pair(p, p + q - 1));
      q = 0;
    }
  } while(s[i++]);
  return res;
}

char s[1010];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    int n; cin >> n;
    cin >> s; deque<pii> d1 = deal(s);
    cin >> s; deque<pii> d2 = deal(s);

    int ans = 0;
    while(d1.size() && d2.size()) {
      pii& p = d1.front();
      pii& q = d2.front();
//      cout << p.first << " " << p.second << " ";
//      cout << q.first << " " << q.second << "\n";
      if(p.second < q.first) {
        ans = ans + 1;
        d1.pop_front();
      }
      else if(q.second < p.first) {
        ans = ans + 1;
        d2.pop_front();
      }
      else if(p.second == p.first || q.second == q.first){
        ans = ans + 1;
        d1.pop_front();
        d2.pop_front();
      }
      else if(q.first <= p.first && p.second <= q.second) {
        ans = ans + 1;
        d1.pop_front();
      }
      else if(p.first <= q.first && q.second <= p.second) {
        ans = ans + 1;
        d2.pop_front();
      }
      else if(p.first < q.first){
        ans = ans + 1;
        d1.pop_front();
      }
      else if(q.first < p.first){
        ans = ans + 1;
        d2.pop_front();
      }
      else assert(false);
    }
//    while(!d1.empty()) cout << d1.front().first << " " << d1.front().second << endl, d1.pop_front();
//    while(!d2.empty()) cout << d2.front().first << " " << d2.front().second << endl, d2.pop_front();
//    cout << ans << " " << d1.size() << " " << d2.size() << endl;
    ans = ans + d1.size() + d2.size();
    std::cout << "Case #" << __ << ": " << ans << '\n';
  }
  return 0;
}
