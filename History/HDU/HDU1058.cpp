/*
 *	Name : HDU1058.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月17日 上午10:07:08
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <stdio.h>
#include <set>
//@ Program Begin

#define maxN 5842
#define maxM 2000000000
const int p[] = {2,3,5,7};
int ans[maxN];

//@ Main Function
int main() {
	std::set<int> S; S.insert(1);
	for (int i = 0; i < maxN; i++) {
		ans[i] = *S.begin(); S.erase(S.begin());
		for (int k = 0; k < 4; k++) {
			long long tmp = (long long)ans[i] * p[k];
			if (tmp <= maxM) S.insert(tmp);
		}
	}

	int x;
	while (scanf("%d", &x) != EOF && x) {
		printf("The %d", x);
		printf((x % 10 == 1 && x / 10 % 10 != 1) ? "st" :
			  ((x % 10 == 2 && x / 10 % 10 != 1) ? "nd" :
			  ((x % 10 == 3 && x / 10 % 10 != 1) ? "rd" : "th")));
		printf(" humble number is %d.\n", ans[x - 1]);
	}
	return 0;
}
