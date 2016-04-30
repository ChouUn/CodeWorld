/*
 *	Name : HDU1115.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月19日 上午2:10:45
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

double cross(double x1, double y1, double x2, double y2) {
	return (x1 * y2 - x2 * y1) / 2.;
}

int main() {
	int T_max; cin >> T_max;
	FOR (T, 1, T_max) {
		int n; cin >> n;
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		double s_area = 0., s_x = 0., s_y = 0.;
		REP (i, n - 2) {
			int x3, y3; cin >> x3 >> y3;
			double area = cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
			s_area	+= area;
			s_x		+= (x1 + x2 + x3) * area;
			s_y		+= (y1 + y2 + y3) * area;
			x2 = x3, y2 = y3;
		}
		s_x /= s_area * 3., s_y /= s_area * 3.;
		printf("%.2lf %.2lf\n", s_x, s_y);
	}
	return 0;
}
