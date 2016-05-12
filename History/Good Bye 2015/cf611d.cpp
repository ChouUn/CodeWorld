//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf611d.cpp
 *  Date : 2015年12月31日 上午4:03:53
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define M 1000000007
#define N 5010
int n; char s[N];
int f[N][N], g[N][N], h[N][N];

inline int cmp(int i, int j, int k) {
  return (g[i][j] >= k) ? 0 : (s[i+g[i][j]] < s[j+g[i][j]]) ? -1 : 1;
}

inline int get(int a[], int j) {
  return j >= 0 ? a[j] : 0;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> s;
  per(i, 0, n) per(j, 0, n) {
    g[i][j] = (s[i] == s[j]) ? (g[i+1][j+1] + 1) : 0;
  }

  rep(i, 1, n+1) {
    rep(j, 0, i) {
      if(s[j] == '0') continue;
      if(j == 0) f[i][j] = 1;
      int k = j + j - i;
      if(k >= 0 && cmp(k, j, i - j) < 0) f[i][j] = (f[i][j] + f[j][k]) % M;
      f[i][j] = ((f[i][j] + get(h[j], j-1) - get(h[j], k)) % M + M) % M;
    }
    rep(j, 0, n+1) h[i][j] = (f[i][j] + get(h[i], j-1)) % M;
  }
  cout << h[n][n] << endl;
  return 0;
}
