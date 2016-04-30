//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5370.cpp
 *  Date : 2015年8月13日 上午9:58:29
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 510
#define mod 1000000007
struct node {
  node *p, *l, *r;
  int size;
  node(node* a, int b) : p(a), l(), r(), size(b) { }
  ~node() {
    if (l) delete l;
    if (r) delete r;
  }
};
ll f[maxn], dp[maxn][maxn];

int node_cnt, leaf_cnt;
queue<node*> q;

void dfs(node* u) {
  --node_cnt;
  if (u->l)
    if (u->l->size) q.push(u->l);
    else dfs(u->l);
  else ++leaf_cnt;
  if (u->r)
    if (u->r->size) q.push(u->r);
    else dfs(u->r);
  else ++leaf_cnt;
}

inline ll solve(node* root) {
  register ll ans = 1; q.push(root);
  while (!q.empty()) {
    node* u = q.front(); q.pop();
    node_cnt = u->size, leaf_cnt = 0;
    dfs(u);
    ans = ans * dp[leaf_cnt][node_cnt] % mod;
  }
  return ans;
}

inline void init() {
  f[0] = dp[0][0] = 1;
  rep(i, 1, maxn) {
    register ll tmp = 0;
    rep(j, 0, i)
      tmp = (tmp + f[j] * f[i-1-j] % mod) % mod;
    f[i] = tmp;
  }

  rep(i, 1, maxn) rep(j, 0, maxn) {
    register ll tmp = 0;
    rep(k, 0, j+1)
    tmp = (tmp + dp[i-1][j-k] * f[k] % mod) % mod;
    dp[i][j] = tmp;
  }
}

//@ Main Function
int main() {
  init();
  int __ = 0;
  //for (; scanf("%d", &_) != EOF; ) {
  for (int n; scanf("%d", &n) != EOF; ) {
    printf("Case #%d: ", ++__);
    node *root = new node(0, 1), *cur = root;
    while (n--) {
      int x, y; scanf("%d", &x);
      switch (x) {
        case 0 : cur = cur->p; break;
        case 1 : if (!cur->l) cur->l = new node(cur, 0); cur = cur->l; break;
        case 2 : if (!cur->r) cur->r = new node(cur, 0); cur = cur->r; break;
        case 3 : scanf("%d", &y); cur->l = new node(cur, y); break;
        case 4 : scanf("%d", &y); cur->r = new node(cur, y); break;
        default : clog << "error input" << endl;
      }
    }
    printf(i64 "\n", solve(root));
    delete root;
  }
  return 0;
}
