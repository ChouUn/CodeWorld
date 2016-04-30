/*
 *	Name : POJ3407.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月19日 上午3:40:07
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

double trans_x(int a, int b, char c) {
	return (c == 'N' ? 1. : -1.) * (a + b / 60.) / 360. * 2 * PI;
}

double trans_y(int a, int b, char c) {
	return (c == 'E' ? 1. : -1.) * (a + b / 60.) / 360. * 2 * PI;
}

int main() {
	int a1, b1, a2, b2; char c1, c2;
	while (cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2) {
		double x1 = trans_x(a1, b1, c1);
		double y1 = trans_y(a2, b2, c2);
		cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
		double x2 = trans_x(a1, b1, c1);
		double y2 = trans_y(a2, b2, c2);

		printf("%.3f\n", 6370 * acos(cos(x1) * cos(x2) * cos(y2 - y1) + sin(x1) * sin(x2)));
	}
	return 0;
}
