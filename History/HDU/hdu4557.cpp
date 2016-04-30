//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu4557.cpp
 *  Date : 2016年4月26日 下午4:01:39
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

struct node {
  int value, order;
  string name;
  friend bool operator < (const node& a, const node& b) {
    return a.value != b.value ? a.value < b.value : a.order < b.order;
  }
};

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ":\n";
    set<node> s;

    int q; cin >> q;
    rep(k, 1, q + 1) {
      string op; cin >> op;
      if (op == "Add") {
        node m; cin >> m.name >> m.value; m.order = k;
        s.insert(m), cout << s.size() << '\n';
      }
      else if (op == "Find") {
        node m; cin >> m.value; m.order = 0;
        auto it = s.lower_bound(m);
        if (it == s.end()) cout << "WAIT...\n";
        else cout << it->name << '\n', s.erase(it);
      }
    }
  }
  return 0;
}
