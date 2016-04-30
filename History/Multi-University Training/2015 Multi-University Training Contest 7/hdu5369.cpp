//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5369.cpp
 *  Date : 2015年8月12日 上午11:37:18
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define mod 1000000007
#define maxn 10010
int n, w[maxn]; ll p;
vi g[maxn];

int dis[maxn], pre[maxn];
void bfs(const int& s) {
  memset(dis, 0xff, sizeof(dis));
  queue<int> q; q.push(s); dis[s] = 0; pre[s] = 0;
  while (!q.empty()) {
    register int u = q.front(); q.pop();
    rep(i, 0, (int)g[u].size()) {
      register int v = g[u][i];
      if (~dis[v]) continue;
      q.push(v); dis[v] = dis[u] + 1; pre[v] = u;
    }
  }
}

int cmp1(register int a, register int b) {
  for (; a != b; a = pre[a], b = pre[b])
    if (w[a] != w[b]) return w[a] > w[b] ? 1 : -1;
  return 0;
}

int cmp2(register int a, register int b) {
  int res = 0;
  for (; a != b; a = pre[a], b = pre[b])
    if (w[a] != w[b]) res = w[a] > w[b] ? 1 : -1;
  return res;
}

bool test(register int u, const int& s, const int& v) {
  for (; u != s; u = pre[u])
    if (u == v) return true;
  return false;
}

vector<int> tot1, tot2;
void solve(const int& s, vector<int>& tot) {
  // find starting vertex
  vi head; bfs(s);
  rep(i, 1, n+1) if (w[i]) {
    if (head.empty()) head.push_back(i);
    else {
      if (dis[i] > dis[head[0]]) head.clear(), head.push_back(i);
      else if (dis[i] == dis[head[0]]) {
        int tmp = cmp1(i, head[0]);
        if (tmp > 0) head.clear(), head.push_back(i);
        else if (tmp == 0) head.push_back(i);
      }
    }
  }

  // store head of ans
  tot.clear();
  for (int x = head[0]; x != s; x = pre[x]) tot.push_back(w[x]);
  tot.push_back(w[s]);

  // judge number of different sub-tree with starting vertex
  bool flag = false;
  rep(k, 0, (int)head.size()) {
    int y = 0;
    for (int x = head[k]; x != s; y = x, x = pre[x]);
    head[k] = y;
    if (k && head[k] != head[k-1]) {
      flag = true;
      break;
    }
  }

  // find destination vertex
  int c = 0, y = (flag == false) ? head[0] : 0;
  rep(i, 1, n+1) {
    if (y && test(i, s, y)) continue;
    if (dis[i] > dis[c]) c = i;
    else if (dis[i] == dis[c] && cmp2(i, c) > 0) c = i;
  }

  // store tail of ans
  static stack<int> p;
  for (; c != s; c = pre[c]) p.push(w[c]);
  while (!p.empty()) tot.push_back(p.top()), p.pop();
}

void print(const vector<int>& tot) {
    ll ans = 0;
    rep(i, 0, (int)tot.size())
      ans = (ans * p % mod + tot[i]) % mod;
    printf(i64 "\n", ans);

    bool flag = false;
    rep(i, 0, (int)tot.size()) {
      if (flag) printf(" "); flag = true; printf("%d", tot[i]);
    }
    printf("\n");
}

//@ Main Function
int main() {
  int _, __ = 0;
  //for (; scanf("%d", &_) != EOF; ) {
  for (scanf("%d", &_); _; _--) {
    printf("Case #%d: ", ++__);

    // input & build
	scanf("%d" i64, &n, &p); p %= mod;
	rep(i, 1, n+1) g[i].clear();
	rep(i, 1, n) {
	  int u, v; scanf("%d%d", &u, &v);
	  g[u].push_back(v); g[v].push_back(u);
	}
	rep(i, 1, n+1) scanf("%d", &w[i]);

	// find middle vertex y(z) of tree
	bfs(1);
	int x = 1; rep(i, 1, n+1) x = dis[i] > dis[x] ? i : x;
	bfs(x);
	int y = 1; rep(i, 1, n+1) y = dis[i] > dis[y] ? i : y;
	int z = dis[y] & 1;
	for (x = dis[y] / 2; x; --x) y = pre[y];
	if (z) z = pre[y];

	// solve & compare
	solve(y, tot1);
	if (z) {
	  solve(z, tot2);
      if (tot2.size() > tot1.size()) print(tot2);
      else if (tot2.size() == tot1.size() && tot2 > tot1) print(tot2);
      else print(tot1);
	}
	else print(tot1);
  }
  return 0;
}
