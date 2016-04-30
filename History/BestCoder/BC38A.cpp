/*
 *	Name : BC38A2.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月19日 上午10:30:40
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>

namespace geometry
{
	struct point
	{
	  double x, y, z;

	  point() : x(), y(), z() { }
	  explicit point(double a, double b, double c) : x(a), y(b), z(c) { }

	  point operator + (const point& b)
	  { return point(x + b.x, y + b.y, z + b.z); }
	  point operator - (const point& b)
	  { return point(x - b.x, y - b.y, z - b.z); }
	  bool operator != (const point& b)
	  { return csl::cmp(x, b.x) || csl::cmp(y, b.y) || csl::cmp(z, b.z); }
	  bool operator == (const point& b)
	  { return !((*this) != b); }

	  inline double norm()
	  { return sqrt(csl::sqr(x) + csl::sqr(y) + csl::sqr(z)); }
	};

  inline double
    dot(const point& u, const point& v)
    { return u.x * v.x + u.y * v.y + u.z * v.z; }

  inline point
    cross(const point& u, const point& v)
    { return point(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x); }

} // namespace geometry

//@ Using Namespace
using namespace std;
using namespace geometry;
//@ Program Begin

point p[4]; int f[4];

bool check() {
	point a = p[f[0]] - p[f[1]], c = p[f[2]] - p[f[3]];
	point b = p[f[0]] - p[f[2]], d = p[f[1]] - p[f[3]];
	if (a != c || b != d) return false;
	if (csl::cmp(dot(a, b), 0)) return false;
	if (csl::cmp(a.norm(), b.norm())) return false;
	return true;
}

//@ Main Function
int main() {
	int _, T = 1;
	scanf("%d", &_);
	while (_--) {
		for (int i = 0; i < 4; i++) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
		for (int i = 0; i < 4; i++) f[i] = i;
		bool ans = false;
		do {
			if ((ans = check())) break;
		} while (next_permutation(f, f + 4));
		printf("Case #%d: %s\n", T++, ans ? "Yes" : "No");
	}
	return 0;
}
