/*
 *	Name : BC44B.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年6月14日 上午10:07:04
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <csl_std.h>
//@ Using Namespace
//using namespace std;
//@ The magic ends here.

#define maxn 50010
#define mod 998244353LL
struct node {
  node* pnt[2];
  int cnt;
  node() : cnt() { pnt[0] = pnt[1] = 0; }
};
node tree[maxn*30]; int size;

void add(node* n, int x, int d) {
  if (d >= 30) return;
  n->cnt++;
  if (!n->pnt[x&1]) {
    tree[size] = node();
    n->pnt[x&1] = &tree[size++];
  }
  add(n->pnt[x&1], x>>1, d+1);
}

int64 count(node* n, int x, int d) {
  if (d >= 30) return 0;
  int64 res = 0; int t = x&1;
  if (n->pnt[t^1]) res += n->pnt[t^1]->cnt * (1 << d);
  if (n->pnt[t]) res += count(n->pnt[t], x>>1, d+1);
  return res % mod;
}

//@ Main Function
int main() {
  int _, __ = 0;
  for (scanf("%d", &_); _; _--) {
    printf("Case #%d: ", ++__);
    int n; scanf("%d", &n);
    size = 1; tree[0] = node();
    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      int x; scanf("%d", &x);
      add(tree, x, 0);
      ans += count(tree, x, 0);
      ans %= mod;
    }
    ans = (ans * 2) % mod;
    printf(i64 "\n", ans);
  }
  return 0;
}
