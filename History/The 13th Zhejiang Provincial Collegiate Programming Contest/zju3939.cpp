//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju3939.cpp
 *  Date : 2016年4月24日 下午3:27:08
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

// 2001 1 1 Mon
const int day[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

//@ Main Function
int main() {
  int m = 0;
  set<int> ans;
  rep(i, 1, 401) {
    int leap = (i % 400 == 0) || (i % 100 != 0 && i % 4 == 0);
    const int* d = day[leap];
    rep(j, 1, 13) {
      if ((m + 1) % 7 == 1) ans.insert(i * 10000 + j * 100 + 1);
      if ((m + 11) % 7 == 1) ans.insert(i * 10000 + j * 100 + 11);
      if ((m + 21) % 7 == 1) ans.insert(i * 10000 + j * 100 + 21);
      m = (m + d[j]) % 7;
    }
  }

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int a, b, c, s; cin >> a >> b >> c >> s;

    int p = ((a - 1) % 400 + 1) * 10000 + b * 100 + c;
    auto it = ans.find(p);

    int t = (s - 1) / ans.size();
    s = (s - 1) % ans.size();
    while (s) {
      --s, ++it;
      if (it == ans.end()) ++t, it = ans.begin();
    }

    int q = *it;
    int x = q / 10000, y = q % 10000 / 100, z = q % 100;
    a = a + (x - ((a - 1) % 400 + 1)) + 400 * t, b = y, c = z;
    cout << a << " " << b << " " << c << endl;
  }
  return 0;
}
