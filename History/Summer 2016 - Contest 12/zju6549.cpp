//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>
#include <geometry.h>

/**
 *  Name : zju6549.cpp
 *  Date : 2016年7月19日 上午10:45:37
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 500010;

typedef complex<double> Point;
typedef vector<Point> Polygon;
typedef pair<Point,Point> Line;
#define p1 first
#define p2 second

double cross(Point a, Point b)
{
    return a.real() * b.imag() - a.imag() * b.real();
}

double cross(Point o, Point a, Point b)
{
    return (a.real() - o.real()) * (b.imag() - o.imag())
        - (a.imag() - o.imag()) * (b.real() - o.real());
}

inline double cross(Line l, Point p)
{
    return cross(l.p1, l.p2, p);
}

inline bool parallel(Line& l1, Line& l2)
{
    return cross(l1.p2 - l1.p1, l2.p2 - l2.p1) == 0;
}

Point intersection(Line& l1, Line& l2)
{
    Point& a1 = l1.p1, &a2 = l1.p2;
    Point& b1 = l2.p1, &b2 = l2.p2;
    Point a = a2 - a1, b = b2 - b1, s = b1 - a1;
    return a1 + a * cross(b, s) / cross(b, a);
}

bool cmp(const Line& l1, const Line& l2)
{
    return arg(l1.p2 - l1.p1) < arg(l2.p2 - l2.p1);
}

Polygon halfplane_intersection(vector<Line>& hp)
{
    // 所有半平面按照極座標角度排序
    sort(hp.begin(), hp.end(), cmp);

    // deque
    int L = 0, R = 0;
    vector<Line> l(N);  // 凸多邊形的邊
    vector<Point> p(N); // 凸多邊形的頂點
    l[R] = hp[0];

    for (int i=1; i<(int)hp.size(); i++)
    {
        // deque右端持續彈出（若不允許退化，則添上等於）
        while (L < R && cross(hp[i], p[R-1]) < 0) R--;
        // deque左端持續彈出（若不允許退化，則添上等於）
        while (L < R && cross(hp[i], p[L])   < 0) L++;

        // 如果已經大於等於180度，
        // deque為空，可以提早結束演算法。
        // 不好實作，故省略。

        // 加入當前半平面
        l[++R] = hp[i];

        // 兩個平行的半平面，刪除靠外側的半平面。
        // 預先加入四個半平面做為邊界，
        // 此處就不會接連出現斜率相等、方向相反的半平面。
        if (parallel(l[R-1], hp[i]) &&
            cross(l[--R], hp[i].p1) < 0) l[R] = hp[i];

        // 計算頂點
        if (L < R) p[R-1] = intersection(l[R], l[R-1]);
    }
    // deque右端持續彈出（避免L型絲帶）（若不允許退化，則添上等於）
    while (L < R && cross(l[L], p[R-1]) < 0) R--;
    // 空集合
    if (R-L <= 1) return Polygon();
    // 計算頂點
    if (L < R) p[R] = intersection(l[L], l[R]);

    // 重新儲存凸包頂點
    Polygon ch;
    for (int i=L; i<=R; i++) ch.push_back(p[i]);
    // 刪除重複的點。可能有多個半平面，交於同一點。
    ch.resize(unique(ch.begin(), ch.end()) - ch.begin());
    // 刪除頭尾重複的點。
    if (ch.size() > 1 && ch.front() == ch.back())
        ch.pop_back();
    return ch;  // 包含退化的情況
}

using csl::point;
using csl::line;
using csl::inter_ls;
double solve(Point l, Point r) {
  double x1 = l.real(), y1 = l.imag();
  double x2 = r.real(), y2 = r.imag();
  double p = (y1 - y2) / (x1 - x2);
  double a = p;
  double b = -1;
  double c = y2 - p * x2;
  double q = (c * c) / (4 * a * b);
//  cout << a << " " << b << " " << c << endl;
  line i(point(x1, y1), point(x2, y2));
  line j(point(0, 0), point(b, a));
  if (inter_ls(j, i)) return q;
  return max(x1 * y1, x2 * y2);
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for (std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    vector<Line> lines;
    rep(i, 0, n) {
      int x, y; cin >> x >> y;
      lines.push_back(make_pair(Point(x, 0), Point(0, y)));
    }
    lines.push_back(make_pair(Point(0, 1e9), Point(0, 0)));
    lines.push_back(make_pair(Point(1e9, 1e9), Point(0, 1e9)));
    lines.push_back(make_pair(Point(1e9, 0), Point(1e9, 1e9)));
    lines.push_back(make_pair(Point(0, 0), Point(1e9, 0)));
//    lines.push_back(make_pair(Point(0, 3), Point(6, 0)));
    Polygon polygon = halfplane_intersection(lines);
    polygon.erase(polygon.begin());
//    rep(i, 0, (int)polygon.size())
//      cout << polygon[i].real() << " " << polygon[i].imag() << endl;
    double ans = 0;
    rep(i, 0, (int)polygon.size() - 1) {
      ans = max(ans, solve(polygon[i], polygon[i + 1]));
    }
    cout << fixed << setprecision(9) << ans << endl;
//    cout << pn << endl;
//    rep(i, 0, n) cout << Q[i].s.x << " " << Q[i].s.y << endl;
//    rep(i, 0, pn) cout << P[i].x << " " << P[i].y << endl;
  }
  return 0;
}
