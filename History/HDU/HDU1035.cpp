/*
 *	Name : HDU1035.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月30日 上午9:09:36
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <string.h>
#include <iostream>
#include <queue>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 20

const int dir[][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1},
};
int n, m, k;
int g[maxN][maxN];
int f[maxN][maxN];

void Init() {
  memset(g, -1, sizeof(g));
  memset(f, -1, sizeof(f));
}

void Input() {
  cin >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char ch; cin >> ch;
      switch (ch) {
        case 'N' : g[i][j] = 0; break;
        case 'E' : g[i][j] = 1; break;
        case 'S' : g[i][j] = 2; break;
        case 'W' : g[i][j] = 3; break;
      }
    }
}

void Solve() {
  int x = 1, y = k, t = 0;
  f[x][y] = 0;
  while (g[x][y] != -1) {
    int d = g[x][y];
    x += dir[d][0];
    y += dir[d][1];
    t += 1;
    if (f[x][y] > -1) {
      cout << f[x][y] << " step(s) before a loop of ";
      cout << t - f[x][y] << " step(s)" << endl;
      return;
    }
    f[x][y] = t;
  }
  cout << t << " step(s) to exit" << endl;
}

//@ Main Function
int main() {
  while (cin >> n >> m && n && m) {
    Init();
    Input();
    Solve();
  }
  return 0;
}
