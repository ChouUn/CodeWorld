//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1059.cpp
 *  Date : 2016年5月10日 上午3:48:55
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

int a[10]; vi b;
bitset<120010> f;

inline void cast(int l, int r) {
  int m = l / __gcd(l, r) * r, p = m / l, q = m / r, t = (a[l] - p + 1) / p;
  a[r] += t * q, a[l] -= t * p;
}

void split(int p, int k) {
  for (int q = 1, t; p; p -= t, q <<= 1) t = min(p, q), b.push_back(t * k);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(; true; --_, ++__) {
    bool flag = false;
    rep(i, 1, 7) cin >> a[i], flag |= !!a[i];
    if (!flag) break;
    std::cout << "Collection #" << __ << ":\n";

    b.clear();
    rep(i, 1, 6) cast(i, 6);
    rep(i, 1, 7) split(a[i], i);
    sort(b.begin(), b.end());

    int m = accumulate(b.begin(), b.end(), 0), t = 0;
    if (m & 1) { cout << "Can't be divided.\n\n"; continue; }
    m /= 2;

    f.reset(), f.set(0, true);
    for (auto bi : b) {
      per(i, 0, min(m - bi, t) + 1) if (f[i]) f.set(i + bi, true);
      t += bi;
    }
    cout << (f[m] ? "Can be divided.\n\n" : "Can't be divided.\n\n");
  }
  return 0;
}
