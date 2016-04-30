/*
 *	Name : BC38C.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月18日 下午7:41:19
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <stdio.h>
#include <string.h>
#include <algorithm>
//@ Using Namespace
using namespace std;
//@ Program Begin

int l1, r1, l2, r2;

int check(int m) {
	if (m < l1 || m > r1) return 0;
	int ret = min(m ^ l2, m ^ r2);
	for (int i = l2; i - 1 <= r2; i += (i&-i)) {
		if (i > l2) ret = min(ret, m ^ (i - 1));
		if (l1 <= (m ^ i) && (m ^ i) <= r2) ret = min(ret, i);
	}
	return ret;
}

//@ Main Function
int main() {
	int _, T = 1; scanf("%d", &_);
	while (_--) {
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		r1 = min(r1, l2 - 1);

		int ans = 0;
		for (int i = l1; i <= r1; i += (i&-i)) {
			ans = max(ans, check(i));
		}
		ans = max(ans, check(r1));

		printf("Case #%d: %d\n", T++, ans);
	}
	return 0;
}
