/*
 *	Name : zju3448.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��23�� ����5:01:03
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

static double EPS = 1e-8;
inline int
cmp(const double& a, const double& b)
{ return fabs(a - b) <= EPS ? 0 : (a < b ? -1 : 1); }

template <typename _Tp>
inline _Tp
sqr(const _Tp& x)
{ return x * x; }

double a, b, c, d, e, f;

bool iscircle() {
  if (cmp(a, c) == 0) return true;
  return false;
}

bool isparabola() {
  if (cmp(a * c, 0) == 0) return true;
  return false;
}

bool isellipse() {
  if (cmp(a * c, 0) > 0) return true;
  return false;
}

//@ Main Function
int main() {
  int _; scanf("%d", &_);
  while (_--) {
    scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);
    if (isparabola()) {
      printf("parabola\n");
    }
    else if (iscircle())
    {
      printf("circle\n");
    }
    else if (isellipse()) {
      printf("ellipse\n");
    }
    else
      printf("hyperbola\n");
  }
  return 0;
}
