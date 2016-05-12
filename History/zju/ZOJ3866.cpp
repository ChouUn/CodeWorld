/*
 *	Name : zju3866.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��15�� ����9:59:35
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

const double pi = M_PI;

//@ Main Function
int main() {
	int _; cin >> _;
	while (_--) {
		double r, h, d; cin >> r >> h >> d;
		double s = pi * ((.5*pi*r*d*d + (2./3*pow(d,3.) + r*r*d)) * 2 + pow(r+d,2)*h);
		double v = 2 * pi * ((2*d*d+pi*d*r) + r*r + (r+d)*h);
		printf("%.8f %.8f\n", s, v);
	}
	return 0;
}
