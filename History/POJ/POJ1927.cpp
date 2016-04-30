/*
 *	Name : POJ1927.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月19日 上午2:41:06
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int main() {
	int T = 0;
	double a, b, c, d;
	while (cin >> a >> b >> c >> d && (a || b || c || d)) {
		double cosa = (sqr(b) + sqr(c) - sqr(a)) / (2 * b * c);
		double s = 0.5 * b * c * sqrt(1 - sqr(cosa));
		double l = a + b + c;
		double r = s * 2 / l;

		double ans;
		if (d > l)
			ans = s;
		else if (2 * PI * r > d)
			ans = sqr(d) * 0.25 / PI;
		else {
			double p = (l - d) / (l - 2 * PI * r);
			ans = s * (1 - sqr(p)) + PI * sqr(r * p);
		}
		printf("Case %d: %.2f\n", ++T, ans);
	}
	return 0;
}
