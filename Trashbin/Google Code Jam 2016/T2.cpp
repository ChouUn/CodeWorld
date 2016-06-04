//@ Including Header
#include <csl_std.h>

/**
 *  Name : T2.cpp
 *  Date : 2016年5月28日 下午10:58:45
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 210;
const double eps = 1e-9;
int n, k;
double p[N], q[N];
double ans;

void dfs(int id, int kk, const map<int,double>& s) {
//  cout << id << " " << kk << endl;
  if (kk < 0 || n - id < kk) return;
  if (id == n) {
//    cout << id << " " << kk << " : ";
//    for (auto si : s) cout << "(" << si.first << "," << si.second << "), ";
//    cout << endl;
    auto it = s.find(k / 2);
    ans = max(ans, it->second);
    return;
  }
  dfs(id + 1, kk, s);
  map<int,double> t;
  for (auto si : s) {
    t[si.first] += si.second * (1 - p[id]);
    t[si.first + 1] += si.second * p[id];
  }
  dfs(id + 1, kk - 1, t);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    cin >> n >> k;
    rep(i, 0, n) cin >> p[i];
    ans = 0;
    map<int,double> s; s[0] = 1; dfs(0, k, s);
    std::cout << "Case #" << __ << ": " << ans << endl;
  }
  return 0;
}
