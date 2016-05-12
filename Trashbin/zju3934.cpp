//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju3934.cpp
 *  Date : 2016年4月16日 下午8:42:19
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 110
#define M 5000
#define K 9
#define P 1000000007

unordered_map<int,int> h[K];

void dfs(int k, int id, int m) {
  static int d[K], e[K];
  if (m == 0) {
    rep(i, 0, id) rep(j, 0, k)
      if (d[i] & (1 << j)) e[k - j - 1] = i + 1;
    int x = accumulate(e, e + k, 0, [](int x, int y) -> int {
      return x * 10 + y;
    }), y = h[k].size();
    h[k][x] = y; return;
  }
  rep(i, 0, m + 1) {
    if ((i & m) != i || (i ^ m) > i) continue;
    d[id] = i, dfs(k, id + 1, m ^ i);
  }
}

inline void update(int& x, int y, bool& flag)
{ flag |= (x && x != y), x = y; }

int d[K];

void split(int x, int k)
{ per(i, 0, k) d[i] = x % 10, x /= 10; }

int relabel(int k) {
  static int e[K], en, res;
  memset(e, 0x00, sizeof e), en = 0, res = 0;
  rep(i, 1, k+1) res = res * 10 + (e[d[i]] ? e[d[i]] : (e[d[i]] = ++en));
  return res;
}

void update(int& x, ll y)
{ x = (x + y) % P; }

int g[N][K];
int f[N][M];
vector<bool> v;

//@ Main Function
int main() {
  rep(i, 2, K) dfs(i, 0, (1 << i) - 1);

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m, k; cin >> n >> m >> k;

    memset(g, 0x00, sizeof g);
    bool flag = false;
    while (m--) {
      int x, y, z; cin >> x >> y >> z; --x, --y;
      if (x > y) swap(x, y);
      if (x == y && x + z < n) flag = true;
      rep(i, 0, z) update(g[y + i][y - x], 1, flag);
      if (y + z < n) update(g[y + z][y - x], 2, flag);
    }
    if (flag) { cout << 0 << '\n'; continue; }

    f[0][h[k].size() - 1] = 26;
    rep(i, 0, n - 1) {
      memset(f[i+1], 0x00, sizeof f[i+1]);
      for (auto& hi : h[k]) {
        int s = hi.second;
        if (!f[i][s]) continue;
        split(hi.first, k);

        v.assign(k + 1, true);
        rep(j, 1, k + 1) {
          if (i + 1 - j < 0) continue;
          if (g[i+1][j] == 1)
          { rep(l, 1, k + 1) if (l != d[k - j]) v[l] = false; }
          else if (g[i+1][j] == 2)
          { rep(l, 1, k + 1) if (l == d[k - j]) v[l] = false; }
        }

//        cout << i << ", " << s << ", " << hi.first << " : ";
//        rep(j, 1, k + 1) cout << g[i+1][j] << " "; cout << ", ";
//        rep(j, 1, k + 1) cout << v[j] << " "; cout << endl;
        int up = accumulate(d, d + k, 1, [](int a, int b) -> int {
          return max(a, b);
        });
        rep(j, 1, min(up + 1, k) + 1) {
          if (!v[j]) continue;
          d[k] = j;
          int t = h[k][relabel(k)];
//          cout << "t = " << t << endl;
          update(f[i+1][t], f[i][s] * (j <= up ? 1ll : 26ll - up));
        }
      }
    }
//    rep(i, 0, n) {
//      cout << "i = " << i << endl;
//      rep(j, 0u, h[k].size()) cout << j << " " << f[i][j] << endl;
//    }
    int ans = 0;
    for (auto& hi : h[k]) update(ans, f[n-1][hi.second]);
    cout << ans << endl;
  }
  return 0;
}
