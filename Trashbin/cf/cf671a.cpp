//@ Including Header
#include <csl_std.h>

/**
 *  Name : cf671a.cpp
 *  Date : 2016年5月12日 上午10:56:28
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
pii p[N];
double cnt, pre[N], suf[N];

double dis(pii a, pii b) {
  double x = a.first - b.first, y = a.second - b.second;
  return sqrt(x * x + y * y);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  pii a, b, t; cin >> a >> b >> t;
  int n; cin >> n;
  rep(i, 1, n + 1) cin >> p[i];
  sort(p + 1, p + n + 1);

  cnt = pre[0] = suf[n + 1] = 0.;
  rep(i, 1, n + 1) cnt += dis(t, p[i]) * 2;
  rep(i, 1, n + 1) pre[i] = min(pre[i - 1], dis(a, p[i]) - dis(t, p[i]));
  per(i, 1, n + 1) suf[i] = min(suf[i + 1], dis(a, p[i]) - dis(t, p[i]));

  double ans = INFINITY;
  rep(i, 1, n + 1) ans = min(ans, cnt + dis(a, p[i]) - dis(t, p[i]));
  rep(i, 1, n + 1) ans = min(ans, cnt + dis(b, p[i]) - dis(t, p[i]) + min(pre[i - 1], suf[i + 1]));
  cout << setprecision(9) << fixed << ans << endl;

  return 0;
}
