//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5397.cpp
 *  Date : 2015年8月18日 下午9:10:43
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef long double ld;
#define maxn 5
ll p, q, r, b;
ll g[maxn*4];
int h[maxn];
pii f[maxn*2]; int n;

inline ll mul(const ll &a, const ll &b) {
  ll c = a * b - ll(ld(a) * b / r) * r;
  return (c % r + r) % r;
}

void bfs(int s, int c) {
  queue<int> q; q.push(s); h[s] = c;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    int x = f[u].first;
    int y = f[u].second;
    if (x == y) continue;
    q.push(x); h[x] = h[u];
    q.push(y); h[y] = -h[u];
  }
}

//@ Main Function
int main() {
  while (scanf(i64 i64 i64 i64, &p, &q, &r, &b) != EOF) {
    p %= r, q %= r, b %= r, n = maxn;;
    g[0] = 1; rep(i, 1, maxn*4) g[i] = mul(g[i-1], b);
    rep(i, 0, maxn) f[i] = make_pair(i,i), h[i] = 0;

    int ans = false;
    map<ll,int> m;
    rep(i, 0, maxn) {
      ll id = (mul(p-q, g[4*i+1]) + mul(q-p, g[4*i+2])) % r;
      map<ll,int>::iterator it = m.find(id);
      if (it != m.end()) {
        h[i] = 1, h[it->second] = -1;
        ans = true;
        break;
      }
      m[id] = i;
    }

    if (!ans)
    while (m.size() > 1) {
      map<ll,int>::iterator i = --m.end(), j = i--;
      ll x = i->first, y = j->first, z = y - x;
      int p = i->second, q = j->second;
      m.erase(i), m.erase(j);
      f[n++] = make_pair(q, p);

      i = m.find(z);
      if (i != m.end()) {
        bfs(n-1, 1), bfs(i->second, -1);
        ans = true; break;
      }
      m[z] = n-1;
    }

    assert(ans == true);
    rep(i, 0, maxn) printf(h[i] >= 0 ? "(())" : "()()"); printf("\n");
    rep(i, 0, maxn) printf(h[i] <= 0 ? "(())" : "()()"); printf("\n");
  }
  return 0;
}
