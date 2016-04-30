//@ Including Header
#include <csl_std.h>

/**
 *  Name : usaco2016JanS-c.cpp
 *  Date : 2016年1月18日 下午9:56:09
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

map<pii,bool> m;
int xmin = 0, xmax = 0, ymin = 0, ymax = 0;
void dfs(int x, int y) {
  if(x < xmin || x > xmax) return;
  if(y < ymin || y > ymax) return;
  if(m[make_pair(x,y)]) return; m[make_pair(x,y)] = true;
  dfs(x-1, y), dfs(x+1, y);
  dfs(x, y-1), dfs(x, y+1);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ifstream in("gates.in");
  ofstream out("gates.out");

  int n; in >> n;
  pii s(0,0); m[s] = true;
  while(n--) {
    char ch; in >> ch;
    switch(ch) {
      case 'N': s.first -= 2; break;
      case 'S': s.first += 2; break;
      case 'W': s.second -= 2; break;
      case 'E': s.second += 2; break;
    }
    xmin = min(xmin, s.first);
    xmax = max(xmax, s.first);
    ymin = min(ymin, s.second);
    ymax = max(ymax, s.second);
  }
  --xmin, ++xmax, --ymin, ++ymax;
  int ans = 0;
  for(int i = xmin; i <= xmax; ++i)
    for(int j = ymin; j <= ymax; ++j) ++ans, dfs(i, j);
  out << ans - 1 << endl;
  return 0;
}
