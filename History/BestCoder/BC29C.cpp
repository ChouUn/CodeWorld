/*
 *	Name : BC29C.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月13日 下午12:58:07
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include <standard.h>

#define maxN 1000010

int num[maxN];
int pre[maxN];
int sum[maxN];

int main() {
	srand(time(0));
	pre[0] = 0;
	FOR(i, 1, maxN - 1) {
		num[i] = (rand() << 16) + (rand() << 0);
		pre[i] = pre[i - 1]^ num[i];
	}

	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		sum[0] = 0ull;
		FOR (i, 1, n) {
			int data = getint();
			sum[i] = sum[i - 1] ^ num[data];
		}

		while (m--) {
			int x = getint();
			int y = getint();
			{
				int src = sum[y] ^ sum[x - 1];
				int tgt = pre[y - x + 1] ^ pre[0];
				if (src != tgt) { puts("NO"); continue; }
			}
			puts("YES");
		}
	}
	return 0;
}
