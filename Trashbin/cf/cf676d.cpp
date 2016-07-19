//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf676d.cpp
 *  Date : 2016年5月25日 下午11:44:19
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 1010;
const int M = 128;
char a[M][4];
bool b[M][4];

int n, m;
char g[N][N];
bool f[N][N][4];

struct point {
  int x, y, z, t;

  point() : x(), y(), z(), t() {}
  point(int x, int y) : x(x), y(y), z(), t() {}
  point(int x, int y, int z, int t) : x(x), y(y), z(z), t(t) {}

  inline bool check() const {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  inline point go(int d) const {
    static int p[5][3] = {{-1, 0, 0}, {0, +1, 0}, {+1, 0, 0}, {0, -1, 0}, {0, 0, +1}};
    return point(x + p[d][0], y + p[d][1], (z + p[d][2]) % 4, t + 1);
  }

  pair<bool,point> link(int d) const {
    pair<bool,point> res(false, point());
    int c = g[x][y]; c = a[c][z];
    if (!b[c][d]) return res;
    point l = this->go(d);
    if (!l.check()) return res;
    int e = g[l.x][l.y]; e = a[e][z];
    if (!b[e][(d + 2) % 4]) return res;
    return make_pair(true, l);
  }
} s, t;

int bfs() {
  queue<point> q;
  q.push(s); f[s.x][s.y][s.z] = 1;
  while (!q.empty()) {
    point u = q.front(); q.pop();
    if (u.x == t.x && u.y == t.y) return u.t;
    rep(d, 0, 5) {
      point v;
      if (d == 4) v = u.go(d);
      else {
        auto it = u.link(d);
        if (!it.first) continue;
        v = it.second;
      }
      if (!f[v.x][v.y][v.z]) q.push(v), f[v.x][v.y][v.z] = 1;
    }
  }
  return -1;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  a['+'][0] = a['+'][1] = a['+'][2] = a['+'][3] = '+';
  a['-'][0] = a['-'][2] = a['|'][1] = a['|'][3] = '-';
  a['-'][1] = a['-'][3] = a['|'][0] = a['|'][2] = '|';
  a['^'][0] = a['>'][3] = a['v'][2] = a['<'][1] = '^';
  a['^'][1] = a['>'][0] = a['v'][3] = a['<'][2] = '>';
  a['^'][2] = a['>'][1] = a['v'][0] = a['<'][3] = 'v';
  a['^'][3] = a['>'][2] = a['v'][1] = a['<'][0] = '<';
  a['U'][0] = a['R'][3] = a['D'][2] = a['L'][1] = 'U';
  a['U'][1] = a['R'][0] = a['D'][3] = a['L'][2] = 'R';
  a['U'][2] = a['R'][1] = a['D'][0] = a['L'][3] = 'D';
  a['U'][3] = a['R'][2] = a['D'][1] = a['L'][0] = 'L';
  a['*'][0] = a['*'][1] = a['*'][2] = a['*'][3] = '*';

  b['+'][0] = b['+'][1] = b['+'][2] = b['+'][3] = 1;
  b['-'][1] = b['-'][3] = b['|'][0] = b['|'][2] = 1;
  b['^'][0] = b['>'][1] = b['v'][2] = b['<'][3] = 1;
  b['R'][0] = b['D'][0] = b['L'][0] = 1;
  b['D'][1] = b['L'][1] = b['U'][1] = 1;
  b['L'][2] = b['U'][2] = b['R'][2] = 1;
  b['U'][3] = b['R'][3] = b['D'][3] = 1;

  cin >> n >> m;
  rep(i, 0, n) rep(j, 0, m) cin >> g[i][j];
  cin >> s.x >> s.y >> t.x >> t.y; --s.x, --s.y, --t.x, --t.y;
  cout << bfs() << endl;

  return 0;
}
