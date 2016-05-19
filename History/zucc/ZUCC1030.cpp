/*
 *	Name : ZUCC1030.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月18日 下午7:21:19
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <iostream>
//@ Using Namespace
using namespace std;
//@ Program Begin

//@ Main Function
int main() {
  int r, a, v, s;
  double l, w, x, y;
  while (cin >> l >> w && l && w) {
    cin >> x >> y >> r >> a >> v >> s;
    double vx = v * cos(a / 180. * M_PI);
    double vy = v * sin(a / 180. * M_PI);
    l -= 2 * r;
    w -= 2 * r;
    x = x - r + vx * s;
    y = y - r + vy * s;
    x = fmod(x, 2 * l);
    y = fmod(y, 2 * w);
    if (x < 0) x += 2 * l;
    if (y < 0) y += 2 * w;
    if (x > l) x = 2 * l - x;
    if (y > w) y = 2 * w - y;
    x += r;
    y += r;
    printf("%.2f %.2f\n", x, y);
  }
  return 0;
}
