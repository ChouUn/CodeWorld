//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5249-1.cpp
 *  Date : 2015年8月5日 下午10:18:37
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

struct channel {
private :
  set<int> head, tail;
  set<int>::iterator it;
  deque<int> order;
public :
  void clear() {
    head.clear();
    tail.clear();
    order.clear();
  }
  void insert(int x) {
    if(head.empty() || x > *head.rbegin()) tail.insert(x);
    else head.insert(x);
    order.push_back(x);
  }
  void erase() {
    if(order.empty()) return;
    int x = order.front(); order.pop_front();
    it = head.find(x); if(it != head.end()) head.erase(it);
    it = tail.find(x); if(it != tail.end()) tail.erase(it);
  }
  void query() {
    while(tail.size() < head.size()) {
      it = --head.end();
      tail.insert(*it);
      head.erase(it);
    }
    while(tail.size() > head.size() + 1) {
      it = tail.begin();
      head.insert(*it);
      tail.erase(it);
    }
    if(!tail.empty()) cout << *tail.begin() << '\n';
  }
} q;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    std::cout << "Case #" << __ <<":\n";
    q.clear();
    while(n--) {
      char s[10]; cin >> s;
      int x;
      switch(s[0]) {
        case 'i': cin >> x; q.insert(x); break;
        case 'o': q.erase(); break;
        case 'q': q.query(); break;
      }
    }
  }
  return 0;
}
