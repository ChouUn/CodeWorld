//@ Including Header
#include <csl_std.h>
#include <sparse.h>

/*
 *  Name : hdu5443.cpp
 *  Date : 2015年9月13日 上午9:01:38
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 1010
int a[maxn];

//@ Main Function
int main() {
  int _;
  //for (; scanf("%d", &_) != EOF; ) {
  for (scanf("%d", &_); _; _--) {
    //printf("Case #%d:\n", ++__);
	int n; scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a+i);

	csl::sparse_table<int, csl::greater<int> > s;
	s.build(a, n);

	int m; scanf("%d", &m);
	rep(i, 0, m) {
	  int x, y; scanf("%d%d", &x, &y);
	  int z = s.query(x - 1, y - 1);
	  printf("%d\n", z);
	}
  }
  return 0;
}
