//@ Including Header
#include <csl_std.h>
#include <BigDec.h>

/**
 *  Name : hdu5235.cpp
 *  Date : 2015年11月24日 上午1:11:12
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 4010
#define T 60010
#define M 1000000
typedef csl::BigDec< csl::array<std::uint32_t,25> > bint;

struct node {
  ll n, ret;
  int k, idx;
  static bool cmpk(const node& a, const node& b)
  { return a.k < b.k; }
  static bool cmpi(const node& a, const node& b)
  { return a.idx < b.idx; }
};

int _;
node a[T];
bint f[N];
ll dp[N];
int g[M];

void init() {
  f[0] = 0, f[1] = 1, dp[0] = 0, g[0] = 0;
  rep(i, 1, M) g[i] = g[i/10] + i%10;
}

void input() {
  cin >> _;
  rep(i, 0, _) cin >> a[i].n >> a[i].k, a[i].idx = i, a[i].ret = 0;
  std::sort(a, a+_, node::cmpk);
}

int count(const bint& n) {
  int ret = 0, m = n.size();
  rep(i, 0, m) {
    int t = n[i];
    ret += g[t / M] + g[t % M];
  }
  return ret;
}

void solve(int m, int n) {
  rep(i, 2, m+1) f[i] = f[i-1] + f[i-2];
  bint fk = f[m];
  rep(i, m, n+1) {
    f[i] = f[i-1] + f[i-2];
    while(f[i] >= fk) f[i] -= fk;
  }
  rep(i, 1, n+1) dp[i] = dp[i-1] + count(f[i]);
}

void output() {
  std::sort(a, a + _, node::cmpi);
  rep(i, 0, _) cout << "Case #" << i+1 << ": " << a[i].ret << "\n";
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  init();
  input();
  rep(i, 0, _) {
    if(a[i].k < 3) continue;
    int m = a[i].k, n = m * (m & 1 ? 4 : 2);
    if(!(i && m == a[i-1].k)) solve(m, n);
    a[i].ret = a[i].n / n * dp[n] + dp[a[i].n % n];
  }
  output();
  return 0;
}
