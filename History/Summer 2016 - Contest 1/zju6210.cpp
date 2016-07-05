//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6210.cpp
 *  Date : 2016年7月5日 上午9:45:13
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 210;
const ll P = 1000000007;

int d[N];
vi g[N];
ll f[N][2], h[N][2];

map<string,int> ss;
int encode(string& s) {
  auto it = ss.find(s);
  if (it != ss.end()) return it->second;
  return ss[s] = ss.size();
}

void dfs(int u) {
  f[u][0] = 1, h[u][0] = 0;
  f[u][1] = 1, h[u][1] = 1;
  for (auto v : g[u]) {
    dfs(v);
    if (h[v][0] == h[v][1]) {
      f[u][0] = f[u][0] * (f[v][1] + f[v][0]) % P;
      h[u][0] = h[u][0] + h[v][0];
    }
    else if (h[v][0] > h[v][1]) {
      f[u][0] = f[u][0] * f[v][0] % P;
      h[u][0] = h[u][0] + h[v][0];
    }
    else {
      f[u][0] = f[u][0] * f[v][1] % P;
      h[u][0] = h[u][0] + h[v][1];
    }
    f[u][1] = f[u][1] * f[v][0] % P;
    h[u][1] = h[u][1] + h[v][0];
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    ss.clear();
    int n; cin >> n;
    rep(i, 0, N) g[i].clear(), d[i] = 0;
    rep(i, 0, n) {
      string a, b; cin >> a >> b;
      int x = encode(a), y = encode(b);
//      cout << x << " " << y << endl;
      g[y].push_back(x), ++d[x];
    }

    int m = ss.size();
    rep(i, 1, m + 1) if (!d[i]) g[0].push_back(i);
    dfs(0);
    cout << h[0][0] << " " << f[0][0] << endl;
  }
  return 0;
}
