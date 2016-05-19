/*
 *	Name : HDU1425.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月31日 下午7:02:06
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <csl_std.h>

//@ Using Namespace
using namespace csl;

int a[1000010];

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		sort(a, a + n);
		for (int i = n - 1; m--; i--) {
			printf("%d", a[i]);
			putchar(m ? ' ' : '\n');
		}
	}
	return 0;
}
