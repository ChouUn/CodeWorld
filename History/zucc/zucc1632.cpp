//@ Including Header
#include <csl_std.h>
#include <csl_math.h>
#include <fft.h>

/**
 *  Name : zucc1632.cpp
 *  Date : 2016年3月27日 下午7:48:04
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 100010

int x[N], y[N << 2], sum[N << 2];
ll z[N << 2];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    rep(i, 0, n) cin >> x[i];

    int m = accumulate(x + 0, x + n, 0, [](int a, int b) -> int { return std::max(a, b); }) + 1;
    rep(i, 0, m) y[i] = 0;
    rep(i, 0, n) ++y[x[i]];
    rep(i, 0, m) sum[i] = i ? sum[i - 1] + y[i] : 0;

    vector<double> a(y, y + m);
    vector<double> b = csl::fft<>()(a, a);

    int l = b.size();
    rep(i, 0, l) z[i] = b[i] + 0.1;
    rep(i, 0, l) z[i] = (z[i] - (i & 1 ? 0 : y[i / 2])) / 2;

    ll cnt = ll(n) * (n - 1) / 2 * (n - 2) / 3, ans = cnt;
    rep(i, 2, m) ans -= z[i] * (n - sum[i - 1]);
    cout << setprecision(7) << setiosflags(ios::fixed) << (double)ans / cnt << endl;
  }
  return 0;
}
