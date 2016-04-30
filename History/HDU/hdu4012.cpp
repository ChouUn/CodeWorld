//@ Including Header
// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#ifndef CSL_STD_H_
#define CSL_STD_H_ 20151122L
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<ll> vll;
typedef std::vector<pii> vpii;

template<typename _Tp>
bool uin(_Tp &a,_Tp b) {
  return a > b ? (a = std::move(b), true) : false;
}
template<typename _Tp>
bool uax(_Tp &a,_Tp b) {
  return a < b ? (a = std::move(b), true) : false;
}

#define rep(i,a,b) for(auto i=a,i##_n=b;i!=i##_n;++i)
#define rrep(i,a,b) for(auto i=b,i##_n=a;i--!=i##_n;)

#endif /* CSL_STD_H_ */


/**
 *  Name : hdu4012.cpp
 *  Date : 2015年11月28日 下午8:08:16
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 8
int n, f[1<<(maxn<<1)];
char s[maxn*2];

#define loop1 { \
  if((s[b] == s[i]) >= (stat >> i & 1)) { \
    stat &= ~(1 << i), \
    stat |= (s[b] == s[i]) << i; \
  } \
  else break; \
}

int color1(int b, int stat) {
  for (int i = b; i > -1; i -= 2) loop1;
  for (int i = b+2; i < 2*n; i += 2) loop1;
  return stat;
}

#define loop2 { \
  if((s[b] == s[i]) + (s[b] == s[i-1]) >= \
    (stat >> i & 1) + (stat >> (i-1) & 1)) { \
    stat &= ~(3 << (i-1)), \
    stat |= (s[b] == s[i]) << i, \
    stat |= (s[b] == s[i-1]) << (i-1); \
  } \
  else break; \
}

int color2(int b, int stat) {
  if (~b & 1) ++b;
  for (int i = b; i > -1; i -= 2) loop2;
  for (int i = b+2; i < 2*n; i += 2) loop2;
  return stat;
}

int bfs() {
  memset(f, 0xff, sizeof f);
  queue<int> q;
  f[0] = 0, q.push(0);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (u == (1 << 2*n) - 1) return f[u];
    for (int i = 2*n-1; i > -1; --i) {
      if (u & (1 << i)) continue;
      int v1 = color1(i, u), v2 = color2(i, u);
      if (f[v1] == -1) q.push(v1), f[v1] = f[u] + 1;
      if (f[v2] == -1) q.push(v2), f[v2] = f[u] + 1;
    }
  }
  return -1;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ <<": ";
    cin >> n;
    rep(i, 0, n) cin >> s[i<<1];
    rep(i, 0, n) cin >> s[i<<1|1];
    cout << bfs() << '\n';
  }
  return 0;
}
