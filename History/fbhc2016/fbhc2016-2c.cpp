//@ Including Header
#include <csl_std.h>

/**
 *  Name : fbhc2016-2c.cpp
 *  Date : 2016年1月17日 下午2:49:02
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

double solve(vector<ll>& v, ll m) {
  double res = 0;
  for(auto& x : v) res += pow(min(m, x), 2) / 2., m -= min(m, x);
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    int n, a, b; cin >> n >> a >> b;
    vector<ll> v(n);
    ll cnt = 0;
    rep(i, 0, n) cin >> v[i], cnt += v[i];
    double sum = solve(v, cnt);
    double y = solve(v, a % cnt) + a / cnt * sum;
    double z = solve(v, b % cnt) + b / cnt * sum;
    std::cout << "Case #" << __ << ": ";
    cout << setprecision(9) << setiosflags(ios::fixed) << (z - y) / (b - a) << endl;
  }
  return 0;
}
