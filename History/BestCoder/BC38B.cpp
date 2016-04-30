/*
 *	Name : BC38B.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月18日 下午6:59:02
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

#define maxN 100010
int cnt[maxN];

int solve(int m) {
	for (int i = m; i > 1; i--) {
		int sum = 0;
		for (int k = i; k <= m; k += i) {
			sum += cnt[k];
			if (sum > 1) return i;
		}
	}
	return 1;
}

//@ Main Function
int main() {
	int _, T = 1;
	scanf("%d", &_);
	while (_--) {
		int n, m = 0;
		scanf("%d", &n);
		memset(cnt, 0x00, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			int in;
			scanf("%d", &in);
			cnt[in]++;
			m = max(m, in);
		}
		printf("Case #%d: %d\n", T++, solve(m));
	}
	return 0;
}
