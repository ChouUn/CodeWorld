//@ Including Header
#include <csl_std.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

/*
 *  Name : hdu5249-3.cpp
 *  Date : 2015年8月8日 上午9:53:05
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef __gnu_pbds::tree<
    int,
    __gnu_pbds ::null_type,
    std::less<int>,
    __gnu_pbds ::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update,
    std::allocator<char>> rb_tree;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    std::cout << "Case #" << __ <<":\n";
    rb_tree p;
    std::queue<int> q;
    while (n--) {
      char s[10]; cin >> s; int x;
      switch (s[0]) {
        case 'i': cin >> x; q.push(x), p.insert(x); break;
        case 'o': x = q.front(), q.pop(), p.erase(x); break;
        case 'q': cout << *p.find_by_order(p.size()/2) << '\n'; break;
      }
    }
  }
  return 0;
}
