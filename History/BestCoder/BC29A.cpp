/*
 *	Name : BC29A.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月12日 下午3:37:09
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

int main() {
	double a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		b *= log(a), d *= log(c);
		if (abs(b-d) < EPS)
			puts("=");
		else
			puts(b < d ? "<" : ">");
	}
	return 0;
}
