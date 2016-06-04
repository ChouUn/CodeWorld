//@ Including Header
#include <csl_std.h>

/**
 *  Name : T1.cpp
 *  Date : 2016年5月28日 下午9:59:52
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

int n, r, p, s;
int t[256];

string dfs(int l, int r, int c) {
//  cout << l << " " << r << " " << c << endl;
  if (l == r) {
    return string(1, char(c));
  }
  int m = (l + r) >> 1;
  string x = dfs(l, m, c);
  string y = dfs(m + 1, r, t[c]);
  if (x > y) swap(x, y);
  return x + y;
}

bool count(string& str) {
  int rr = 0, ss = 0, pp = 0;
  for (auto c : str) {
    if (c == 'R') ++rr;
    if (c == 'S') ++ss;
    if (c == 'P') ++pp;
  }
  return rr == r && ss == s && pp == p;
}

string check() {
  string res = "Z";
  string x = dfs(1, 1 << n, 'R');
//  cout << x << endl;
  if (count(x)) res = min(res, x);
  string y = dfs(1, 1 << n, 'S');
//  cout << y << endl;
  if (count(y)) res = min(res, y);
  string z = dfs(1, 1 << n, 'P');
//  cout << z << endl;
  if (count(z)) res = min(res, z);
  return res;
}

//@ Main Function
int main() {
  t['R'] = 'S'; t['S'] = 'P'; t['P'] = 'R';
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ": ";
    cin >> n >> r >> p >> s;
    string ans = check();
    cout << (ans == "Z" ? "IMPOSSIBLE" : ans) << endl;
  }
  return 0;
}
