//@ Including Header
#include <csl_std.h>
#include <csl_math.h>

/**
 *  Name : jsk 2016 - R2A.cpp
 *  Date : 2016年6月5日 下午1:02:46
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

double solve(double a, double b, double C) {
  //c²=a²+b²-2ab cosC.
  return sqrt(a * a + b * b - 2 * a * b * cos(C / 180. * M_PI));
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  double l1, l2, th; cin >> l1 >> l2 >> th;
  double l3 = solve(l1 / 2., l2 / 2., th);
  double r = (l1 / 2. + l2 / 2. + l3) / 2;
  double S = M_PI * r * r;
  cout << fixed << setprecision(9) << S << endl;

  return 0;
}
