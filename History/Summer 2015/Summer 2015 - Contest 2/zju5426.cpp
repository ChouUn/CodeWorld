//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju5426.cpp
 *  Date : 2016年3月23日 下午7:14:53
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 1010
#define M 1010
struct node {
  string name;
  int score[M];
} a[N], *b[N];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m; cin >> n >> m;
    rep(i, 0, n) {
      node& x = a[i];
      cin >> x.name;
      rep(j, 0, m) cin >> x.score[j];
      b[i] = a + i;
    }
    int k = 0;
    while (n) {
      nth_element(b, b + n - 1, b + n, [&k](node* a, node* b) -> bool {
        return a->score[k] != b->score[k] ? a->score[k] < b->score[k] : a->name < b->name;
      });
      cout << b[--n]->name << " ";
      nth_element(b, b + n - 1, b + n, [&k](node* a, node* b) -> bool {
        return a->score[k] != b->score[k] ? a->score[k] > b->score[k] : a->name > b->name;
      });
      cout << b[--n]->name << endl;
      k = (k + 1) % m;
    }
  }
  return 0;
}
