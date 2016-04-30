/*
 *	Name : BD15R2A-B.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年6月1日 下午7:21:00
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#define USING_CONTAINER
#include <csl_std.h>
#include <sparse.h>
//@ Using Namespace
//using namespace std;
//@ The magic ends here.

#define maxN 10010
#define maxM maxN*15
int n, m, a[maxN], b[maxN];
int v1[maxM], v2[maxM], v3[maxM];

std::map<int,int> p;
std::map<int,int>::iterator it;

//@ Main Function
int main() {
  int _ = 1; //scanf("%d", &_);
  for (int T = 1; T <= _; T++) {
    printf("Case #%d:\n", T);
    scanf("%d%d", &n, &m);
    p.clear();
    for (int i = 0; i < n; i++) {
      int x; scanf("%d", &x);
      a[i] = x; it = p.find(x);
      if (it == p.end())
        b[i] = -1, p[x] = i;
      else
        b[i] = it->second, it->second = i;
    }
    csl::SparseTable<int> s1, s2, s3;
    s1.build(v1, a, maxN, std::min);
    s2.build(v2, a, maxN, std::max);
    s3.build(v3, b, maxN, std::max);
    while (m--) {
      int k; scanf("%d", &k);
      int ans = 0;
      for (int i = 0; i + k <= n; i++) {
        int z = s3.query(i, i + k - 1);
        if (z >= i) continue;
        int x = s1.query(i, i + k - 1);
        int y = s2.query(i, i + k - 1);
        if (y - x + 1 == k) ans++;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
