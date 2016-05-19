//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf671c.cpp
 *  Date : 2016年5月13日 下午5:51:18
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 200010;
int a[N], b[N];
map<int,int> s;
ll ans = 0, cnt = 0;

void add(int l, int r) {
  if (l > r) return;
  auto p = --s.upper_bound(l);
  if (r <= p->second) return;
  s[l] = r;
  int x = l, y = p->second;
  while (true) {
    p = s.upper_bound(l);
    cnt -= y * ( - x)
  }
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; cin >>n;
  rep(i, 1, n + 1) cin >> a[i], b[a[i]] = i;
  rep(i, 1, n + 1) s[i] = i - 1; s[0] = 0; s[n + 1] = n + 1;

  per(i, 1, N) {
    vi p;
    for (int j = i; j < N; j += i) if (b[j]) p.push_back(b[j]);
    if (p.size() > 1) {
      int m = p.size();
      add(1, p[m - 2] - 1);
      add(p[0] + 1, p[m - 1] - 1);
      add(p[1] + 1, n);
    }
  }

  return 0;
}
