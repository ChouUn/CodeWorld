//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5374.cpp
 *  Date : 2015年8月11日 下午2:21:27
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int f[3][4][4][4] = { 
  { {1,1,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0}, },
  { {1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0},
    {1,1,1,1, 0,0,0,0, 0,0,0,0, 0,0,0,0}, },
  { {1,1,1,0, 1,0,0,0, 0,0,0,0, 0,0,0,0},
    {1,0,0,0, 1,0,0,0, 1,1,0,0, 0,0,0,0},
    {0,0,1,0, 1,1,1,0, 0,0,0,0, 0,0,0,0},
    {1,1,0,0, 0,1,0,0, 0,1,0,0, 0,0,0,0}, },
};

#define maxn 1010
int n, x, y, r, p, q;
int a[maxn]; char s[maxn];
bool g[30][30];

inline int ns(int p, int q) {
  if (p == 1) return (q + 1) & 1;
  else return p ? (q + 1) & 3 : 0;
}

bool test(int x, int y, int p, int q) {
  rep(i, 0, 4) rep(j, 0, 4) {
    if (g[x+i][y+j] && f[p][q][i][j]) return false;
  }
  return true;
}

bool dis(int x) {
  if (x < 1 || x > 12) return false;
  int flag = true;
  rep(j, 1, 10) flag &= g[x][j];
  if (flag) {
    rep(i, x, 12) rep(j, 1, 10) g[i][j] = g[i+1][j];
    rep(j, 1, 10) g[12][j] = 0;
    return true;
  }
  return false;
}

void put(int x, int y, int p, int q) {
  rep(i, 0, 4) rep(j, 0, 4) g[x+i][y+j] |= f[p][q][i][j];
}

//@ Main Function
int main() {
  int _, __ = 0;
  //for (; scanf("%d", &_) != EOF; ) {
  for (scanf("%d", &_); _; _--) {
    printf("Case %d: ", ++__);

    scanf("%d%s", &n, s); int m = strlen(s);
    rep(i, 0, n) scanf("%d", a+i);

    memset(g, 0x01, sizeof(g));
    rep(i, 1, 13) rep(j, 1, 10) g[i][j] = 0;

    int ans = 0;
    x = 9, y = 4, r = 0, p = a[r], q = 0;
    rep(i, 0, m) {
      switch (s[i]) {
        case 'w' : if (test(x, y, p, ns(p, q))) q = ns(p, q); break;
        case 'a' : if (test(x, y - 1, p, q)) y = y - 1; break;
        case 's' : if (test(x - 1, y, p, q)) x = x - 1; break;
        case 'd' : if (test(x, y + 1, p, q)) y = y + 1; break;
        case 'p' : break;
        default : assert(0);
      }
      if (test(x - 1, y, p, q)) {
        x = x - 1;
        continue;
      }
      put(x, y, p, q);
      rep(k, 0, 4) while (dis(x+k)) ++ans;
      x = 9, y = 4, r = r + 1, p = a[r], q = 0;
      if (!test(x, y, p, q)) break;
      if (r == n) break;
    }
    printf("%d\n", ans);
  }
  return 0;
}
